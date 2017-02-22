#include "imagedisplay.h"

#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QSize>
#include <QDebug>
#include <QMouseEvent>
#include <QPen>
#include <QColor>
#include <qmath.h>

ImageDisplay::ImageDisplay(QWidget *parent) :
    QWidget(parent), img(NULL)
{
    setMouseTracking(true);
    edit.setColor(QColor(64, 245, 255));
    edit.setWidth(2);
    normal.setColor(QColor(251, 228, 68));
    normal.setWidth(3);
    highlight.setColor(QColor(255, 122, 64));
    highlight.setWidth(5);
    pointpen.setColor(Qt::red);
    pointpen.setCapStyle(Qt::RoundCap);
    pointpen.setWidth(6);
    PLinePen.setColor(Qt::white);
    PLinePen.setWidth(3);
    
    //for (int i = 0; i < boxNumber; i++) {
    //    bList.push_back(new QRect(QPoint(0, 0), QSize(0, 0)));
    //}
}

ImageDisplay::~ImageDisplay()
{
    if(img != NULL)
    {
        delete(img);
    }
    //for (int i = 0; i < bList.size(); i++) {
    //    if (bList[i] != NULL) {
    //       delete bList[i];
    //    }
    //}
}

void ImageDisplay::setImage(QImage* t, FileListStruct *thisfile)
{
    if(img != NULL)
    {
        delete(img);
        //bList.clear();
        addToNumber();
    }

    delete boundingBox;
    int x1 = thisfile->x1, y1 = thisfile->y1;
    int x2 = thisfile->x2, y2 = thisfile->y2;
    boundingBox = new QRect(QPoint(x1, y1), QSize(x2 - x1 + 1, y2 - y1 + 1));
    //qDebug() << x1 << y1 << x2 << y2 << boundingBox << thisfile->filename;

    Reset();

    img = t;
    this->update();
}

void ImageDisplay::paintEvent(QPaintEvent *)
{
    //qDebug() << "Painting...";
    if(img != NULL)
    { 
        QPainter painter(this);
        QRect target = this->rect();
        QRect source = QRect(QPoint(0, 0), img->size());
        painter.drawImage(target, *img, source);
        
        //qDebug() << "normal" << bList.size();
        painter.setPen(normal);
        //qDebug() << boundingBox;
        painter.drawRect(QRect(rconv(boundingBox->topLeft()), rconv(boundingBox->size())));
        painter.setPen(PLinePen);
        QPoint nonePoint(-1, -1);
        for (int i = 0; i < pointNumber; i++) {
            if (pList[i] != nonePoint && pList[pPair[i]] != nonePoint)
                painter.drawLine(rconv(pList[i]), rconv(pList[pPair[i]]));
        }
        for (int i = 0; i < pointNumber; i++)
            if (pList[i] != nonePoint)
            {
                pointpen.setColor(pColor[i]);
                painter.setPen(pointpen);
                painter.drawPoint(rconv(pList[i]));
            }
        painter.setPen(highlight);
        QString pointerPos;
        QTextStream(&pointerPos) << "( " << px << " , " << py << " )";
        painter.drawText(QPoint(20,20), pointerPos);
        /*
        for(int i = 0; i < bList.size(); i++)
        {
            //qDebug() << "box";
            if(bList[i]->contains(conv(QPoint(tmpX, tmpY))))
            {
                continue;
            }
            //qDebug() << rconv(bList[i]->topLeft()) << rconv(bList[i]->size());
            emit boxUnhighlight(i);
            painter.drawRect(QRect(rconv(bList[i]->topLeft()),
                                   rconv(bList[i]->size())));
        }
        //qDebug() << "highlight";
        painter.setPen(highlight);
        for(int i = 0; i < bList.size(); i++)
        {
            if(!bList[i]->contains(conv(QPoint(tmpX, tmpY))))
            {
                continue;
            }
            emit boxHighlight(i);
            painter.drawRect(QRect(rconv(bList[i]->topLeft()),
                                   rconv(bList[i]->size())));
        }
        
        if(state)
        {
            painter.setPen(edit);
            painter.drawRect(min(oriStartX, tmpX), min(oriStartY, tmpY),
                             qAbs(tmpX - oriStartX) + 1, qAbs(tmpY - oriStartY) + 1);
        }*/
    }
}

void ImageDisplay::mousePressEvent(QMouseEvent *t)
{
    QPoint p = conv(t->pos());
    //qDebug() << "Press:" << t->pos() << ", img: " << p;
    //state = 1;
    //startX = p.x();
    //startY = p.y();
    //oriStartX = max(min(t->pos().x(), this->width() - 1), 0);
    //oriStartY = max(min(t->pos().y(), this->height() - 1), 0);


    for (int i = 0; i < pointNumber; i++) {
        QPoint dis = pList[i] - p;
        if (dis.manhattanLength() < 5) {
            lastPos = pList[i];
            selectLast = i;

            if (t->button() == Qt::RightButton) {
                pList[i] = QPoint(-1,-1);
                break;
            }

            selectPoint = i;
            pColor[i] = Qt::red;
            break;
        }
    }
    this->update();
}

