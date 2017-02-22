#include "imagetagger.h"
#include "ui_imagetagger.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QString>
#include <QSizePolicy>
#include <QKeySequence>
#include <QFile>
#include <QStringList>
#include <QMessageBox>

ImageTagger::ImageTagger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageTagger)
{
    ui->setupUi(this);
    
    auto topLayout = new QVBoxLayout;
    auto upperLayout = new QHBoxLayout;
    auto buttonLayout = new QHBoxLayout;
    
    
    ui->centralWidget->setLayout(topLayout);
    topLayout->addLayout(upperLayout);
    topLayout->addLayout(buttonLayout);
    
    upperLayout->addWidget(&imgDisp);
    //upperLayout->addWidget(&boxDisp);
    
    QSizePolicy wide;
    QSizePolicy narrow;
    
    wide.setHorizontalPolicy(QSizePolicy::Expanding);
    wide.setVerticalPolicy(QSizePolicy::Expanding);
    wide.setHorizontalStretch(100);
    narrow.setHorizontalPolicy(QSizePolicy::Expanding);
    narrow.setVerticalPolicy(QSizePolicy::Expanding);
    narrow.setHorizontalStretch(60);
    
    imgDisp.setSizePolicy(wide);
    //boxDisp.setSizePolicy(narrow);
    
    buttonLayout->addWidget(&prevButton);
    buttonLayout->addWidget(&nextButton);
    buttonLayout->addWidget(&cancelButton);
    buttonLayout->addWidget(&resetButton);
    
    prevButton.setText("Last");
    resetButton.setText("Reset");
    nextButton.setText("Next");
    cancelButton.setText("Cancel");
    connect(&prevButton, SIGNAL(clicked()), this, SLOT(prevImage()));
    connect(&nextButton, SIGNAL(clicked()), this, SLOT(nextImage()));
    connect(&resetButton, SIGNAL(clicked()), this, SLOT(resetSkltn()));
    connect(&cancelButton, SIGNAL(clicked()), this, SLOT(cancelMove()));
    resetButton.setShortcut(tr("Ctrl+X"));
    cancelButton.setShortcut(tr("Ctrl+Z"));
    prevButton.setShortcut(tr("PgUp"));
    nextButton.setShortcut(tr("PgDown"));
    
    //connect(&imgDisp, SIGNAL(modifyBox(int,int,int,int)), &boxDisp, SLOT(modifyBox(int,int,int,int)));
    //connect(&imgDisp, SIGNAL(boxHighlight(int)), &boxDisp, SLOT(boxHighlight(int)));
    //connect(&imgDisp, SIGNAL(boxUnhighlight(int)), &boxDisp, SLOT(boxUnhighlight(int)));
    //connect(&boxDisp, SIGNAL(rmBox()), &imgDisp, SLOT(delBox()));
    //connect(&boxDisp, SIGNAL(selectBox(int)), &imgDisp, SLOT(selectBox(int)));

    //QStringList filters;
    //filters << "*.bmp" << "*.jpg" << "*.png";
    path.setPath(QDir::currentPath() + "/");
    qDebug() << path.path();
    QFile AllDataFile(path.path() + "/appenddata/test.txt");
    if(!AllDataFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Load failed";
        return;
    }
    QTextStream in(&AllDataFile);
    QString line = in.readLine();
    while (!line.isNull())
    {
        //qDebug() << line;
        QStringList imgData = line.split(' ');
        if (imgData.size() < 6) {
            qDebug() << "Data list format error";
        }
        int x1 = imgData[2].toInt();
        int y1 = imgData[3].toInt();
        int x2 = imgData[4].toInt();
        int y2 = imgData[5].toInt();
        FileListStruct *newfile = new FileListStruct;
        newfile->filename = imgData[0];
        newfile->classname = imgData[1];
        newfile->x1 = x1;
        newfile->y1 = y1;
        newfile->x2 = x2;
        newfile->y2 = y2;
        fileList.push_back(newfile);
        line = in.readLine();
    }
    //fileList = path.entryList(filters, QDir::Files, QDir::Name);
    qDebug() << fileList.size();
    loadImage();
}

ImageTagger::~ImageTagger()
{
    delete ui;
}

void ImageTagger::loadTags(FileListStruct *thisfile)
{
    //boxDisp.clearList();
    qDebug() << "Loading anno...";
    QFile file(path.path() + "/appenddata/annos/" + fileList[imgPtr]->filename + "_" +
               fileList[imgPtr]->classname + "_" + QString::number(fileList[imgPtr]->x1) + "_" +
               QString::number(fileList[imgPtr]->y1) + "_" + QString::number(fileList[imgPtr]->x2) +
               "_" + QString::number(fileList[imgPtr]->y2) + ".txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Load failed";
        return;
    }
    QTextStream in(&file);
    int x1, y1, x2, y2;
    QString tag;
    QString line = in.readLine().trimmed();
    while(!line.isNull())
    {
        QStringList inList = line.split(' ');
        if(inList.size() != 3)
        {
            qDebug() << "Loading: Format Error - " << fileList[imgPtr]->filename;
            break;
        }
        //qDebug() << inList;
        x1 = inList[0].toInt();
        y1 = inList[1].toInt();
        tag = inList[2];
        //qDebug() << x1 << y1 << tag;
        int tagRank = checkTag(tag);
        if (tagRank != -1) {
            //boxDisp.setCurrentBox(tag);
            //imgDisp.addBox(x1, y1, x2, y2);
            //qDebug() << tagRank;
            imgDisp.loadPoint(tagRank, x1, y1);
        }
        else {
            qDebug() << "Invalid tag: ", tag;
        }
        line = in.readLine();
    }
    qDebug() << "Load completed.";
    file.close();
}

int ImageTagger::checkTag(QString tag)
{
    for (int i = 0; i < tagNumber; i++) {
        //qDebug() << tag << tagName[i];
        if (tagName[i] == tag)
            return i;
    }
    return -1;
}


void ImageTagger::loadImage()
{
    FileListStruct *thisfile = fileList[imgPtr];
    QString name = thisfile->filename;
    img = new QImage(path.path() + "/appenddata/images/" + name + ".jpg");
    imgDisp.setImage(img, thisfile);
    loadTags(thisfile);
}

void ImageTagger::saveTags()
{
    qDebug() << "Saving tags...";
    QFile file(path.path() + "/appenddata/annos/" + fileList[imgPtr]->filename + "_" +
               fileList[imgPtr]->classname + "_" + QString::number(fileList[imgPtr]->x1) + "_" +
               QString::number(fileList[imgPtr]->y1) + "_" + QString::number(fileList[imgPtr]->x2) +
               "_" + QString::number(fileList[imgPtr]->y2) + ".txt");
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Save failed";
        return;
    }
    QTextStream stream(&file);
    imgDisp.WritePoint(stream);
}

void ImageTagger::prevImage()
{
    saveTags();
    if(imgPtr > 0)
    {
        imgPtr--;
        loadImage();
    }
}

void ImageTagger::nextImage()
{
    saveTags();
    if(imgPtr < (fileList.size() - 1))
    {
        imgPtr++;
        loadImage();
    }
}

void ImageTagger::resetSkltn()
{
    imgDisp.Reset();
}

void ImageTagger::cancelMove()
{
    imgDisp.Cancel();
}



