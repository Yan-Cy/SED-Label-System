#include "imagetagger.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageTagger w;
    w.show();
    
    return a.exec();
}
