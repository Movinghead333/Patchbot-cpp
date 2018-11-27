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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *loadColony;
    QGridLayout *gameProgramming;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QVBoxLayout *currentProgramLayout;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineEdit;
    QScrollBar *horizontalScrollBar;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *missionControlLayout;
    QPushButton *missionStop;
    QPushButton *missionStart;
    QPushButton *missionStep;
    QPushButton *missionAutomatic;
    QPushButton *missionCancel;
    QLabel *staticLabel1;
    QGridLayout *gameWindow;
    QScrollBar *yScrollbar;
    QLabel *placeHolder;
    QScrollBar *xScrollbar;
    QLabel *colonyName;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->resize(816, 644);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(main_window->sizePolicy().hasHeightForWidth());
        main_window->setSizePolicy(sizePolicy);
        main_window->setMinimumSize(QSize(800, 600));
        centralWidget = new QWidget(main_window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loadColony = new QPushButton(centralWidget);
        loadColony->setObjectName(QStringLiteral("loadColony"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loadColony->sizePolicy().hasHeightForWidth());
        loadColony->setSizePolicy(sizePolicy1);
        loadColony->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(loadColony, 0, 1, 1, 1, Qt::AlignRight);

        gameProgramming = new QGridLayout();
        gameProgramming->setSpacing(6);
        gameProgramming->setObjectName(QStringLiteral("gameProgramming"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(40, 40));
        pushButton_2->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(pushButton_2, 3, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(40, 40));
        pushButton_3->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(pushButton_3, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(40, 40));
        pushButton_6->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(pushButton_6, 1, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gameProgramming->addWidget(label_2, 0, 0, 1, 5);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(40, 40));
        pushButton_5->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(pushButton_5, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gameProgramming->addItem(horizontalSpacer, 1, 3, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(50, 30));
        comboBox->setMaximumSize(QSize(500, 30));

        gameProgramming->addWidget(comboBox, 1, 4, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(40, 40));
        pushButton->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(pushButton, 2, 0, 1, 1);

        currentProgramLayout = new QVBoxLayout();
        currentProgramLayout->setSpacing(0);
        currentProgramLayout->setObjectName(QStringLiteral("currentProgramLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        currentProgramLayout->addItem(verticalSpacer_3);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(80, 30));
        lineEdit->setReadOnly(true);

        currentProgramLayout->addWidget(lineEdit);

        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setMinimumSize(QSize(0, 17));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        currentProgramLayout->addWidget(horizontalScrollBar);


        gameProgramming->addLayout(currentProgramLayout, 2, 4, 2, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(40, 40));
        pushButton_4->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(pushButton_4, 2, 2, 1, 1);


        gridLayout->addLayout(gameProgramming, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        missionControlLayout = new QGridLayout();
        missionControlLayout->setSpacing(6);
        missionControlLayout->setObjectName(QStringLiteral("missionControlLayout"));
        missionControlLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        missionStop = new QPushButton(centralWidget);
        missionStop->setObjectName(QStringLiteral("missionStop"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(missionStop->sizePolicy().hasHeightForWidth());
        missionStop->setSizePolicy(sizePolicy3);
        missionStop->setMinimumSize(QSize(130, 40));
        missionStop->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(8);
        missionStop->setFont(font1);

        missionControlLayout->addWidget(missionStop, 3, 1, 1, 1);

        missionStart = new QPushButton(centralWidget);
        missionStart->setObjectName(QStringLiteral("missionStart"));
        sizePolicy3.setHeightForWidth(missionStart->sizePolicy().hasHeightForWidth());
        missionStart->setSizePolicy(sizePolicy3);
        missionStart->setMinimumSize(QSize(130, 40));
        missionStart->setMaximumSize(QSize(16777215, 50));
        missionStart->setFont(font1);

        missionControlLayout->addWidget(missionStart, 1, 0, 1, 1);

        missionStep = new QPushButton(centralWidget);
        missionStep->setObjectName(QStringLiteral("missionStep"));
        sizePolicy3.setHeightForWidth(missionStep->sizePolicy().hasHeightForWidth());
        missionStep->setSizePolicy(sizePolicy3);
        missionStep->setMinimumSize(QSize(130, 40));
        missionStep->setMaximumSize(QSize(16777215, 50));
        missionStep->setFont(font1);

        missionControlLayout->addWidget(missionStep, 2, 0, 1, 1);

        missionAutomatic = new QPushButton(centralWidget);
        missionAutomatic->setObjectName(QStringLiteral("missionAutomatic"));
        sizePolicy3.setHeightForWidth(missionAutomatic->sizePolicy().hasHeightForWidth());
        missionAutomatic->setSizePolicy(sizePolicy3);
        missionAutomatic->setMinimumSize(QSize(130, 40));
        missionAutomatic->setMaximumSize(QSize(16777215, 50));
        missionAutomatic->setFont(font1);

        missionControlLayout->addWidget(missionAutomatic, 2, 1, 1, 1);

        missionCancel = new QPushButton(centralWidget);
        missionCancel->setObjectName(QStringLiteral("missionCancel"));
        sizePolicy3.setHeightForWidth(missionCancel->sizePolicy().hasHeightForWidth());
        missionCancel->setSizePolicy(sizePolicy3);
        missionCancel->setMinimumSize(QSize(130, 40));
        missionCancel->setMaximumSize(QSize(16777215, 50));
        missionCancel->setFont(font1);

        missionControlLayout->addWidget(missionCancel, 1, 1, 1, 1);

        staticLabel1 = new QLabel(centralWidget);
        staticLabel1->setObjectName(QStringLiteral("staticLabel1"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(staticLabel1->sizePolicy().hasHeightForWidth());
        staticLabel1->setSizePolicy(sizePolicy4);
        staticLabel1->setMinimumSize(QSize(0, 30));
        staticLabel1->setMaximumSize(QSize(16777215, 30));
        staticLabel1->setFont(font);
        staticLabel1->setAlignment(Qt::AlignCenter);

        missionControlLayout->addWidget(staticLabel1, 0, 0, 1, 2);


        gridLayout->addLayout(missionControlLayout, 3, 1, 1, 1);

        gameWindow = new QGridLayout();
        gameWindow->setSpacing(6);
        gameWindow->setObjectName(QStringLiteral("gameWindow"));
        gameWindow->setContentsMargins(20, -1, 20, -1);
        yScrollbar = new QScrollBar(centralWidget);
        yScrollbar->setObjectName(QStringLiteral("yScrollbar"));
        yScrollbar->setOrientation(Qt::Vertical);

        gameWindow->addWidget(yScrollbar, 0, 1, 1, 1);

        placeHolder = new QLabel(centralWidget);
        placeHolder->setObjectName(QStringLiteral("placeHolder"));
        placeHolder->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(placeHolder->sizePolicy().hasHeightForWidth());
        placeHolder->setSizePolicy(sizePolicy5);
        placeHolder->setMinimumSize(QSize(0, 0));

        gameWindow->addWidget(placeHolder, 0, 0, 1, 1);

        xScrollbar = new QScrollBar(centralWidget);
        xScrollbar->setObjectName(QStringLiteral("xScrollbar"));
        sizePolicy1.setHeightForWidth(xScrollbar->sizePolicy().hasHeightForWidth());
        xScrollbar->setSizePolicy(sizePolicy1);
        xScrollbar->setMinimumSize(QSize(0, 0));
        xScrollbar->setOrientation(Qt::Horizontal);

        gameWindow->addWidget(xScrollbar, 1, 0, 1, 1);


        gridLayout->addLayout(gameWindow, 1, 0, 4, 1);

        colonyName = new QLabel(centralWidget);
        colonyName->setObjectName(QStringLiteral("colonyName"));

        gridLayout->addWidget(colonyName, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 80);
        gridLayout->setColumnStretch(1, 20);
        main_window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(main_window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 816, 21));
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
        loadColony->setText(QApplication::translate("main_window", "Andere Kolonie...", Q_NULLPTR));
        pushButton_2->setText(QString());
        pushButton_3->setText(QApplication::translate("main_window", "W", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("main_window", "<-", Q_NULLPTR));
        label_2->setText(QApplication::translate("main_window", "Programmieren", Q_NULLPTR));
        pushButton_5->setText(QString());
        pushButton->setText(QString());
        lineEdit->setText(QApplication::translate("main_window", "W8W8W8", Q_NULLPTR));
        pushButton_4->setText(QString());
        missionStop->setText(QApplication::translate("main_window", "Anhalten", Q_NULLPTR));
        missionStart->setText(QApplication::translate("main_window", "Start", Q_NULLPTR));
        missionStep->setText(QApplication::translate("main_window", "Einzelschritt", Q_NULLPTR));
        missionAutomatic->setText(QApplication::translate("main_window", "Automatik", Q_NULLPTR));
        missionCancel->setText(QApplication::translate("main_window", "Abbruch", Q_NULLPTR));
        staticLabel1->setText(QApplication::translate("main_window", "Missionsablauf", Q_NULLPTR));
        placeHolder->setText(QApplication::translate("main_window", "-- gamescreen --", Q_NULLPTR));
        colonyName->setText(QApplication::translate("main_window", "Aktuelle Kolonie:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
