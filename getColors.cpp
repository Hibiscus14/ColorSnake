#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <fstream>

std::ofstream exceptionLog;

void logException(const std::string& message) {
    exceptionLog << "Exception: " << message << std::endl;
}
 void getColorsOfAllImages(std::vector<std::pair<std::vector<int>, std::string>>&colorfulImages, std::vector<std::pair<std::vector<int>, std::string>>&grayImages, const std::vector<std::string>& fileNames, bool RoiSelect, const int& hmin,const int& hmax,const int& smin, const int& smax, const int& vmin, const int& vmax,const int& compression, const int& sGray, const int& vGray)
{
     exceptionLog.open("exception.log");

     cv::Mat firstImage = cv::imread(fileNames[0]);
     cv::Rect2d roi;
     if(RoiSelect)
     {
     cv::namedWindow("Select ROI", cv::WND_PROP_FULLSCREEN);
     cv::setWindowProperty("Select ROI", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);
     cv::resizeWindow("Select ROI", 700, 700);
     roi = cv::selectROI("Select ROI", firstImage,true, false );
     cv::destroyAllWindows();
     }

  for(size_t i = 0; i < fileNames.size(); ++i)
  {
      count++;
      progress->setValue(count);
      try{
      cv::Mat image = cv::imread(fileNames[i]);
      if(image.rows!=firstImage.rows||image.cols!=firstImage.cols)  cv::resize(image, image, firstImage.size());
      if(RoiSelect) { image = image(roi); }
      cv::Mat mask = masking(image, hmin,hmax,smin,smax,vmin,vmax);
      std::vector<int>dominantColor = getDominantColor(image, mask, compression);
      image.release();
      if(dominantColor[1]<sGray || dominantColor[2]<vGray )
      {
          grayImages.emplace_back(dominantColor, fileNames[i]);
      }
      else {
          colorfulImages.emplace_back(dominantColor, fileNames[i]);
      }


  } catch (const cv::Exception& e) {
              // Handle OpenCV exceptions
              // Log the exception or continue processing other images
           logException(e.what());
              continue;
          } catch (const std::exception& e) {
              // Handle other exceptions
              // Log the exception or continue processing other images
          logException(e.what());
              continue;
          }
  }
  exceptionLog.close();
}


cv::Mat masking(cv::Mat bgrImage, const int& hmin,const int& hmax,const int& smin, const int& smax, const int& vmin, const int& vmax)
{
    cv::Mat hsvImage, mask;
    cv::cvtColor(bgrImage, hsvImage, cv::COLOR_BGR2HSV);
    cv::Scalar lower(hmin, smin, vmin);
    cv::Scalar upper(hmax, smax, vmax);
    cv::inRange(hsvImage, lower, upper, mask);

  return mask;
}


std::vector<int> getDominantColor(cv::Mat bgrImage,cv::Mat mask, const int& compression)
{
    if(compression>0)
    {
    cv::resize(bgrImage, bgrImage, cv::Size(), (1-(compression/10)), (1-(compression/10)));
    cv::resize(mask, mask, cv::Size(), (1-(compression/10)), (1-(compression/10)));
    }

    cv::Mat hsvImage, grayImage;
    cv::cvtColor(bgrImage, hsvImage, cv::COLOR_BGR2HSV);
    //cv::imshow("image", bgrImage);
    int k=4, sat = cv::mean(hsvImage)[1], val = cv::mean(hsvImage)[2];

    cv::Mat reshapedImage = hsvImage.reshape(1, hsvImage.rows * hsvImage.cols);
    //cv::imshow("img", hsvImage);
    //cv::imshow("i", mask);
    cv::Mat reshapedMask = mask.reshape(1, mask.rows * mask.cols);
    cv::Mat labels, centers;

    reshapedImage.convertTo(reshapedImage, CV_32F);

    cv::kmeans(reshapedImage,k,labels, cv::TermCriteria(cv::TermCriteria::EPS+cv::TermCriteria::COUNT, 10, 1.0), 3, cv::KMEANS_PP_CENTERS, centers);
    std::map<int, int> labelCounts;

    for (int i = 0; i < labels.rows; ++i)
    {
        int label = labels.at<int>(i, 0);
        if((int)mask.at<uchar>(i)==255){ labelCounts[label]++; }
    }

    int maxCount = -1;
    int dominantLabel = -1;
    for (auto& pair : labelCounts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            dominantLabel = pair.first;
        }
    }

  cv::Scalar dominantColors = centers.at<cv::Vec3f>(dominantLabel, 0);
  std::vector<int> dominantColor;
  dominantColor.push_back(dominantColors[0]);
  dominantColor.push_back(sat);
  dominantColor.push_back(val);

    return dominantColor;
}
