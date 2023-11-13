#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QStyle>
#include <QMessageBox>
#include <QToolTip>
#include <QThread>



QProgressBar* progress;
int count=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 QPalette lightPalette;

 lightPalette.setColor(QPalette::ToolTipBase,Qt::white);
 lightPalette.setColor(QPalette::ToolTipText,Qt::black);
 lightPalette.setColor(QPalette::Highlight,QColor(255,148,121));
 lightPalette.setColor(QPalette::Window, QColor(253, 253, 253));
 lightPalette.setColor(QPalette::WindowText, Qt::black);
 lightPalette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(127, 127, 127));
 lightPalette.setColor(QPalette::Base, QColor(255, 255, 255));
 lightPalette.setColor(QPalette::AlternateBase, QColor(255, 255, 255));
 lightPalette.setColor(QPalette::Text, Qt::black);
 lightPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
 lightPalette.setColor(QPalette::Dark, QColor(35, 35, 35));
 lightPalette.setColor(QPalette::Shadow, QColor(240, 240, 240));
 lightPalette.setColor(QPalette::Button, QColor(253, 253, 253));
 lightPalette.setColor(QPalette::ButtonText, Qt::black);
 lightPalette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(127, 127, 127));
 lightPalette.setColor(QPalette::BrightText, Qt::red);
 lightPalette.setColor(QPalette::Link, Qt::black);
 lightPalette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
 lightPalette.setColor(QPalette::HighlightedText, Qt::black);
 lightPalette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(127, 127, 127));

qApp->setPalette(lightPalette);
 QToolTip::setPalette(lightPalette);
 ui->satMinNum->setText(QString::number(ui->satMin->value()));
 ui->valMinNum->setText(QString::number(ui->valMin->value()));
 ui->satMinNumGray->setText(QString::number(ui->satMinGray->value()));
 ui->valMinNumGray->setText(QString::number(ui->valMinGray->value()));

 ui->progressBar->setVisible(false);
    progress = ui->progressBar;

   if(rus) {
    ui->label_3->setToolTip("Данные параметры ограничивают зону определения цвета, \nдля более чистого результата, путём удаления пикселей цвет \nкоторых недостоточно насыщенный или недостаточно яркий \nРекмоендуемые параметры: Sat 150 Val 50");
    ui->label_5->setToolTip("Сжатие изображения для более быстрой но менее качественной обработки");
    ui->label_12->setToolTip("Данные параметры переносят часть картинок в раздел чёрно-белые, если картинка достаточно ярка/тёмная\nРекмоендуемые параметры: Sat 40 Val 40\nДля разных картинок подходят разные значения, подбирите что подходит вам\nЕсли вы не хотите отсекать чёрные и белые изображения - оставьте параметры на 0");
    ui->selectRoi->setToolTip("Лимитирует зону в которой алгоритм вычисляет цвет");
   }

else {
       ui->label_3->setToolTip("This sliders limit the color-detection zone to achive \nbetter sorting results. It doesnt count the colour of pixels that are not saturated enough or not bright enough. \nRecomended settings: Sat 150 Val 50");
       ui->label_5->setToolTip("Compressing the image for faster but worse quality sorting");
       ui->label_12->setToolTip("This sliders decide if pictures are considered balck or white and moved to the end of sorted images.\nIf the picture is dark or bright enough it will be considered and moved to ''Black&white'' images\nRecomended settings: Sat 40 Val 40\nHere values are really dependant on images, try your own and see what works\nIf you dont want to sepperate B&W immages leave the sliders at 0");
       ui->selectRoi->setToolTip("Limits the zone in which the sorting will work");
   }


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inputFolderButton_clicked()
{
    QString inputFolder;
    if(rus) { inputFolder = QFileDialog::getExistingDirectory(this, "Выбор папки", QDir::homePath()); }
    else { inputFolder = QFileDialog::getExistingDirectory(this, "Select folder", QDir::homePath()); }

    ui->lineEdit->setText(inputFolder);
}


void MainWindow::on_outputFolderButton_clicked()
{
    QString outputFolder;
   if(rus) { outputFolder = QFileDialog::getExistingDirectory(this,"Выбор папки", QDir::homePath()); }
   else { outputFolder = QFileDialog::getExistingDirectory(this,"Select folder", QDir::homePath()); }
    ui->lineEdit_2->setText(outputFolder);
}


