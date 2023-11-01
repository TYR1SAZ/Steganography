#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_Container_clicked();

    void on_button_Mess_clicked();

    void on_Code_clicked();

    void on_Decode_clicked();

    void on_attack_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
