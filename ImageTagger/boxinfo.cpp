#include "boxinfo.h"
#include "boxesdisplay.h"

#include <QSizePolicy>
#include <QDebug>

//const QString BoxInfo::tagShow[11] = {"头部*","身体*","全身*","左触须","右触须", "左前肢","右前肢","左中肢","右中肢","左后肢","右后肢"};
//const QString BoxInfo::tagName[11] = {"Head", "Body", "Whole", "LeftAntennae", "RightAntennae", "LeftFrontLeg", "RightFrontLeg","LeftMiddleLeg","RightMiddleLeg","LeftBackLeg","RightBackLeg"};

const QString BoxInfo::tagShow[8] = {"Head", "Neck", "LShoulder", "RShoulder", "LElbow", "RElbow", "LPalm", "RPalm"};
const QString BoxInfo::tagName[8] = {"Head", "Neck", "LShoulder", "RShoulder", "LElbow", "RElbow", "LPalm", "RPalm"};

BoxInfo::BoxInfo(int a, int b, int c, int d, QString name, int _rank, BoxesDisplay *_father):
    x1(a), y1(b), x2(c), y2(d), rank(_rank), father(_father)
{
    x1l.setText(QString::number(x1).sprintf("%03d", x1));
    y1l.setText(QString::number(y1).sprintf("%03d", y1));
    x2l.setText(QString::number(x2).sprintf("%03d", x2));
    y2l.setText(QString::number(y2).sprintf("%03d", y2));
    highlight.setText("       ");
    for (int i = 0; i < BoxInfo::tagNumber; i++) {
        if (name == BoxInfo::tagName[i]) {
            tag.setText(BoxInfo::tagShow[i]);
            break;
        }
    }
    selTag.setText(" ");
    selectButton.setText("选中");
    connect(&selectButton, SIGNAL(clicked()), this, SLOT(selected()));
    this->setLayout(&layout);
    layout.addWidget(&highlight);
    layout.addWidget(&x1l);
    layout.addWidget(&y1l);
    layout.addWidget(&x2l);
    layout.addWidget(&y2l);
    layout.addWidget(&tag);
    layout.addWidget(&selectButton);
    layout.addWidget(&selTag);
    
    QSizePolicy narrow;
    QSizePolicy wide;
    
    narrow.setHorizontalPolicy(QSizePolicy::Expanding);
    narrow.setVerticalPolicy(QSizePolicy::Fixed);
    narrow.setHorizontalStretch(40);
    
    wide.setHorizontalPolicy(QSizePolicy::Expanding);
    wide.setVerticalPolicy(QSizePolicy::Fixed);
    wide.setHorizontalStretch(60);
    
    highlight.setSizePolicy(narrow);
    x1l.setSizePolicy(narrow);
    y1l.setSizePolicy(narrow);
    x2l.setSizePolicy(narrow);
    y2l.setSizePolicy(narrow);
    tag.setSizePolicy(wide);
}

BoxInfo::~BoxInfo()
{}

void BoxInfo::focus()
{
    tag.setFocus();
}

void BoxInfo::setHighlight()
{
    //qDebug() << "setHighlight";
    if(!hl)
    {
        highlight.setText("--->");
        //tag.setFocus();
        hl = 1;
    }
    //qDebug() << "/setHighlight";
}

void BoxInfo::setUnhighlight()
{
    highlight.setText("       ");
    hl = 0;
}

void BoxInfo::setPosition(int a, int b, int c, int d)
{
    //qDebug() << a << b << c << d << " !!!!!" << endl;
    x1 = a, y1 = b, x2 = c, y2 = d;
    x1l.setText(QString::number(x1).sprintf("%03d", x1));
    y1l.setText(QString::number(y1).sprintf("%03d", y1));
    x2l.setText(QString::number(x2).sprintf("%03d", x2));
    y2l.setText(QString::number(y2).sprintf("%03d", y2));
}

int BoxInfo::getCoord(int p)
{
    switch(p)
    {
    case 0: return x1;
    case 1: return y1;
    case 2: return x2;
    case 3: return y2;
    default: return 0;
    }
}

QString BoxInfo::getTag()
{
    for (int i = 0; i < BoxInfo::tagNumber; i++) {
        if (tag.text() == BoxInfo::tagShow[i]) {
            return BoxInfo::tagName[i];
        }
    }
    return tag.text();
}

void BoxInfo::setTag(const QString& t)
{
    for (int i = 0; i < BoxInfo::tagNumber; i++) {
        if (t == BoxInfo::tagName[i]) {
            tag.setText(BoxInfo::tagShow[i]);
            return;
        }
    }
    tag.setText(t);
}

bool BoxInfo::haveHead()
{
    return tag.text() == "头部*" && (x1 | y1 | x2 | y2) != 0;
}

bool BoxInfo::haveBody()
{
    return tag.text() == "身体*" && (x1 | y1 | x2 | y2) != 0;
}

bool BoxInfo::haveWhole()
{
    return tag.text() == "全身*" && (x1 | y1 | x2 | y2) != 0;
}

void BoxInfo::selected()
{
    father->currentBox(this, rank);
}

void BoxInfo::setSelected()
{
    selTag.setText("*");
}

void BoxInfo::setUnselected()
{
    selTag.setText(" ");
}

void BoxInfo::clear()
{
    x1 = x2 = y1 = y2 = 0;
    x1l.setText(QString::number(x1).sprintf("%03d", x1));
    y1l.setText(QString::number(y1).sprintf("%03d", y1));
    x2l.setText(QString::number(x2).sprintf("%03d", x2));
    y2l.setText(QString::number(y2).sprintf("%03d", y2));
}
