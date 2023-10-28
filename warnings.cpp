#include "mainwindow.h"
#include <QFile>
#include <QDir>

bool hasFiles (const QString &path)
{
    QStringList filter;
    filter << "*.png" << "*.jpg" << "*.jpeg";
    QStringList files = QDir(path).entryList(filter);

    return files.size();
}


