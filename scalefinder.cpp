#include "scalefinder.h"

ScaleFinder::ScaleFinder()
{
    for(int i = 0; i < 6; i++)
    {
        QVector<Note> temp;
        matrix.push_back(temp);
    }

    int starterNote;
    for(int i = 0; i < 6; i++)
    {
        switch(i)
        {
        case 0:
            starterNote = 7;
            break;
        case 1:
            starterNote = 2;
            break;
        case 2:
            starterNote = 10;
            break;
        case 3:
            starterNote = 5;
            break;
        case 4:
            starterNote = 0;
            break;
        case 5:
            starterNote = 7;
            break;
        default:
            break;
        }
        for(int j = 0; j < 25; j++)
        {
            Note temp;
            temp.name = starterNote;
            matrix[i].push_back(temp);
            starterNote++;
            starterNote %= 12;
        }
    }
}

QVector<QVector<Note>> ScaleFinder::getScale()
{
    return matrix;
}

QVector<Note> getNotes(const int scale)
{
    QVector<Note> scales;
    Note temp;
    int step = scale;
    for(int i = 0; i < 7; i++)
    {
        switch(i)
        {
        case 0:
            step = scale;
            temp.penta = true;
            break;
        case 1:
            step = (scale + 2)%12;
            temp.penta = true;
            break;
        case 2:
            step = (scale + 4)%12;
            temp.penta = true;
            break;
        case 3:
            step = (scale + 5)%12;
            temp.penta = false;
            break;
        case 4:
            step = (scale + 7)%12;
            temp.penta = true;
            break;
        case 5:
            step = (scale + 9)%12;
            temp.penta = true;
            break;
        case 6:
            step = (scale + 11)%12;
            temp.penta = false;
            break;
        default:
            break;
        }
        temp.name = step;
        scales.push_back(temp);
    }
    return scales;
}

void change(QVector<Note>& List,Note key)
{
    for(int i = 0; i < List.size(); i++)
    {
        if(List[i].name == key.name)
        {
            List[i].hl = true;
            List[i].penta = key.penta;
        }
    }
}

void ScaleFinder::setScale(int scale, bool major)
{
    if(!major)
    {
        scale += 3;
        scale %= 12;
    }

    QVector<Note> scales = getNotes(scale);

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            change(matrix[i],scales[j]);
        }
    }
}

void ScaleFinder::clear()
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 25; j++)
        {
            matrix[i][j].hl = false;
            matrix[i][j].penta = false;
        }
}