void MainWindow::on_sortButton_clicked()
{
    count=0;

    QString inputFolder = ui->lineEdit->text();
    QString outputFolder = ui->lineEdit_2->text();
    QDir outDir (outputFolder);
    if(inputFolder.isEmpty()||outputFolder.isEmpty())
    {
        if(rus) { QMessageBox::critical(this, tr("ERROR"), tr("Поля не заполнены") ); }
        else { QMessageBox::critical(this, tr("ERROR"), tr("Fields are empty") ); }
    }
    else if(!outDir.isEmpty())
    {
        if(rus) { QMessageBox::critical(this, tr("ERROR"), tr("Папка не пустая") ); }
        else { QMessageBox::critical(this, tr("ERROR"), tr("The folder isn't empty") ); };
    }
    else if(!hasFiles(inputFolder))
    {
        if(rus) { QMessageBox::critical(this, tr("ERROR"), tr("В папке нет изображений") ); }
        else { QMessageBox::critical(this, tr("ERROR"), tr("The folder doesn't contain any imajes") ); }
    }
    else {

    ui->sortButton->setEnabled(false);

    ui->progressBar->setValue(count);
    ui->progressBar->setVisible(true);

    std::vector<std::string> fileNames = GetFileNames(inputFolder);
    std::vector<std::string> files;

    ui->progressBar->setMaximum(fileNames.size()*2);
    bool RoiSelect = ui->selectRoi->isChecked();

    int hmin = 0, smin = ui->satMin->value(), vmin = ui->valMin->value(), compression = ui->compressionSlider->value(), sGray = ui->satMinGray->value(), vGray = ui->valMinGray->value();
    int hmax = 179, smax = 255, vmax =255;

    std::vector<std::pair<std::vector<int>, std::string>> colorfulImages;
    std::vector<std::pair<std::vector<int>, std::string>> grayImages;

    getColorsOfAllImages(colorfulImages, grayImages, fileNames, RoiSelect, hmin, hmax, smin, smax, vmin, vmax, compression, sGray, vGray);

    Sorting(colorfulImages, grayImages);



    SaveImages(colorfulImages, grayImages, outputFolder);

    
        for(int i=progress->value();i<=progress->maximum();i++)
    { 
        progress->setValue(i);
        QThread::msleep(70);
    }

    ui->sortButton->setEnabled(true);
}

}


void MainWindow::on_themeButton_clicked()
{
    if(dark==false) {
        QPalette darkPalette;
        darkPalette = qApp->palette();
        darkPalette.setColor(QPalette::Window,QColor(53,53,53));
        darkPalette.setColor(QPalette::WindowText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::WindowText,QColor(127,127,127));
        darkPalette.setColor(QPalette::Base,QColor(42,42,42));
        darkPalette.setColor(QPalette::AlternateBase,QColor(66,66,66));
        darkPalette.setColor(QPalette::ToolTipBase,QColor (53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipText,Qt::white);
        darkPalette.setColor(QPalette::Text,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::Text,QColor(127,127,127));
        darkPalette.setColor(QPalette::Dark,QColor(35,35,35));
        darkPalette.setColor(QPalette::Shadow,QColor(20,20,20));
        darkPalette.setColor(QPalette::Button,QColor(53,53,53));
        darkPalette.setColor(QPalette::ButtonText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
        darkPalette.setColor(QPalette::BrightText,Qt::red);
        darkPalette.setColor(QPalette::Link,Qt::white);
        darkPalette.setColor(QPalette::Highlight,QColor(143,80,157));
        darkPalette.setColor(QPalette::Disabled,QPalette::Highlight,QColor(80,80,80));
        darkPalette.setColor(QPalette::HighlightedText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor(127,127,127));
        qApp->setPalette(darkPalette);
        ui->progressBar->setPalette(darkPalette);
        ui->valMin->setPalette(darkPalette);
        ui->satMin->setPalette(darkPalette);
        ui->valMinGray->setPalette(darkPalette);
        ui->satMinGray->setPalette(darkPalette);
        ui->compressionSlider->setPalette(darkPalette);

        QToolTip::setPalette(darkPalette);
        if(rus)
        { ui->languageButton->setIcon(QIcon::fromTheme("list-add",
                                                 QIcon(":/new/prefix1/img/Eng.png"))); }
        else {ui->languageButton->setIcon(QIcon::fromTheme("list-add",
                                                           QIcon(":/new/prefix1/img/Ru.png")));}
        ui->themeButton->setIcon(QIcon::fromTheme("list-add",
                                                   QIcon(":/new/prefix1/img/dark.png")));
        ui->infoButton->setIcon(QIcon::fromTheme("list-add",
                                                   QIcon(":/new/prefix1/img/infW.png")));

        dark=!dark;

    }
    else {
        QPalette lightPalette;
        lightPalette.setColor(QPalette::ToolTipBase,Qt::white);
        lightPalette.setColor(QPalette::ToolTipText,Qt::black);
        lightPalette.setColor(QPalette::Highlight,QColor(255,148,121));
        lightPalette.setColor(QPalette::ToolTipBase, Qt::white);
        lightPalette.setColor(QPalette::ToolTipText, Qt::black);
        lightPalette.setColor(QPalette::Highlight, QColor(255, 148, 121));
        lightPalette.setColor(QPalette::Window, QColor(253, 253, 253));
        lightPalette.setColor(QPalette::WindowText, Qt::black);
        lightPalette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(127, 127, 127));
        lightPalette.setColor(QPalette::Base, QColor(255, 255, 255));
        lightPalette.setColor(QPalette::AlternateBase, QColor(255, 255, 255));
        lightPalette.setColor(QPalette::Text, Qt::black);
        lightPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
        lightPalette.setColor(QPalette::Dark, QColor(35, 35, 35));
        lightPalette.setColor(QPalette::Shadow, QColor(240, 240, 240));
        lightPalette.setColor(QPalette::Button, QColor(253, 253, 253));
        lightPalette.setColor(QPalette::ButtonText, Qt::black);
        lightPalette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(127, 127, 127));
        lightPalette.setColor(QPalette::BrightText, Qt::red);
        lightPalette.setColor(QPalette::Link, Qt::black);
        lightPalette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
        lightPalette.setColor(QPalette::HighlightedText, Qt::black);
        lightPalette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(127, 127, 127));
        ui->progressBar->setPalette(lightPalette);
        ui->valMin->setPalette(lightPalette);
        ui->satMin->setPalette(lightPalette);
        ui->valMinGray->setPalette(lightPalette);
        ui->satMinGray->setPalette(lightPalette);
        ui->compressionSlider->setPalette(lightPalette);
        qApp->setPalette(lightPalette);
        QToolTip::setPalette(lightPalette);

        if(rus)
        { ui->languageButton->setIcon(QIcon::fromTheme("list-add",
                                                 QIcon(":/new/prefix1/img/EngDark.png"))); }
        else {ui->languageButton->setIcon(QIcon::fromTheme("list-add",
                                                           QIcon(":/new/prefix1/img/RuDark.png")));}

        ui->themeButton->setIcon(QIcon::fromTheme("list-add",
                                                   QIcon(":/new/prefix1/img/Light.png")));
        ui->infoButton->setIcon(QIcon::fromTheme("list-add",
                                                   QIcon(":/new/prefix1/img/InfB.png")));
        dark=!dark;

    }
}


