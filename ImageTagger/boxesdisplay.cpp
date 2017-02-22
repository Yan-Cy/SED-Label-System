#include "boxesdisplay.h"

#include <QSizePolicy>
#include <QKeySequence>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>

BoxesDisplay::BoxesDisplay(QWidget *parent) :
    QWidget(parent)
{
    spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    
    this->setLayout(&layout);
    //layout.addWidget(&rmButton);
    layout.addItem(spacer);
    
    //rmButton.setText("Remove last bounding box");
    
    QSizePolicy t;
    t.setHorizontalPolicy(QSizePolicy::Expanding);
    t.setVerticalPolicy(QSizePolicy::Fixed);
    
    //connect(&rmButton, SIGNAL(clicked()), this, SLOT(delBox()));
    //connect(&rmButton, SIGNAL(clicked()), this, SIGNAL(rmBox()));
    //rmButton.setShortcut(QKeySequence(tr("Ctrl+R")));

    for (int i = 0; i < BoxInfo::tagNumber; i++) {
        addBox(0,0,0,0,BoxInfo::tagName[i], i);
    }
}

BoxesDisplay::~BoxesDisplay()
{
    clearList();
    //delete spacer;
}

void BoxesDisplay::addBox(int x1, int y1, int x2, int y2, QString name, int rank)
{
    //qDebug() << name << endl;
    qDebug() << "Adding box: " << x1 << y1 << x2 << y2 << name << rank;
    layout.removeItem(spacer);
    BoxInfo* newBox = new BoxInfo(x1, y1, x2, y2, name, rank, this);
    currentBox(newBox, bList.size());
    //qDebug() << "Setting current box";
    //qDebug() << selectedBox->getTag() << endl;
    bList.push_back(newBox);
    layout.addWidget(bList.back());
    layout.addItem(spacer);
    bList.back()->focus();
    //qDebug() << "End Adding";
}

void BoxesDisplay::delBox()
{
    if(bList.size())
    {
        layout.removeItem(spacer);
        layout.removeWidget(bList.back());
        delete bList.back();
        bList.pop_back();
        layout.addItem(spacer);
    }
    if(bList.size())
    {
        bList.back()->focus();
    }
}

void BoxesDisplay::clearList()
{
    /*
    layout.removeItem(spacer);
    while(bList.size())
    {
        layout.removeWidget(bList.back());
        delete bList.back();
        bList.pop_back();
    }
    bList.clear();
    layout.addItem(spacer);
    */
    for (int i = 0; i < BoxInfo::tagNumber; i++) {
        //qDebug() << bList[i]->getTag();
        bList[i]->clear();
    }
}

void BoxesDisplay::boxHighlight(int p)
{
    bList[p]->setHighlight();
}

void BoxesDisplay::boxUnhighlight(int p)
{
    bList[p]->setUnhighlight();
}

int BoxesDisplay::save(const QString &path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Save failed";
        return 1;
    }
    QTextStream out(&file);
    for(int i = 0; i < bList.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            out << bList[i]->getCoord(j) << " ";
        }
        out << bList[i]->getTag() << endl;
    }
    file.close();
    return 0;
}

void BoxesDisplay::setLastTag(const QString &tag)
{
    qDebug() << bList.size() << "-------";
    if(bList.size())
    {
        bList.back()->setTag(tag);
    }
}

bool BoxesDisplay::check()
{
    bool head = false, body = false, whole = false;
    for(int i = 0; i < bList.size(); i++)
    {
        if (bList[i]->haveHead()) head = true;
        if (bList[i]->haveBody()) body = true;
        if (bList[i]->haveWhole()) whole = true;
        if (head && body && whole) return true;
    }
    qDebug() << "Head " << head << "body " << body << "whole " << whole;
    return false;
}

void BoxesDisplay::modifyBox(int x1, int y1, int x2, int y2)
{
    if (!selectedBox) {
        return;
    }
    //qDebug() << selectedBox->getTag() << endl;
    selectedBox->setPosition(x1,y1,x2,y2);
}

void BoxesDisplay::currentBox(BoxInfo* box, int i)
{
    //qDebug() << "!";
    if (box == NULL) {
        return;
    }
    if (selectedBox) {
        selectedBox->setUnselected();
    }
    selectedBox = box;
    selectedBox->setSelected();
    selectBox(i);
}

void BoxesDisplay::setCurrentBox(QString tag)
{
    for(int i = 0; i < bList.size(); i++)
    {
        if (bList[i]->getTag() == tag) {
            currentBox(bList[i], i);
            return;
        }
    }
}
