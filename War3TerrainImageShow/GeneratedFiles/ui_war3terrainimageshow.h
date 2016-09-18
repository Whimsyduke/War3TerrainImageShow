/********************************************************************************
** Form generated from reading UI file 'war3terrainimageshow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAR3TERRAINIMAGESHOW_H
#define UI_WAR3TERRAINIMAGESHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_War3TerrainImageShowClass
{
public:
    QAction *Action_SingleTerrain;
    QAction *Action_ALLTerrain;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGraphicsView *graphicsView;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_SingleTerrain;
    QMenu *menu_AllTerrain;
    QToolBar *toolBar;

    void setupUi(QMainWindow *War3TerrainImageShowClass)
    {
        if (War3TerrainImageShowClass->objectName().isEmpty())
            War3TerrainImageShowClass->setObjectName(QStringLiteral("War3TerrainImageShowClass"));
        War3TerrainImageShowClass->resize(1366, 768);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(War3TerrainImageShowClass->sizePolicy().hasHeightForWidth());
        War3TerrainImageShowClass->setSizePolicy(sizePolicy);
        Action_SingleTerrain = new QAction(War3TerrainImageShowClass);
        Action_SingleTerrain->setObjectName(QStringLiteral("Action_SingleTerrain"));
        Action_ALLTerrain = new QAction(War3TerrainImageShowClass);
        Action_ALLTerrain->setObjectName(QStringLiteral("Action_ALLTerrain"));
        centralWidget = new QWidget(War3TerrainImageShowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_3->addWidget(graphicsView, 0, 0, 1, 1);

        War3TerrainImageShowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(War3TerrainImageShowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        War3TerrainImageShowClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(War3TerrainImageShowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1366, 37));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_SingleTerrain = new QMenu(menuBar);
        menu_SingleTerrain->setObjectName(QStringLiteral("menu_SingleTerrain"));
        menu_AllTerrain = new QMenu(menuBar);
        menu_AllTerrain->setObjectName(QStringLiteral("menu_AllTerrain"));
        War3TerrainImageShowClass->setMenuBar(menuBar);
        toolBar = new QToolBar(War3TerrainImageShowClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMinimumSize(QSize(1366, 50));
        toolBar->setMaximumSize(QSize(1366, 50));
        War3TerrainImageShowClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_SingleTerrain->menuAction());
        menuBar->addAction(menu_AllTerrain->menuAction());
        toolBar->addAction(Action_SingleTerrain);
        toolBar->addAction(Action_ALLTerrain);

        retranslateUi(War3TerrainImageShowClass);

        QMetaObject::connectSlotsByName(War3TerrainImageShowClass);
    } // setupUi

    void retranslateUi(QMainWindow *War3TerrainImageShowClass)
    {
        War3TerrainImageShowClass->setWindowTitle(QApplication::translate("War3TerrainImageShowClass", "War3TerrainImageShow", 0));
        Action_SingleTerrain->setText(QApplication::translate("War3TerrainImageShowClass", "\345\215\225\345\235\227\347\272\271\347\220\206", 0));
#ifndef QT_NO_TOOLTIP
        Action_SingleTerrain->setToolTip(QApplication::translate("War3TerrainImageShowClass", "<html><head/><body><p>\345\244\204\347\220\206\345\215\225\347\213\254\347\232\204\344\270\200\345\235\227\347\272\271\347\220\206\347\233\264\345\210\260\345\256\214\346\210\220</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Action_SingleTerrain->setShortcut(QApplication::translate("War3TerrainImageShowClass", "1", 0));
        Action_ALLTerrain->setText(QApplication::translate("War3TerrainImageShowClass", "\345\205\250\351\203\250\347\272\271\347\220\206", 0));
#ifndef QT_NO_TOOLTIP
        Action_ALLTerrain->setToolTip(QApplication::translate("War3TerrainImageShowClass", "<html><head/><body><p>\345\244\204\347\220\206\345\211\251\344\275\231\347\232\204\345\205\250\351\203\250\347\272\271\347\220\206\343\200\202</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Action_ALLTerrain->setShortcut(QApplication::translate("War3TerrainImageShowClass", "2", 0));
        menu->setTitle(QApplication::translate("War3TerrainImageShowClass", "\346\226\207\344\273\266", 0));
        menu_SingleTerrain->setTitle(QApplication::translate("War3TerrainImageShowClass", "\345\215\225\345\235\227\347\272\271\347\220\206", 0));
        menu_AllTerrain->setTitle(QApplication::translate("War3TerrainImageShowClass", "\345\205\250\351\203\250\347\272\271\347\220\206", 0));
        toolBar->setWindowTitle(QApplication::translate("War3TerrainImageShowClass", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class War3TerrainImageShowClass: public Ui_War3TerrainImageShowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAR3TERRAINIMAGESHOW_H
