/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *valMinNum;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_6;
    QSlider *valMin;
    QSlider *satMin;
    QLabel *satMinNum;
    QSlider *satMinGray;
    QLabel *label_12;
    QLabel *valMinNumGray;
    QLabel *satMinNumGray;
    QSlider *valMinGray;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSlider *compressionSlider;
    QLabel *compressionNum;
    QSpacerItem *horizontalSpacer;
    QCheckBox *selectRoi;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sortButton;
    QToolButton *themeButton;
    QToolButton *languageButton;
    QToolButton *infoButton;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QPushButton *inputFolderButton;
    QPushButton *outputFolderButton;
    QLabel *label_2;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(427, 264);
        MainWindow->setMinimumSize(QSize(427, 0));
        MainWindow->setMaximumSize(QSize(427, 264));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName("gridLayout_4");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 2);

        valMinNum = new QLabel(centralwidget);
        valMinNum->setObjectName("valMinNum");

        gridLayout->addWidget(valMinNum, 2, 2, 2, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 1, 4, 2, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 3, 4, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 1, 0, 2, 1);

        valMin = new QSlider(centralwidget);
        valMin->setObjectName("valMin");
        valMin->setMinimumSize(QSize(120, 0));
        valMin->setMaximum(255);
        valMin->setValue(50);
        valMin->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(valMin, 3, 1, 1, 1);

        satMin = new QSlider(centralwidget);
        satMin->setObjectName("satMin");
        satMin->setMaximum(255);
        satMin->setValue(150);
        satMin->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(satMin, 1, 1, 2, 1);

        satMinNum = new QLabel(centralwidget);
        satMinNum->setObjectName("satMinNum");

        gridLayout->addWidget(satMinNum, 1, 2, 1, 1);

        satMinGray = new QSlider(centralwidget);
        satMinGray->setObjectName("satMinGray");
        satMinGray->setMinimumSize(QSize(120, 0));
        satMinGray->setMaximum(255);
        satMinGray->setValue(40);
        satMinGray->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(satMinGray, 1, 5, 2, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 0, 4, 1, 2);

        valMinNumGray = new QLabel(centralwidget);
        valMinNumGray->setObjectName("valMinNumGray");

        gridLayout->addWidget(valMinNumGray, 2, 6, 2, 1);

        satMinNumGray = new QLabel(centralwidget);
        satMinNumGray->setObjectName("satMinNumGray");
        satMinNumGray->setMinimumSize(QSize(18, 0));

        gridLayout->addWidget(satMinNumGray, 1, 6, 1, 1);

        valMinGray = new QSlider(centralwidget);
        valMinGray->setObjectName("valMinGray");
        valMinGray->setMaximum(255);
        valMinGray->setValue(40);
        valMinGray->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(valMinGray, 3, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        compressionSlider = new QSlider(centralwidget);
        compressionSlider->setObjectName("compressionSlider");
        compressionSlider->setMinimumSize(QSize(120, 0));
        compressionSlider->setMinimum(0);
        compressionSlider->setMaximum(9);
        compressionSlider->setSingleStep(1);
        compressionSlider->setPageStep(1);
        compressionSlider->setValue(0);
        compressionSlider->setSliderPosition(0);
        compressionSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(compressionSlider);

        compressionNum = new QLabel(centralwidget);
        compressionNum->setObjectName("compressionNum");

        horizontalLayout_2->addWidget(compressionNum);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        selectRoi = new QCheckBox(centralwidget);
        selectRoi->setObjectName("selectRoi");
        selectRoi->setMinimumSize(QSize(135, 0));

        horizontalLayout_2->addWidget(selectRoi);


        gridLayout_4->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        sortButton = new QPushButton(centralwidget);
        sortButton->setObjectName("sortButton");
        sortButton->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(sortButton);

        themeButton = new QToolButton(centralwidget);
        themeButton->setObjectName("themeButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/img/Light.png"), QSize(), QIcon::Normal, QIcon::Off);
        themeButton->setIcon(icon);
        themeButton->setCheckable(false);
        themeButton->setChecked(false);

        horizontalLayout->addWidget(themeButton);

        languageButton = new QToolButton(centralwidget);
        languageButton->setObjectName("languageButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/img/RuDark.png"), QSize(), QIcon::Normal, QIcon::Off);
        languageButton->setIcon(icon1);

        horizontalLayout->addWidget(languageButton);

        infoButton = new QToolButton(centralwidget);
        infoButton->setObjectName("infoButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/img/InfB.png"), QSize(), QIcon::Normal, QIcon::Off);
        infoButton->setIcon(icon2);

        horizontalLayout->addWidget(infoButton);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout_4->addLayout(horizontalLayout, 4, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(200, 0));
        lineEdit->setClearButtonEnabled(false);

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1, Qt::AlignTop);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(200, 0));

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 1, Qt::AlignTop);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        inputFolderButton = new QPushButton(centralwidget);
        inputFolderButton->setObjectName("inputFolderButton");

        gridLayout_2->addWidget(inputFolderButton, 0, 2, 1, 1);

        outputFolderButton = new QPushButton(centralwidget);
        outputFolderButton->setObjectName("outputFolderButton");

        gridLayout_2->addWidget(outputFolderButton, 1, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        gridLayout_4->addWidget(progressBar, 5, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 427, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ColorSnake", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Optimization", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Mask settings", nullptr));
        valMinNum->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Sat. Min:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Val. Min:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Val. Min:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Sat. Min:", nullptr));
        satMinNum->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Clipping B/W", nullptr));
        valMinNumGray->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        satMinNumGray->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Compression", nullptr));
        compressionNum->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        selectRoi->setText(QCoreApplication::translate("MainWindow", "Custom selection", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        themeButton->setText(QString());
        languageButton->setText(QString());
        infoButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Input Folder", nullptr));
        inputFolderButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        outputFolderButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Output Folder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
