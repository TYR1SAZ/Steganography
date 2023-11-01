/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_mess;
    QLabel *name_container;
    QLabel *label_container;
    QLabel *name_out;
    QLabel *name_in;
    QLabel *name_mess;
    QLabel *label_con_in;
    QLabel *label_mess_out;
    QSlider *horizontalSlider;
    QProgressBar *progressBar;
    QGridLayout *gridLayout;
    QPushButton *Code;
    QPushButton *button_Mess;
    QPushButton *Decode;
    QPushButton *button_Container;
    QLabel *label;
    QPushButton *attack;
    QGridLayout *gridLayout_3;
    QCheckBox *Rotate;
    QCheckBox *Resize;
    QCheckBox *Jpeg;
    QCheckBox *Noise;
    QCheckBox *Cropping;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(656, 609);
        MainWindow->setMaximumSize(QSize(770, 609));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(-1, 0, -1, -1);
        label_mess = new QLabel(centralwidget);
        label_mess->setObjectName("label_mess");
        label_mess->setMinimumSize(QSize(200, 100));
        label_mess->setMaximumSize(QSize(200, 100));
        label_mess->setScaledContents(true);

        gridLayout_2->addWidget(label_mess, 1, 1, 1, 1);

        name_container = new QLabel(centralwidget);
        name_container->setObjectName("name_container");
        name_container->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        font.setBold(true);
        name_container->setFont(font);
        name_container->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(name_container, 0, 0, 1, 1);

        label_container = new QLabel(centralwidget);
        label_container->setObjectName("label_container");
        label_container->setMinimumSize(QSize(200, 100));
        label_container->setMaximumSize(QSize(200, 100));
        label_container->setScaledContents(true);

        gridLayout_2->addWidget(label_container, 1, 0, 1, 1);

        name_out = new QLabel(centralwidget);
        name_out->setObjectName("name_out");
        name_out->setMaximumSize(QSize(16777215, 20));
        name_out->setFont(font);
        name_out->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(name_out, 2, 1, 1, 1);

        name_in = new QLabel(centralwidget);
        name_in->setObjectName("name_in");
        name_in->setMaximumSize(QSize(16777215, 20));
        name_in->setFont(font);
        name_in->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(name_in, 2, 0, 1, 1);

        name_mess = new QLabel(centralwidget);
        name_mess->setObjectName("name_mess");
        name_mess->setMaximumSize(QSize(16777215, 20));
        name_mess->setFont(font);
        name_mess->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(name_mess, 0, 1, 1, 1);

        label_con_in = new QLabel(centralwidget);
        label_con_in->setObjectName("label_con_in");
        label_con_in->setMinimumSize(QSize(200, 100));
        label_con_in->setMaximumSize(QSize(200, 100));
        label_con_in->setScaledContents(true);

        gridLayout_2->addWidget(label_con_in, 3, 0, 1, 1);

        label_mess_out = new QLabel(centralwidget);
        label_mess_out->setObjectName("label_mess_out");
        label_mess_out->setMinimumSize(QSize(200, 100));
        label_mess_out->setMaximumSize(QSize(200, 100));
        label_mess_out->setScaledContents(true);

        gridLayout_2->addWidget(label_mess_out, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        Code = new QPushButton(centralwidget);
        Code->setObjectName("Code");
        Code->setMinimumSize(QSize(150, 20));
        Code->setMaximumSize(QSize(150, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto")});
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setUnderline(false);
        Code->setFont(font1);
        Code->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(Code, 2, 0, 1, 1);

        button_Mess = new QPushButton(centralwidget);
        button_Mess->setObjectName("button_Mess");
        button_Mess->setMinimumSize(QSize(150, 20));
        button_Mess->setMaximumSize(QSize(150, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setUnderline(true);
        button_Mess->setFont(font2);
        button_Mess->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(button_Mess, 1, 1, 1, 1);

        Decode = new QPushButton(centralwidget);
        Decode->setObjectName("Decode");
        Decode->setMinimumSize(QSize(150, 20));
        Decode->setMaximumSize(QSize(150, 20));
        Decode->setFont(font1);
        Decode->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(Decode, 2, 1, 1, 1);

        button_Container = new QPushButton(centralwidget);
        button_Container->setObjectName("button_Container");
        button_Container->setMinimumSize(QSize(150, 20));
        button_Container->setMaximumSize(QSize(150, 20));
        button_Container->setFont(font2);
        button_Container->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(button_Container, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setMaximumSize(QSize(150, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto")});
        font3.setPointSize(20);
        font3.setBold(true);
        label->setFont(font3);

        gridLayout->addWidget(label, 5, 0, 1, 1);

        attack = new QPushButton(centralwidget);
        attack->setObjectName("attack");
        attack->setMinimumSize(QSize(150, 20));
        attack->setMaximumSize(QSize(150, 20));
        attack->setFont(font2);
        attack->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(attack, 3, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, 0, -1, -1);
        Rotate = new QCheckBox(centralwidget);
        Rotate->setObjectName("Rotate");
        Rotate->setEnabled(true);

        gridLayout_3->addWidget(Rotate, 2, 0, 1, 1);

        Resize = new QCheckBox(centralwidget);
        Resize->setObjectName("Resize");
        Resize->setEnabled(true);

        gridLayout_3->addWidget(Resize, 2, 1, 1, 1);

        Jpeg = new QCheckBox(centralwidget);
        Jpeg->setObjectName("Jpeg");
        Jpeg->setEnabled(true);

        gridLayout_3->addWidget(Jpeg, 0, 0, 1, 1);

        Noise = new QCheckBox(centralwidget);
        Noise->setObjectName("Noise");
        Noise->setEnabled(true);
        Noise->setAutoFillBackground(false);

        gridLayout_3->addWidget(Noise, 0, 1, 1, 1);

        Cropping = new QCheckBox(centralwidget);
        Cropping->setObjectName("Cropping");
        Cropping->setEnabled(true);

        gridLayout_3->addWidget(Cropping, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_3, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 656, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_mess->setText(QString());
        name_container->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\320\265\320\271\320\275\320\265\321\200", nullptr));
        label_container->setText(QString());
        name_out->setText(QCoreApplication::translate("MainWindow", "\320\246\320\222\320\227 \320\277\320\276\321\201\320\273\320\265 \320\262\321\201\320\272\321\200\321\213\321\202\320\270\321\217", nullptr));
        name_in->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\321\200\320\276\320\265\320\275\320\276 \320\246\320\222\320\227", nullptr));
        name_mess->setText(QCoreApplication::translate("MainWindow", "\320\246\320\222\320\227", nullptr));
        label_con_in->setText(QString());
        label_mess_out->setText(QString());
        Code->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        button_Mess->setText(QCoreApplication::translate("MainWindow", "\320\246\320\222\320\227", nullptr));
        Decode->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        button_Container->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\320\265\320\271\320\275\320\265\321\200", nullptr));
        label->setText(QString());
        attack->setText(QCoreApplication::translate("MainWindow", "\320\220\321\202\320\260\320\272\320\276\320\262\320\260\321\202\321\214", nullptr));
        Rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        Resize->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        Jpeg->setText(QCoreApplication::translate("MainWindow", "Jpeg", nullptr));
        Noise->setText(QCoreApplication::translate("MainWindow", "Noise", nullptr));
        Cropping->setText(QCoreApplication::translate("MainWindow", "Cropping", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
