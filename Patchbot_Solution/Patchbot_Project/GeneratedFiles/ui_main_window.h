/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *colonyName;
    QPushButton *loadColony;
    QGridLayout *gameWindow;
    QLabel *placeHolder;
    QScrollBar *xScrollbar;
    QScrollBar *yScrollbar;
    QGridLayout *gameProgramming;
    QVBoxLayout *currentProgramLayout;
    QLabel *label;
    QScrollBar *horizontalScrollBar;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QGridLayout *missionControlLayout;
    QLabel *staticLabel1;
    QPushButton *missionStart;
    QPushButton *missionCancel;
    QPushButton *missionStep;
    QPushButton *missionAutomatic;
    QPushButton *missionStop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(main_window->sizePolicy().hasHeightForWidth());
        main_window->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(main_window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 771, 521));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        colonyName = new QLabel(widget);
        colonyName->setObjectName(QStringLiteral("colonyName"));

        gridLayout_2->addWidget(colonyName, 0, 0, 1, 1);

        loadColony = new QPushButton(widget);
        loadColony->setObjectName(QStringLiteral("loadColony"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loadColony->sizePolicy().hasHeightForWidth());
        loadColony->setSizePolicy(sizePolicy1);
        loadColony->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(loadColony, 0, 1, 1, 1);

        gameWindow = new QGridLayout();
        gameWindow->setSpacing(6);
        gameWindow->setObjectName(QStringLiteral("gameWindow"));
        placeHolder = new QLabel(widget);
        placeHolder->setObjectName(QStringLiteral("placeHolder"));
        placeHolder->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(placeHolder->sizePolicy().hasHeightForWidth());
        placeHolder->setSizePolicy(sizePolicy2);
        placeHolder->setMinimumSize(QSize(400, 400));

        gameWindow->addWidget(placeHolder, 0, 0, 1, 1);

        xScrollbar = new QScrollBar(widget);
        xScrollbar->setObjectName(QStringLiteral("xScrollbar"));
        sizePolicy2.setHeightForWidth(xScrollbar->sizePolicy().hasHeightForWidth());
        xScrollbar->setSizePolicy(sizePolicy2);
        xScrollbar->setMinimumSize(QSize(300, 10));
        xScrollbar->setOrientation(Qt::Horizontal);

        gameWindow->addWidget(xScrollbar, 1, 0, 1, 1);

        yScrollbar = new QScrollBar(widget);
        yScrollbar->setObjectName(QStringLiteral("yScrollbar"));
        yScrollbar->setOrientation(Qt::Vertical);

        gameWindow->addWidget(yScrollbar, 0, 1, 1, 1);


        gridLayout_2->addLayout(gameWindow, 1, 0, 2, 1);

        gameProgramming = new QGridLayout();
        gameProgramming->setSpacing(6);
        gameProgramming->setObjectName(QStringLiteral("gameProgramming"));
        currentProgramLayout = new QVBoxLayout();
        currentProgramLayout->setSpacing(6);
        currentProgramLayout->setObjectName(QStringLiteral("currentProgramLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        currentProgramLayout->addWidget(label);

        horizontalScrollBar = new QScrollBar(widget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        currentProgramLayout->addWidget(horizontalScrollBar);


        gameProgramming->addLayout(currentProgramLayout, 3, 3, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gameProgramming->addWidget(comboBox, 1, 3, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gameProgramming->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gameProgramming->addWidget(pushButton_4, 2, 2, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gameProgramming->addWidget(pushButton_3, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gameProgramming->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gameProgramming->addWidget(pushButton_2, 3, 1, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gameProgramming->addWidget(pushButton, 2, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gameProgramming->addWidget(label_2, 0, 0, 1, 4);


        gridLayout_2->addLayout(gameProgramming, 1, 1, 1, 1);

        missionControlLayout = new QGridLayout();
        missionControlLayout->setSpacing(6);
        missionControlLayout->setObjectName(QStringLiteral("missionControlLayout"));
        missionControlLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticLabel1 = new QLabel(widget);
        staticLabel1->setObjectName(QStringLiteral("staticLabel1"));

        missionControlLayout->addWidget(staticLabel1, 0, 0, 1, 2);

        missionStart = new QPushButton(widget);
        missionStart->setObjectName(QStringLiteral("missionStart"));

        missionControlLayout->addWidget(missionStart, 1, 0, 1, 1);

        missionCancel = new QPushButton(widget);
        missionCancel->setObjectName(QStringLiteral("missionCancel"));

        missionControlLayout->addWidget(missionCancel, 1, 1, 1, 1);

        missionStep = new QPushButton(widget);
        missionStep->setObjectName(QStringLiteral("missionStep"));

        missionControlLayout->addWidget(missionStep, 2, 0, 1, 1);

        missionAutomatic = new QPushButton(widget);
        missionAutomatic->setObjectName(QStringLiteral("missionAutomatic"));

        missionControlLayout->addWidget(missionAutomatic, 2, 1, 1, 1);

        missionStop = new QPushButton(widget);
        missionStop->setObjectName(QStringLiteral("missionStop"));

        missionControlLayout->addWidget(missionStop, 3, 1, 1, 1);


        gridLayout_2->addLayout(missionControlLayout, 2, 1, 1, 1);

        main_window->setCentralWidget(centralWidget);
        xScrollbar->raise();
        yScrollbar->raise();
        placeHolder->raise();
        placeHolder->raise();
        staticLabel1->raise();
        missionStart->raise();
        missionCancel->raise();
        missionStep->raise();
        missionAutomatic->raise();
        missionStop->raise();
        horizontalScrollBar->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        label_2->raise();
        comboBox->raise();
        label_2->raise();
        loadColony->raise();
        colonyName->raise();
        menuBar = new QMenuBar(main_window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        main_window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(main_window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        main_window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(main_window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        main_window->setStatusBar(statusBar);

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QMainWindow *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "main_window", Q_NULLPTR));
        colonyName->setText(QApplication::translate("main_window", "TextLabel", Q_NULLPTR));
        loadColony->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        placeHolder->setText(QApplication::translate("main_window", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("main_window", "TextLabel", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        label_2->setText(QApplication::translate("main_window", "TextLabel", Q_NULLPTR));
        staticLabel1->setText(QApplication::translate("main_window", "TextLabel", Q_NULLPTR));
        missionStart->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        missionCancel->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        missionStep->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        missionAutomatic->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
        missionStop->setText(QApplication::translate("main_window", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
