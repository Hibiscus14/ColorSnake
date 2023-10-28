#include "mainwindow.h"
void SaveImages(std::vector<std::pair<std::vector<int>, std::string>>& colorfulImages, std::vector<std::pair<std::vector<int>, std::string>>& grayImages, const QString& outputFolder)
{
    int j=1;
    for(size_t i = 0; i < colorfulImages.size(); ++i)
    {
        std::string str = colorfulImages[i].second;
        cv::Mat image = cv::imread(str);
        QString path = outputFolder + '/' + QString::number(j) + ".jpg";
        cv::imwrite(path.toStdString(), image);
        image.release();
        j++;
        count++;
        progress->setValue(count);
    }
    for(size_t i = 0; i < grayImages.size(); ++i)
    {
        std::string str = grayImages[i].second;
        cv::Mat image = cv::imread(str);
        QString path = outputFolder + '/' + QString::number(j) + ".jpg";
        cv::imwrite(path.toStdString(), image);
        image.release();
        j++;
        count++;
        progress->setValue(count);

    }

}
