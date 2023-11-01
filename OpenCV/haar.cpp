#include "haar.h"

// Функция для применения вейвлет-преобразования Хаара к каждой строке массива
std::vector<float> Haar1D(std::vector<float> input)
{
    int N = input.size();
    std::vector<float> output(N);
    for (int i = 0; i < N; i += 2)
    {
        float sum = input[i] + input[i + 1];
        float diff = input[i] - input[i + 1];
        output[i >> 1] = sum / 2;
        output[(i + N) >> 1] = diff / 2;
    }

    return output;
}

// Функция для применения обратного вейвлет-преобразования Хаара к каждой строке массива
std::vector<float> RHaar1D(std::vector<float> input)
{
    int N = input.size();
    std::vector<float> output(N);
    for (int i = 0; i < N; i += 2)
    {
        float sum = input[i >> 1] * 2;
        float diff = input[(i + N) >> 1] * 2;
        output[i] = (sum + diff) / 2;
        output[i + 1] = (sum - diff) / 2;
    }

    return output;
}

// Функция для применения вейвлет-преобразования Хаара к двумерному массиву
void Haar2D(std::vector<std::vector<float>> &input, bool reverse)
{
    int rows = input.size();
    int cols = input[0].size();
    // Применяем вейвлет-преобразование Хаара к каждой строке
    for (int i = 0; i < rows; i++)
    {
        std::vector<float> row = input[i];
        std::vector<float> transformedRow = reverse ? RHaar1D(row) : Haar1D(row);
        for (int j = 0; j < cols; j++)
        {
            input[i][j] = transformedRow[j];
        }
    }

    // Применяем вейвлет-преобразование Хаара к каждому столбцу
    for (int j = 0; j < cols; j++)
    {
        std::vector<float> col(rows);
        for (int i = 0; i < rows; i++)
        {
            col[i] = input[i][j];
        }
        std::vector<float> transformedCol = reverse ? RHaar1D(col) : Haar1D(col);
        for (int i = 0; i < rows; i++)
        {
            input[i][j] = transformedCol[i];
        }
    }
}

