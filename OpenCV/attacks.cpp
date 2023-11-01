#include "attacks.h"

// Атака на основе сжатия
void JpegAttack(Mat& container)
{
    // Сохранение в файл
    imwrite("image/CarCode.jp2", container);
    // Достаём из файла
    container = imread("image/CarCode.jp2");
}

// Атака на основе изменения размера картинки
void ResizeAttack(Mat& container)
{
    int rows = container.rows;
    int cols = container.cols;
    Size2i size(cols / 2, rows / 2);
    resize(container, container, size);
    imwrite("image/SmallSize.bmp", container);
    resize(container, container, size * 2);
    imwrite("image/BigSize.bmp", container);
}

// Атака на основе обрезки картинки
void CroppingAttack(Mat& container)
{
    Mat ROI(container, Rect(0, 0, 500, 500));
    ROI.copyTo(container);
}

// Атака на основе известного контейнера
void ContainerAttack(Mat& container)
{
    rotate(container, container, ROTATE_180);
}

// Атака шумом
void addGaussianNoise(Mat& m, int mu, int sigma)
{
    // Генерация гауссовского генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    std::normal_distribution<> d(mu, sigma);

    auto rows = m.rows; // количество строк
    auto cols = m.cols * m.channels(); // количество столбцов

    for (int i = 0; i < rows; i++)
    {
        auto p = m.ptr <uchar>(i); // Получить первый указатель строки
        for (int j = 0; j < cols; j++)
        {
            auto tmp = p[j] + d(gen);
            tmp = tmp > 255 ? 255 : tmp;
            tmp = tmp < 0 ? 0 : tmp;
            p[j] = tmp;
        }
    }
}