void MainWindow::on_languageButton_clicked()
{
    if(rus)
    {
        ui->label->setText("Input Folder");
        ui->label_2->setText("Output Folder");
        ui->inputFolderButton->setText("Browse");
        ui->outputFolderButton->setText("Browse");
        ui->label_3->setText("Mask settings");
        ui->label_12->setText("Clipping B/W");
        ui->label_4->setText("Optimization");
        ui->label_5->setText("Compression");
        ui->selectRoi->setText("Custom selection");
        ui->sortButton->setText("Sort");
        ui->label_3->setToolTip("This sliders limit the color-detection zone to achive \nbetter sorting results. It doesnt count the colour of pixels that are not saturated enough or not bright enough. \nRecomended settings: Sat 150 Val 50");
        ui->label_5->setToolTip("Compressing the image for faster but worse quality sorting");
        ui->label_12->setToolTip("This sliders decide if pictures are considered balck or white and moved to the end of sorted images. If the picture is dark or bright enough it will be considered and moved to ''Black&white'' images\nRecomended settings: Sat 40 Val 40\nHere values are really dependant on images, try your own and see what works\nIf you dont want to sepperate B&W immages leave the sliders at 0");
        ui->selectRoi->setToolTip("Limits the zone in which the sorting will work");

        if(dark) { ui->languageButton->setIcon(QIcon::fromTheme("list-add",
                                                                QIcon(":/new/prefix1/img/Ru.png"))); }
        else { ui->languageButton->setIcon(QIcon::fromTheme("list-add",
                                                            QIcon(":/new/prefix1/img/RuDark.png"))); }
        rus=!rus;
    }
    else{
        ui->label->setText("Загрузить из");
        ui->label_2->setText("Сохранить в");
        ui->inputFolderButton->setText("Обзор");
        ui->outputFolderButton->setText("Обзор");
        ui->label_3->setText("Параметры маски");
        ui->label_12->setText("Отсечение Ч/Б");
        ui->label_4->setText("Оптимизация");
        ui->label_5->setText("Сжатие");
        ui->selectRoi->setText("Выделение области");
        ui->sortButton->setText("Отсортировать");
        ui->label_3->setToolTip("Данные параметры ограничивают зону определения цвета, \nдля более чистого результата, путём удаления пикселей цвет \nкоторых недостоточно насыщенный или недостаточно яркий \nРекмоендуемые параметры: Sat 150 Val 50");
        ui->label_5->setToolTip("Сжатие изображения для более быстрой но менее качественной обработки");
        ui->label_12->setToolTip("Данные параметры переносят часть картинок в раздел чёрно-белые, если картинка достаточно ярка/тёмная\nРекмоендуемые параметры: Sat 40 Val 40\nДля разных картинок подходят разные значения, подбирите что подходит вам\nЕсли вы не хотите отсекать чёрные и белые изображения - оставьте параметры на 0");
        ui->selectRoi->setToolTip("Лимитирует зону в которой алгоритм вычисляет цвет");

        if(dark) { ui->languageButton->setIcon(QIcon::fromTheme("list-add",
                                                                QIcon(":/new/prefix1/img/Eng.png"))); }
        else { ui->languageButton->setIcon(QIcon::fromTheme("list-add",
                                                            QIcon(":/new/prefix1/img/EngDark.png"))); }
        rus=!rus;
    }

}

