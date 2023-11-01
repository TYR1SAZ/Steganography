
#ifndef HAAR_H
#define HAAR_H

#include <vector>

// Функция для применения вейвлет-преобразования Хаара к каждой строке массива
std::vector<float> Haar1D(std::vector<float> input);

// Функция для применения обратного вейвлет-преобразования Хаара к каждой строке массива
std::vector<float> RHaar1D(std::vector<float> input);

// Функция для применения вейвлет-преобразования Хаара к двумерному массиву
void Haar2D(std::vector<std::vector<float>> &input, bool reverse);

#endif // HAAR_H
