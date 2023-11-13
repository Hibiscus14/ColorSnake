#include "mainwindow.h"
#include <algorithm>


bool comp1(const std::pair<std::vector<int>, std::string>& a, const std::pair<std::vector<int>, std::string>& b)
{

    return a.first[0]<b.first[0];
}
bool comp2(const std::pair<std::vector<int>, std::string>& a, const std::pair<std::vector<int>, std::string>& b)
{

    return a.first[2]<b.first[2];
}


void Sorting(std::vector<std::pair<std::vector<int>, std::string>>& colorfulImages, std::vector<std::pair<std::vector<int>, std::string>>& grayImages)
{
    std::sort(colorfulImages.begin(), colorfulImages.end(), comp1);

    std::sort(grayImages.begin(), grayImages.end(), comp2);

}


