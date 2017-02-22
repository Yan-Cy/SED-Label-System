#ifndef BOXESDISPLAY_H
#define BOXESDISPLAY_H

#include "boxinfo.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QString>

#include <vector>

extern class BoxInfo;

class BoxesDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit BoxesDisplay(QWidget *parent = 0);
    ~BoxesDisplay();
    
    void clearList();
    int save(const QString& path);
    void setLastTag(const QString& tag);
    void addBox(int x1, int y1, int x2, int y2, QString name, int rank);
    void currentBox(BoxInfo* box, int i);
    bool check();
    void setCurrentBox(QString tag);

private:
    BoxInfo* selectedBox = NULL;
    std::vector<BoxInfo*> bList;
    QVBoxLayout layout;
    //QPushButton rmButton;
    QSpacerItem* spacer;

signals:
    void rmBox();
    void selectBox(int num);
    
public slots:
    void modifyBox(int x1, int y1, int x2, int y2);
    void boxHighlight(int p);
    void boxUnhighlight(int p);
    
private slots:
    void delBox();
};

#endif // BOXESDISPLAY_H
