#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <map>
#include <QProgressBar>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/tracking/tracking.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern QProgressBar* progress;
extern int count;

void getColorsOfAllImages(std::vector<std::pair<std::vector<int>, std::string>>&colorfulImages, std::vector<std::pair<std::vector<int>, std::string>>&grayImages, const std::vector<std::string>& fileNames, bool RoiSelect, const int& hmin,const int& hmax,const int& smin, const int& smax, const int& vmin, const int& vmax,const int& compression, const int& sGray, const int& vGray);
void SaveImages(std::vector<std::pair<std::vector<int>, std::string>>& colorfulImages, std::vector<std::pair<std::vector<int>, std::string>>& grayImages, const QString& outputFolder);
void Sorting(std::vector<std::pair<std::vector<int>, std::string>>& colorfulImages, std::vector<std::pair<std::vector<int>, std::string>>& grayImages);
std::vector<std::string> GetFileNames(const QString& path);
cv::Mat masking(cv::Mat bgrImage, const int& hmin,const int& hmax,const int& smin, const int& smax, const int& vmin, const int& vmax);
std::vector<int> getDominantColor(cv::Mat hsvImage, cv::Mat mask, const int& compression);
bool hasFiles (const QString &path);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_inputFolderButton_clicked();

    void on_outputFolderButton_clicked();

    void on_sortButton_clicked();

    void on_satMin_valueChanged(int value);

    void on_valMin_valueChanged(int value);

    void on_compressionSlider_valueChanged(int value);

    void on_satMinGray_valueChanged(int value);

    void on_valMinGray_valueChanged(int value);

    void on_themeButton_clicked();

    void on_languageButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::MainWindow *ui;
    bool dark = false;
    bool rus = false;

};
#endif // MAINWINDOW_H
