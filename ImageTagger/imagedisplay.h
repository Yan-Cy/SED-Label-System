#ifndef IMAGEDISPLAY_H
#define IMAGEDISPLAY_H

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QPen>
#include <QRect>
#include <QColor>
#include <vector>
#include <QTextStream>
#include "structs.h"

class ImageDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit ImageDisplay(QWidget *parent = 0);
    ~ImageDisplay();
    
    void setImage(QImage* t, FileListStruct *thisfile);
    void addBox(int x1, int y1, int x2, int y2);
    void addToNumber();
    void Reset();
    void Cancel();
    void loadPoint(int tagRank, int x1, int y1);
    void WritePoint(QTextStream &stream);
    
private:
    QImage* img;
    QPen highlight, normal, edit, pointpen, PLinePen;
    
    inline int min(int a, int b);
    inline int max(int a, int b);
    QPoint conv(QPoint p0);
    QPoint rconv(QPoint p0);
    QSize rconv(QSize s0);

    
    //std::vector<QRect*> bList;
    int px, py;
    static const int pointNumber = 8;
    QPoint pList[pointNumber];
    QPoint lastPos;
    int selectPoint = -1;
    int selectLast = -1;
    const QColor oripColor[pointNumber] = {Qt::cyan, Qt::white, Qt::yellow, Qt::blue, Qt::darkYellow, Qt::darkBlue, Qt::green, Qt::lightGray};
    QColor pColor[pointNumber] = {Qt::cyan, Qt::white, Qt::yellow, Qt::blue, Qt::darkYellow, Qt::darkBlue, Qt::green, Qt::lightGray};
    const int pDefault[pointNumber][2] = {{0,0},{0,10},{-10,20},{10,20},{-20,20},{20,20},{-25,30},{25,30}};
    const int pPair[pointNumber] = {1,2,4,1,6,3,4,5};
    QRect* boundingBox = NULL;
    
    int tagNumber = 8;
    QString tagName[8] = {"Head", "Neck", "LShoulder", "RShoulder", "LElbow", "RElbow", "LPalm", "RPalm"};


    int startX, startY, tmpX, tmpY;
    //int selectedbox = 0;
    int oriStartX, oriStartY;
    int state = 0;
    //const int boxNumber = BoxInfo::tagNumber;
    
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *t);
    void mouseReleaseEvent(QMouseEvent *t);
    void mouseMoveEvent(QMouseEvent *t);
    
signals:
    void modifyBox(int, int, int, int);
    void boxHighlight(int);
    void boxUnhighlight(int);
    
public slots:
    void delBox();
    void selectBox(int num);
};

#endif // IMAGEDISPLAY_H
