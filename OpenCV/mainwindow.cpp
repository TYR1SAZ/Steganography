#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stegopictures.h"
#include "attacks.h"

cv::Mat container;
cv::Mat inMess;

int rows;
int cols;

extern int WEIGHT;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_Container_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "Open File", "", "*.bmp | *.jpg | *.png");
    if(filename.isEmpty())
    {
        return;
    }
    QPixmap img(filename);
    container = imread(filename.toStdString());
    rows = container.rows / 8 * BLOCK_BIT;
    cols = container.cols / 8 * BLOCK_BIT;
    ui->label_container->setPixmap(img);
    ui->label_mess->setPixmap(QPixmap());
    ui->label_con_in->setPixmap(QPixmap());
    ui->label_mess_out->setPixmap(QPixmap());
}


void MainWindow::on_button_Mess_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "Open File", "", "*.bmp | *.jpg | *.png");
    if(filename.isEmpty())
    {
        return;
    }
    inMess = imread(filename.toStdString(), IMREAD_GRAYSCALE);
    cv::resize(inMess, inMess, Size(cols, rows));
    cv::threshold(inMess, inMess, 128, 255, 0);
    imwrite("image/BW.bmp", inMess);
    QImage qimg("image/BW.bmp");
    QPixmap img(QPixmap::fromImage(qimg));
    ui->label_mess->setPixmap(img);
}

void MainWindow::on_Code_clicked()
{
    ui->label_mess_out->setPixmap(QPixmap());
    WEIGHT = ui->horizontalSlider->value();
    ui->progressBar->setValue(50);
    Stego(container, inMess, rows, cols, 0);
    imwrite("image/input.bmp", container);
    QImage qimg("image/input.bmp");
    QPixmap img(QPixmap::fromImage(qimg));
    ui->progressBar->setValue(100);
    ui->label_con_in->setPixmap(img);
}


void MainWindow::on_Decode_clicked()
{
    std::vector<std::vector<float>> buff;
    ui->progressBar->setValue(50);
    rows = container.rows / 8 * BLOCK_BIT;
    cols = container.cols / 8 * BLOCK_BIT;
    buff = Stego(container, inMess, rows, cols, 1);
    imwrite("image/emptyContainer.bmp", container);
    // Создание контейнера для ЦВЗ
    Mat outMess(rows, cols, CV_8U);
    OutMessage(outMess, buff);
    imwrite("image/outMess.bmp", outMess);
    QImage qimg("image/outMess.bmp");
    QPixmap img(QPixmap::fromImage(qimg));
    ui->label_mess_out->setPixmap(img);
    ui->progressBar->setValue(100);
}


void MainWindow::on_attack_clicked()
{
    ui->label_mess_out->setPixmap(QPixmap());
    container = imread("image/input.bmp");
    ui->progressBar->setValue(20);

    if(ui->Jpeg->checkState())
    {
        JpegAttack(container);
    }
    if(ui->Resize->checkState())
    {
        ResizeAttack(container);
    }
    ui->progressBar->setValue(40);
    if(ui->Cropping->checkState())
    {
        CroppingAttack(container);
    }
    if(ui->Rotate->checkState())
    {
        ContainerAttack(container);
    }
    ui->progressBar->setValue(60);
    if(ui->Noise->checkState())
    {
        addGaussianNoise(container, 5, 2);
    }

    imwrite("image/attack_img.bmp", container);
    QImage qimg("image/attack_img.bmp");
    QPixmap img(QPixmap::fromImage(qimg));
    ui->label_con_in->setPixmap(img);
    ui->progressBar->setValue(100);
}

