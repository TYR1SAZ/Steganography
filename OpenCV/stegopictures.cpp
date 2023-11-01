#include "stegopictures.h"
#include "haar.h"

int WEIGHT = 2;

void code(int a[], int bit, std::vector<std::vector<float>>& vec, int i, int j)
{
    int mid = 0;
    // 17 18
    if(a[0] > a[1])
    {
        if(!bit)
        {
            return;
        }
        else
        {
            mid = (a[0] - a[1])/2;
            a[0] -= (mid + WEIGHT);
            a[1] += (mid + WEIGHT);
        }
    }
    else if(a[0] < a[1])
    {
        if(bit)
        {
            return;
        }
        else
        {
            mid = (a[1] - a[0])/2;
            a[1] -= (mid + WEIGHT);
            a[0] += (mid + WEIGHT);
        }
    }
    if(a[0] == a[1])
    {
        if(bit)
        {
            a[1] += WEIGHT;
            a[0] -= WEIGHT;
        }
        else
        {
            a[0] += WEIGHT;
            a[1] -= WEIGHT;
        }
    }
    vec[i + 1][j] = a[0];
    vec[i][j + 1] = a[1];
}

// Встраивание информации
void Input(std::vector<std::vector<float>>& vec, std::vector<std::vector<float>>& mess)
{
    int a[2];
    for (int i = 0; i < 4; i+=2)
    {
        for (int j = 0; j < 4; j+=2)
        {
            bool bit = (bool)(mess[i/2][j/2] > 127);

            a[0] = abs(vec[i + 1][j]);
            a[1] = abs(vec[i][j + 1]);
            if(abs(a[0] - a[1]) < 20)
            {
                code(a,bit,vec,i,j);
            }
            else
            {
                code(a,bit,vec,i,j+1);
            }
        }
    }
}

void Decode(int a[], std::vector<float> &mess, std::vector<std::vector<float>>& vec, int i, int j)
{
    int mid = 0;
    if (a[0] > a[1])
    {
        mess.push_back(0);
        mid = ((a[1] - a[0])) / 2;
        vec[i][j] += (mid + WEIGHT);
        vec[i][j + 1] -= (mid - WEIGHT);
    }
    else
    {
        mess.push_back(255);
        mid = ((a[1] - a[0])) / 2;
        vec[i][j] -= (mid + WEIGHT);
        vec[i][j + 1] += (mid - WEIGHT);
    }
}

// Извлечение информации
std::vector<float> Output(std::vector<std::vector<float>>& vec)
{

    int a[2];
    std::vector<float> mess;
    for (int i = 0; i < 4; i+=2)
    {
        for (int j = 0; j < 4; j+=2)
        {
            a[0] = abs(vec[i + 1][j]);
            a[1] = abs(vec[i][j + 1]);
            if(abs(a[0] - a[1]) < 20)
            {
                Decode(a, mess, vec, i, j);
            }
            else
            {
                Decode(a, mess, vec, i, j + 1);
            }
        }
    }
    return mess;
}

void SubMatrix(Mat& input, std::vector<std::vector<float>>& output, int num1, int num2, int chanel)
{
    int rows = output.size();
    int cols = output[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            output[i][j] = input.at<Vec3b>(num1 * rows + i, num2 * cols + j)[chanel];
        }
    }
}

void SubMatrix(Mat& input, std::vector<std::vector<float>>& output, int num1, int num2)
{
    int rows = output.size();
    int cols = output[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            output[i][j] = input.at<uchar>(num1 * rows + i, num2 * cols + j);
        }
    }
}

void SubMatrix(std::vector<std::vector<float>>& input, Mat& output, int num1, int num2, int chanel)
{
    int rows = input.size();
    int cols = input[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            output.at<Vec3b>(num1 * rows + i, num2 * cols + j)[chanel] = input[i][j];
        }
    }
}

void SubMatrix(std::vector<float>& input, Mat& output, int cols, int i, int j)
{
    for (int n = 0; n < BLOCK_BIT; n++)
    {
        for (int m = 0; m < BLOCK_BIT; m++)
        {
            output.at<uchar>(i + n, j + m) = input[i * cols + BLOCK_BIT * j + n * BLOCK_BIT + m];
        }
    }
}

std::vector<std::vector<float>> Stego(Mat& container, Mat& inMess, int rows, int cols, bool reverse)
{
    // Перезод из цветового пространства BGR в YCbCr
    cv::cvtColor(container, container, COLOR_BGR2YCrCb);
    // Подмассив для блоков контейнера
    std::vector<std::vector<float>> B(8, std::vector<float>(8));
    std::vector<std::vector<float>> G(8, std::vector<float>(8));
    std::vector<std::vector<float>> R(8, std::vector<float>(8));
    // Подмассив для блоков ЦВЗ
    std::vector<std::vector<float>> byteMess(BLOCK_BIT, std::vector<float>(BLOCK_BIT));
    std::vector<std::vector<float>> buff;
    // Разделение картинки на блоки и встраивание 1 бита ЦВЗ в блок 8x8 контейнера

    for (int i = 0; i < rows / BLOCK_BIT; i++)
    {
        for (int j = 0; j < cols / BLOCK_BIT; j++)
        {
            SubMatrix(container, B, i, j, 2);
            SubMatrix(container, G, i, j, 1);
            SubMatrix(container, R, i, j, 0);
            Haar2D(B, 0);
            Haar2D(G, 0);
            Haar2D(R, 0);
            if (!reverse)
            {
                SubMatrix(inMess, byteMess, i, j);
                Input(B, byteMess);
            }
            else
            {
                buff.push_back(Output(B));
            }
            Haar2D(B, 1);
            Haar2D(G, 1);
            Haar2D(R, 1);
            SubMatrix(B, container, i, j, 2);
            SubMatrix(G, container, i, j, 1);
            SubMatrix(R, container, i, j, 0);
        }
    }

    // Перезод из цветового пространства YCbCr в BGR
    cv::cvtColor(container, container, COLOR_YCrCb2BGR);
    return buff;
}

void OutMessage(Mat& mess, std::vector<std::vector<float>>& vec)
{
    // Создаем буффер для удобства изымания битов
   std::vector<float> buffer;

    // Заносим биты в буфер
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec[0].size(); j++)
        {
            buffer.push_back(vec[i][j]);
        }
    }

    // Извлекаем биты из буфера в контейнер для ЦВЗ
    for (int i = 0; i < mess.rows; i += BLOCK_BIT)
    {
        for (int j = 0; j < mess.cols; j += BLOCK_BIT)
        {
            SubMatrix(buffer, mess, mess.cols, i, j);
        }
    }
}
