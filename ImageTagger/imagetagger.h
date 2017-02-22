#ifndef IMAGETAGGER_H
#define IMAGETAGGER_H

#include "imagedisplay.h"
#include "structs.h"

#include <QMainWindow>
#include <QWidget>
#include <QImage>
#include <QPushButton>
#include <QDir>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <vector>

using namespace std;

namespace Ui {
class ImageTagger;
}

class ImageTagger : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ImageTagger(QWidget *parent = 0);
    ~ImageTagger();
    
private:
    Ui::ImageTagger *ui;
    QImage* img;
    QPushButton prevButton, nextButton, cancelButton, resetButton;
    ImageDisplay imgDisp;
    //BoxesDisplay boxDisp;
    vector<FileListStruct *> fileList;
    QDir path;
    
    int imgPtr = 0;
    
    int tagNumber = 8;
    QString tagName[8] = {"Head", "Neck", "LShoulder", "RShoulder", "LElbow", "RElbow", "LPalm", "RPalm"};


    void loadTags(FileListStruct *thisfile);
    void loadImage();
    int checkTag(QString tag);
    
private slots:
    void saveTags();
    void resetSkltn();
    void prevImage();
    void nextImage();
    void cancelMove();
};

#endif // IMAGETAGGER_H
