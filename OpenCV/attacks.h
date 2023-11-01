#ifndef ATTACKS_H
#define ATTACKS_H

#include <opencv2/opencv.hpp>
#include <random>

using namespace cv;

// Атака на основе сжатия
void JpegAttack(Mat& container);

// Атака на основе изменения размера картинки
void ResizeAttack(Mat& container);

// Атака на основе обрезки картинки
void CroppingAttack(Mat& container);

// Атака на основе известного контейнера
void ContainerAttack(Mat& container);

// Атака шумом
void addGaussianNoise(Mat& m, int mu, int sigma);

#endif // ATTACKS_H