void ImageDisplay::mouseReleaseEvent(QMouseEvent *t)
{
    //QPoint p = conv(t->pos());
    //qDebug() << "Release:" << t->pos() << ", img: " << p;
    //state = 0;
    //int aX = p.x();
    //int aY = p.y();
    //addBox(min(startX, aX), min(startY, aY), max(startX, aX), max(startY, aY));

    if (selectPoint > -1) {
        pColor[selectPoint] = oripColor[selectPoint];
    }
    selectPoint = -1;
    this->update();
}

void ImageDisplay::mouseMoveEvent(QMouseEvent *t)
{
    //qDebug() << "Move:" << t->pos() << ", img: " << conv(t->pos());
    //tmpX = max(min(t->pos().x(), this->width() - 1), 0);
    //tmpY = max(min(t->pos().y(), this->height() - 1), 0);
    //if (state == 1) {
    //    QPoint p = conv(t->pos());
    //    int aX = p.x();
    //    int aY = p.y();
    //    //emit modifyBox(min(startX, aX), min(startY, aY), max(startX, aX), max(startY, aY));
    //}

    QPoint p = conv(t->pos());

    px = p.rx();
    py = p.ry();

    if (selectPoint > -1) {
        pList[selectPoint] = p;
    }
    this->update();
}

inline int ImageDisplay::min(int a, int b)
{
    return (a < b)? a: b;
}

inline int ImageDisplay::max(int a, int b)
{
    return (a > b)? a: b;
}

QPoint ImageDisplay::conv(QPoint p0)
{
    QSize imgSize = img->size();
    int tX = round(double(p0.x()) * imgSize.width() / this->width());
    int tY = round(double(p0.y()) * imgSize.height() / this->height());
    return QPoint(max(min(tX, imgSize.width() - 1), 0),
                  max(min(tY, imgSize.height() - 1), 0));
}

QPoint ImageDisplay::rconv(QPoint p0)
{
    QSize imgSize = img->size();
    int tX = round(double(p0.x()) * this->width() / imgSize.width());
    int tY = round(double(p0.y()) * this->height() / imgSize.height());
    return QPoint(max(min(tX, this->width() - 1), 0),
                  max(min(tY, this->height() - 1), 0));
}

QSize ImageDisplay::rconv(QSize s0)
{
    QSize imgSize = img->size();
    int tX = round(double(s0.width()) * this->width() / imgSize.width());
    int tY = round(double(s0.height()) * this->height() / imgSize.height());
    return QSize(max(min(tX, this->width() - 1), 0),
                 max(min(tY, this->height() - 1), 0));
}


void ImageDisplay::addBox(int x1, int y1, int x2, int y2)
{
    //bList.push_back(new QRect(QPoint(x1, y1), QSize(x2 - x1 + 1, y2 - y1 + 1)));
    // 知道当前修改的是第几个
    //if (bList[selectedbox] != NULL) {
    //    delete bList[selectedbox];
    //}
    //bList[selectedbox] = new QRect(QPoint(x1, y1), QSize(x2 - x1 + 1, y2 - y1 + 1));
    //emit modifyBox(x1, y1, x2, y2);
    //this->update();
}

void ImageDisplay::Reset()
{
    QPoint center = boundingBox->center();
    for (int i = 0; i < pointNumber; i++) {
        pList[i] = QPoint(center.rx() + pDefault[i][0], center.ry() + pDefault[i][1]);
    }
    this->update();
}

void ImageDisplay::Cancel()
{
    if (selectLast > -1) {
        pList[selectLast] = lastPos;
    }
    this->update();
}

void ImageDisplay::loadPoint(int tagRank, int x1, int y1)
{
    if (tagRank < 0 || tagRank >= pointNumber)
        return;
    pList[tagRank] = QPoint(x1, y1);
}

void ImageDisplay::WritePoint(QTextStream &stream)
{
    bool notchange = true;
    QPoint center = boundingBox->center();
    for (int i = 0; i < pointNumber; i++) {
        if (pList[i] != QPoint(center.rx() + pDefault[i][0], center.ry() + pDefault[i][1])) {
            notchange = false;
        }
    }
    if (notchange) {
        return;
    }

    for (int i = 0; i < tagNumber; i++) {
        //qDebug() << pList[i].rx() << pList[i].ry() << tagName[i];
        stream << pList[i].rx() << " " << pList[i].ry() << " " << tagName[i] << endl;
    }
}

void ImageDisplay::delBox()
{
    //if(bList.size())
    //{
    //    bList.pop_back();
    //}
    //this->update();
}

void ImageDisplay::selectBox(int num)
{
    //selectedbox = num;
}

void ImageDisplay::addToNumber()
{
    //while (bList.size() < boxNumber) {
    //   bList.push_back(new QRect(QPoint(0, 0), QSize(0, 0)));
    //}
}
