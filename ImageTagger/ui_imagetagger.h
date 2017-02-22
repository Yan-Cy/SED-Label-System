/********************************************************************************
** Form generated from reading UI file 'imagetagger.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGETAGGER_H
#define UI_IMAGETAGGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageTagger
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageTagger)
    {
        if (ImageTagger->objectName().isEmpty())
            ImageTagger->setObjectName(QStringLiteral("ImageTagger"));
        ImageTagger->resize(877, 710);
        centralWidget = new QWidget(ImageTagger);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ImageTagger->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageTagger);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 877, 22));
        ImageTagger->setMenuBar(menuBar);
        statusBar = new QStatusBar(ImageTagger);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImageTagger->setStatusBar(statusBar);

        retranslateUi(ImageTagger);

        QMetaObject::connectSlotsByName(ImageTagger);
    } // setupUi

    void retranslateUi(QMainWindow *ImageTagger)
    {
        ImageTagger->setWindowTitle(QApplication::translate("ImageTagger", "ImageTagger", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageTagger: public Ui_ImageTagger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGETAGGER_H
