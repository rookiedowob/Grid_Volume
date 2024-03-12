/********************************************************************************
** Form generated from reading UI file 'DSI_Debug.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSI_DEBUG_H
#define UI_DSI_DEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DSI_DebugClass
{
public:
    QAction *open;
    QAction *showmodel;
    QAction *close;
    QAction *clear;
    QAction *ConvexPack;
    QAction *GridsView;
    QAction *actionisinpoly;
    QAction *actionIDW;
    QAction *action2;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *label6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLabel *label7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFILE;
    QMenu *menuHELP;
    QMenu *menu;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DSI_DebugClass)
    {
        if (DSI_DebugClass->objectName().isEmpty())
            DSI_DebugClass->setObjectName(QStringLiteral("DSI_DebugClass"));
        DSI_DebugClass->resize(1931, 835);
        DSI_DebugClass->setMouseTracking(true);
        DSI_DebugClass->setUnifiedTitleAndToolBarOnMac(false);
        open = new QAction(DSI_DebugClass);
        open->setObjectName(QStringLiteral("open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon/\345\233\276\345\261\202 6.png"), QSize(), QIcon::Normal, QIcon::Off);
        open->setIcon(icon);
        showmodel = new QAction(DSI_DebugClass);
        showmodel->setObjectName(QStringLiteral("showmodel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icon/\345\233\276\345\261\202 4.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral("C:/Users/lenovo/Desktop/meshlab.png"), QSize(), QIcon::Normal, QIcon::On);
        showmodel->setIcon(icon1);
        close = new QAction(DSI_DebugClass);
        close->setObjectName(QStringLiteral("close"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icon/\345\233\276\345\261\202 8.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon2);
        clear = new QAction(DSI_DebugClass);
        clear->setObjectName(QStringLiteral("clear"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icon/\345\233\276\345\261\202 3.png"), QSize(), QIcon::Normal, QIcon::Off);
        clear->setIcon(icon3);
        ConvexPack = new QAction(DSI_DebugClass);
        ConvexPack->setObjectName(QStringLiteral("ConvexPack"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icon/\345\233\276\345\261\202 1.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConvexPack->setIcon(icon4);
        GridsView = new QAction(DSI_DebugClass);
        GridsView->setObjectName(QStringLiteral("GridsView"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icon/\345\233\276\345\261\202 2.png"), QSize(), QIcon::Normal, QIcon::Off);
        GridsView->setIcon(icon5);
        actionisinpoly = new QAction(DSI_DebugClass);
        actionisinpoly->setObjectName(QStringLiteral("actionisinpoly"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("icon/\345\233\276\345\261\202 5.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionisinpoly->setIcon(icon6);
        actionIDW = new QAction(DSI_DebugClass);
        actionIDW->setObjectName(QStringLiteral("actionIDW"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("icon/\345\233\276\345\261\202 0.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIDW->setIcon(icon7);
        action2 = new QAction(DSI_DebugClass);
        action2->setObjectName(QStringLiteral("action2"));
        centralWidget = new QWidget(DSI_DebugClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(320, 40, 1404, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setContentsMargins(12, 12, 12, 12);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("SimSun-ExtB"));
        font.setPointSize(15);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        label4 = new QLabel(layoutWidget);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setFont(font);

        horizontalLayout_2->addWidget(label4);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        label6 = new QLabel(layoutWidget);
        label6->setObjectName(QStringLiteral("label6"));
        label6->setFont(font);

        horizontalLayout_3->addWidget(label6);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        label7 = new QLabel(layoutWidget);
        label7->setObjectName(QStringLiteral("label7"));
        label7->setFont(font);

        horizontalLayout_5->addWidget(label7);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);


        horizontalLayout_4->addLayout(horizontalLayout);

        DSI_DebugClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DSI_DebugClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1931, 26));
        menuFILE = new QMenu(menuBar);
        menuFILE->setObjectName(QStringLiteral("menuFILE"));
        menuHELP = new QMenu(menuBar);
        menuHELP->setObjectName(QStringLiteral("menuHELP"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        DSI_DebugClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(DSI_DebugClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DSI_DebugClass->setStatusBar(statusBar);
        toolBar = new QToolBar(DSI_DebugClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        DSI_DebugClass->addToolBar(Qt::LeftToolBarArea, toolBar);

        menuBar->addAction(menuFILE->menuAction());
        menuBar->addAction(menuHELP->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFILE->addAction(open);
        menuFILE->addAction(close);
        menuHELP->addAction(clear);
        menu->addAction(ConvexPack);
        menu->addAction(GridsView);
        menu->addAction(actionisinpoly);
        menu->addAction(actionIDW);
        menu->addAction(showmodel);
        menu->addAction(action2);
        toolBar->addAction(open);
        toolBar->addAction(clear);
        toolBar->addSeparator();
        toolBar->addAction(ConvexPack);
        toolBar->addAction(GridsView);
        toolBar->addAction(actionisinpoly);
        toolBar->addSeparator();
        toolBar->addAction(actionIDW);
        toolBar->addAction(showmodel);
        toolBar->addSeparator();
        toolBar->addAction(close);
        toolBar->addSeparator();

        retranslateUi(DSI_DebugClass);

        QMetaObject::connectSlotsByName(DSI_DebugClass);
    } // setupUi

    void retranslateUi(QMainWindow *DSI_DebugClass)
    {
        DSI_DebugClass->setWindowTitle(QApplication::translate("DSI_DebugClass", "\346\240\274\345\210\231\346\240\274\347\275\221\350\256\241\347\256\227\344\275\223\347\247\257", Q_NULLPTR));
        open->setText(QApplication::translate("DSI_DebugClass", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        showmodel->setText(QApplication::translate("DSI_DebugClass", "\345\261\225\347\244\272\344\270\211\347\273\264\346\250\241\345\236\213", Q_NULLPTR));
        close->setText(QApplication::translate("DSI_DebugClass", "\351\200\200\345\207\272\347\250\213\345\272\217", Q_NULLPTR));
        clear->setText(QApplication::translate("DSI_DebugClass", "\346\270\205\347\251\272", Q_NULLPTR));
        ConvexPack->setText(QApplication::translate("DSI_DebugClass", "\347\273\230\345\210\266\345\207\270\345\214\205", Q_NULLPTR));
        GridsView->setText(QApplication::translate("DSI_DebugClass", "\346\230\276\347\244\272\350\247\204\345\210\231\346\240\274\347\275\221", Q_NULLPTR));
        actionisinpoly->setText(QApplication::translate("DSI_DebugClass", "\345\210\244\346\226\255\347\202\271\345\234\250\345\244\232\350\276\271\345\275\242\345\206\205", Q_NULLPTR));
        actionIDW->setText(QApplication::translate("DSI_DebugClass", "\345\217\215\350\267\235\347\246\273\345\212\240\346\235\203\346\217\222\345\200\274", Q_NULLPTR));
        action2->setText(QApplication::translate("DSI_DebugClass", "\345\212\240\345\257\206\347\275\221\346\240\274", Q_NULLPTR));
        label_3->setText(QApplication::translate("DSI_DebugClass", "\350\247\204\345\210\231\346\240\274\347\275\221\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label4->setText(QString());
        label_5->setText(QApplication::translate("DSI_DebugClass", "      \346\216\247\345\210\266\347\202\271\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label6->setText(QString());
        label_6->setText(QApplication::translate("DSI_DebugClass", "      \345\234\250\345\207\270\345\214\205\345\206\205\347\232\204\350\247\204\345\210\231\346\240\274\347\275\221\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label7->setText(QString());
        label_2->setText(QApplication::translate("DSI_DebugClass", "      \344\275\223\347\247\257\357\274\232", Q_NULLPTR));
        label->setText(QString());
        menuFILE->setTitle(QApplication::translate("DSI_DebugClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menuHELP->setTitle(QApplication::translate("DSI_DebugClass", "\347\274\226\350\276\221", Q_NULLPTR));
        menu->setTitle(QApplication::translate("DSI_DebugClass", "\345\261\225\347\244\272", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("DSI_DebugClass", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DSI_DebugClass: public Ui_DSI_DebugClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSI_DEBUG_H