void MainWindow::on_infoButton_clicked()
{
    QMessageBox info;
    info.setWindowTitle("Info");
    QPixmap img(":/new/prefix1/icon.ico");
    QPixmap img2 = img.scaled(120, 120, Qt::KeepAspectRatio);
    info.setIconPixmap(img2);
    info.setTextFormat(Qt::RichText);
    info.setTextInteractionFlags(Qt::TextBrowserInteraction);
    if(dark)
    {
        if(rus) {
        info.setText("<b>ColorSnake v1.0</b> by Hibiscus14<br><br>Поддержать автора:  <a href=\"https://www.tinkoff.ru/cf/YryNVeMVbg\" style=\"color: #cc80ff;\">Тут!</a><br>Мои прочие штуки:  <a href=\"https://hibiscus-comms-eng.carrd.co/\" style=\"color: #cc80ff;\">Тут!</a><br>Мой GitHub:  <a href=\https://github.com/Hibiscus14\ style=\"color: #cc80ff;\">Тут!</a>");

        }
        else{
        info.setText("<b>ColorSnake v1.0</b> by Hibiscus14<br><br>Buy me a coffe:  <a href=\"https://www.paypal.com/paypalme/kotoezh\"style=\"color: #cc80ff;\">Here!</a><br>My other stuff:  <a href=\"https://hibiscus-comms-eng.carrd.co/\"style=\"color: #cc80ff;\">Here!</a><br>My GitHub: <a href=\https://github.com/Hibiscus14\ style=\"color: #cc80ff;\">Here!</a>");
        }
    }
    else {
        if(rus) {
    info.setText("<b>ColorSnake v1.0</b> by Hibiscus14<br><br>Поддержать автора:  <a href=\"https://www.tinkoff.ru/cf/YryNVeMVbg\" style=\"color: #db5c48;\">Тут!</a><br>Мои прочие штуки:  <a href=\"https://hibiscus-comms-eng.carrd.co/\" style=\"color: #db5c48;\">Тут!</a><br>Мой GitHub:  <a href=\https://github.com/Hibiscus14\ style=\"color: #db5c48;\">Тут!</a>");

    }
    else{
    info.setText("<b>ColorSnake v1.0</b> by Hibiscus14<br><br>Buy me a coffe:  <a href=\"https://www.paypal.com/paypalme/kotoezh\"style=\"color: #db5c48;\">Here!</a><br>My other stuff:  <a href=\"https://hibiscus-comms-eng.carrd.co/\"style=\"color: #db5c48;\">Here!</a><br>My GitHub: <a href=\https://github.com/Hibiscus14\ style=\"color: #db5c48;\">Here!</a>");
    }
    }

    info.show();
    info.exec();

}

void MainWindow::on_satMin_valueChanged(int value)
{
    ui->satMinNum->setText(QString::number(ui->satMin->value()));
}


void MainWindow::on_valMin_valueChanged(int value)
{
    ui->valMinNum->setText(QString::number(ui->valMin->value()));
}


void MainWindow::on_compressionSlider_valueChanged(int value)
{
    ui->compressionNum->setText(QString::number(ui->compressionSlider->value()*10) + '%');
}


void MainWindow::on_satMinGray_valueChanged(int value)
{
    ui->satMinNumGray->setText(QString::number(ui->satMinGray->value()));
}


void MainWindow::on_valMinGray_valueChanged(int value)
{
    ui->valMinNumGray->setText(QString::number(ui->valMinGray->value()));
}


