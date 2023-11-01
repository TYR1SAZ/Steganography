#ifndef STEGOPICTURES_H
#define STEGOPICTURES_H

#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;

// Размерность матрицы встраиваемых данных
#define BLOCK_BIT 2

// Встраивание информации
void Input(std::vector<std::vector<float>>& vec, std::vector<std::vector<float>>& mess);

// Извлечение информации
std::vector<float> Output(std::vector<std::vector<float>>& vec);

std::vector<std::vector<float>> Stego(Mat& container, Mat& inMess, int rows, int cols, bool reverse);

void OutMessage(Mat& mess, std::vector<std::vector<float>>& vec);
#endif // STEGOPICTURES_H
