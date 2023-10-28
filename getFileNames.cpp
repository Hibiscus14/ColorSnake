#include "mainwindow.h"
#include <QDir>


std::vector<std::string> GetFileNames(const QString& path)
{
    std::vector<std::string> files;
    QDir dir;
    dir.cd(path);
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        QString name = path + '/'+ fileInfo.fileName();
        files.push_back(name.toStdString());
    }
    return files;
}
