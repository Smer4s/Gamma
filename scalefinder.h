#ifndef SCALEFINDER_H
#define SCALEFINDER_H
#include <QVector>
#include "Note.h"

class ScaleFinder
{
    QVector<QVector<Note>> matrix;
public:
    ScaleFinder();
    QVector<QVector<Note>> getScale();
    void setScale(int scale, bool major);
    void clear();
};

#endif // SCALEFINDER_H
