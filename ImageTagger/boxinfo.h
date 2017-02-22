#ifndef BOXINFO_H
#define BOXINFO_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include "boxesdisplay.h"

extern class BoxesDisplay;

class BoxInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BoxInfo(int a, int b, int c, int d, QString name, int _rank, BoxesDisplay* _father);
    ~BoxInfo();
    
    void focus();
    
    void setHighlight();
    void setUnhighlight();
    void setTag(const QString& t);
    void setPosition(int a, int b, int c, int d);
    bool haveHead();
    bool haveBody();
    bool haveWhole();
    void setSelected();
    void setUnselected();
    void clear();

    int getCoord(int p);
    QString getTag();

    static const int tagNumber = 8;
    static const QString tagShow[8];
    static const QString tagName[8];
    
private:
    BoxesDisplay *father;
    int x1, y1, x2, y2;
    int rank;
    QPushButton selectButton;
    QLabel x1l, y1l, x2l, y2l;
    QLabel tag, selTag;
    QHBoxLayout layout;
    QLabel highlight;
    int hl = 0;
    
signals:
    
public slots:
    void selected();
};


#endif // BOXINFO_H
