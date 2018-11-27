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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *changeColony;
    QGridLayout *gameProgramming;
    QPushButton *directionDown;
    QPushButton *playerWait;
    QPushButton *removeCommand;
    QLabel *staticProgramText;
    QPushButton *directionUp;
    QSpacerItem *horizontalSpacer;
    QComboBox *repititionComboBox;
    QPushButton *directionLeft;
    QVBoxLayout *currentProgramLayout;
    QSpacerItem *programmDisplaySpacer;
    QLineEdit *currentProgramText;
    QScrollBar *scrollProgram;
    QPushButton *directionRight;
    QSpacerItem *programMissionSpacer;
    QGridLayout *missionControlLayout;
    QPushButton *missionPause;
    QPushButton *missionStart;
    QPushButton *missionStep;
    QPushButton *missionAutomatic;
    QPushButton *missionCancel;
    QLabel *staticMissionText;
    QGridLayout *gameWindow;
    QScrollBar *yScrollbar;
    QLabel *placeHolder;
    QScrollBar *xScrollbar;
    QLabel *colonyName;

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
        changeColony = new QPushButton(centralWidget);
        changeColony->setObjectName(QStringLiteral("changeColony"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(changeColony->sizePolicy().hasHeightForWidth());
        changeColony->setSizePolicy(sizePolicy1);
        changeColony->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(changeColony, 0, 1, 1, 1, Qt::AlignRight);

        gameProgramming = new QGridLayout();
        gameProgramming->setSpacing(6);
        gameProgramming->setObjectName(QStringLiteral("gameProgramming"));
        directionDown = new QPushButton(centralWidget);
        directionDown->setObjectName(QStringLiteral("directionDown"));
        directionDown->setMinimumSize(QSize(40, 40));
        directionDown->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(directionDown, 3, 1, 1, 1);

        playerWait = new QPushButton(centralWidget);
        playerWait->setObjectName(QStringLiteral("playerWait"));
        playerWait->setMinimumSize(QSize(40, 40));
        playerWait->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(playerWait, 2, 1, 1, 1);

        removeCommand = new QPushButton(centralWidget);
        removeCommand->setObjectName(QStringLiteral("removeCommand"));
        removeCommand->setMinimumSize(QSize(40, 40));
        removeCommand->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(removeCommand, 1, 2, 1, 1);

        staticProgramText = new QLabel(centralWidget);
        staticProgramText->setObjectName(QStringLiteral("staticProgramText"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(staticProgramText->sizePolicy().hasHeightForWidth());
        staticProgramText->setSizePolicy(sizePolicy2);
        staticProgramText->setMinimumSize(QSize(0, 30));
        staticProgramText->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(10);
        staticProgramText->setFont(font);
        staticProgramText->setAlignment(Qt::AlignCenter);

        gameProgramming->addWidget(staticProgramText, 0, 0, 1, 5);

        directionUp = new QPushButton(centralWidget);
        directionUp->setObjectName(QStringLiteral("directionUp"));
        directionUp->setMinimumSize(QSize(40, 40));
        directionUp->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(directionUp, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gameProgramming->addItem(horizontalSpacer, 1, 3, 1, 1);

        repititionComboBox = new QComboBox(centralWidget);
        repititionComboBox->setObjectName(QStringLiteral("repititionComboBox"));
        sizePolicy1.setHeightForWidth(repititionComboBox->sizePolicy().hasHeightForWidth());
        repititionComboBox->setSizePolicy(sizePolicy1);
        repititionComboBox->setMinimumSize(QSize(50, 30));
        repititionComboBox->setMaximumSize(QSize(16777215, 30));
        repititionComboBox->setEditable(false);

        gameProgramming->addWidget(repititionComboBox, 1, 4, 1, 1);

        directionLeft = new QPushButton(centralWidget);
        directionLeft->setObjectName(QStringLiteral("directionLeft"));
        sizePolicy1.setHeightForWidth(directionLeft->sizePolicy().hasHeightForWidth());
        directionLeft->setSizePolicy(sizePolicy1);
        directionLeft->setMinimumSize(QSize(40, 40));
        directionLeft->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(directionLeft, 2, 0, 1, 1);

        currentProgramLayout = new QVBoxLayout();
        currentProgramLayout->setSpacing(0);
        currentProgramLayout->setObjectName(QStringLiteral("currentProgramLayout"));
        programmDisplaySpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        currentProgramLayout->addItem(programmDisplaySpacer);

        currentProgramText = new QLineEdit(centralWidget);
        currentProgramText->setObjectName(QStringLiteral("currentProgramText"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(currentProgramText->sizePolicy().hasHeightForWidth());
        currentProgramText->setSizePolicy(sizePolicy3);
        currentProgramText->setMinimumSize(QSize(80, 40));
        currentProgramText->setMaximumSize(QSize(16777215, 40));
        QPalette palette;
        QBrush brush(QColor(66, 136, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(0, 170, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        currentProgramText->setPalette(palette);
        QFont font1;
        font1.setUnderline(false);
        font1.setKerning(true);
        currentProgramText->setFont(font1);
        currentProgramText->setReadOnly(true);

        currentProgramLayout->addWidget(currentProgramText);

        scrollProgram = new QScrollBar(centralWidget);
        scrollProgram->setObjectName(QStringLiteral("scrollProgram"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollProgram->sizePolicy().hasHeightForWidth());
        scrollProgram->setSizePolicy(sizePolicy4);
        scrollProgram->setMinimumSize(QSize(0, 20));
        scrollProgram->setMaximumSize(QSize(16777215, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        scrollProgram->setPalette(palette1);
        scrollProgram->setFont(font1);
        scrollProgram->setOrientation(Qt::Horizontal);

        currentProgramLayout->addWidget(scrollProgram);


        gameProgramming->addLayout(currentProgramLayout, 2, 4, 2, 1);

        directionRight = new QPushButton(centralWidget);
        directionRight->setObjectName(QStringLiteral("directionRight"));
        directionRight->setMinimumSize(QSize(40, 40));
        directionRight->setMaximumSize(QSize(40, 40));

        gameProgramming->addWidget(directionRight, 2, 2, 1, 1);


        gridLayout->addLayout(gameProgramming, 1, 1, 1, 1);

        programMissionSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(programMissionSpacer, 2, 1, 1, 1);

        missionControlLayout = new QGridLayout();
        missionControlLayout->setSpacing(6);
        missionControlLayout->setObjectName(QStringLiteral("missionControlLayout"));
        missionControlLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        missionPause = new QPushButton(centralWidget);
        missionPause->setObjectName(QStringLiteral("missionPause"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(missionPause->sizePolicy().hasHeightForWidth());
        missionPause->setSizePolicy(sizePolicy5);
        missionPause->setMinimumSize(QSize(130, 40));
        missionPause->setMaximumSize(QSize(16777215, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(8);
        missionPause->setFont(font2);

        missionControlLayout->addWidget(missionPause, 3, 1, 1, 1);

        missionStart = new QPushButton(centralWidget);
        missionStart->setObjectName(QStringLiteral("missionStart"));
        sizePolicy5.setHeightForWidth(missionStart->sizePolicy().hasHeightForWidth());
        missionStart->setSizePolicy(sizePolicy5);
        missionStart->setMinimumSize(QSize(130, 40));
        missionStart->setMaximumSize(QSize(16777215, 50));
        missionStart->setFont(font2);

        missionControlLayout->addWidget(missionStart, 1, 0, 1, 1);

        missionStep = new QPushButton(centralWidget);
        missionStep->setObjectName(QStringLiteral("missionStep"));
        sizePolicy5.setHeightForWidth(missionStep->sizePolicy().hasHeightForWidth());
        missionStep->setSizePolicy(sizePolicy5);
        missionStep->setMinimumSize(QSize(130, 40));
        missionStep->setMaximumSize(QSize(16777215, 50));
        missionStep->setFont(font2);

        missionControlLayout->addWidget(missionStep, 2, 0, 1, 1);

        missionAutomatic = new QPushButton(centralWidget);
        missionAutomatic->setObjectName(QStringLiteral("missionAutomatic"));
        sizePolicy5.setHeightForWidth(missionAutomatic->sizePolicy().hasHeightForWidth());
        missionAutomatic->setSizePolicy(sizePolicy5);
        missionAutomatic->setMinimumSize(QSize(130, 40));
        missionAutomatic->setMaximumSize(QSize(16777215, 50));
        missionAutomatic->setFont(font2);

        missionControlLayout->addWidget(missionAutomatic, 2, 1, 1, 1);

        missionCancel = new QPushButton(centralWidget);
        missionCancel->setObjectName(QStringLiteral("missionCancel"));
        sizePolicy5.setHeightForWidth(missionCancel->sizePolicy().hasHeightForWidth());
        missionCancel->setSizePolicy(sizePolicy5);
        missionCancel->setMinimumSize(QSize(130, 40));
        missionCancel->setMaximumSize(QSize(16777215, 50));
        missionCancel->setFont(font2);

        missionControlLayout->addWidget(missionCancel, 1, 1, 1, 1);

        staticMissionText = new QLabel(centralWidget);
        staticMissionText->setObjectName(QStringLiteral("staticMissionText"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(staticMissionText->sizePolicy().hasHeightForWidth());
        staticMissionText->setSizePolicy(sizePolicy6);
        staticMissionText->setMinimumSize(QSize(0, 30));
        staticMissionText->setMaximumSize(QSize(16777215, 30));
        staticMissionText->setFont(font);
        staticMissionText->setAlignment(Qt::AlignCenter);

        missionControlLayout->addWidget(staticMissionText, 0, 0, 1, 2);


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
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(placeHolder->sizePolicy().hasHeightForWidth());
        placeHolder->setSizePolicy(sizePolicy7);
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
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        colonyName->setFont(font3);

        gridLayout->addWidget(colonyName, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 80);
        gridLayout->setColumnStretch(1, 20);
        main_window->setCentralWidget(centralWidget);

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QMainWindow *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "main_window", Q_NULLPTR));
        changeColony->setText(QApplication::translate("main_window", "Andere Kolonie...", Q_NULLPTR));
        directionDown->setText(QString());
        playerWait->setText(QApplication::translate("main_window", "W", Q_NULLPTR));
        removeCommand->setText(QApplication::translate("main_window", "<-", Q_NULLPTR));
        staticProgramText->setText(QApplication::translate("main_window", "Programmieren", Q_NULLPTR));
        directionUp->setText(QString());
        repititionComboBox->clear();
        repititionComboBox->insertItems(0, QStringList()
         << QApplication::translate("main_window", "1x", Q_NULLPTR)
         << QApplication::translate("main_window", "2x", Q_NULLPTR)
         << QApplication::translate("main_window", "3x", Q_NULLPTR)
         << QApplication::translate("main_window", "4x", Q_NULLPTR)
         << QApplication::translate("main_window", "5x", Q_NULLPTR)
         << QApplication::translate("main_window", "6x", Q_NULLPTR)
         << QApplication::translate("main_window", "7x", Q_NULLPTR)
         << QApplication::translate("main_window", "8x", Q_NULLPTR)
         << QApplication::translate("main_window", "9x", Q_NULLPTR)
        );
        directionLeft->setText(QString());
        currentProgramText->setText(QApplication::translate("main_window", "W8W8W8", Q_NULLPTR));
        directionRight->setText(QString());
        missionPause->setText(QApplication::translate("main_window", "Anhalten", Q_NULLPTR));
        missionStart->setText(QApplication::translate("main_window", "Start", Q_NULLPTR));
        missionStep->setText(QApplication::translate("main_window", "Einzelschritt", Q_NULLPTR));
        missionAutomatic->setText(QApplication::translate("main_window", "Automatik", Q_NULLPTR));
        missionCancel->setText(QApplication::translate("main_window", "Abbruch", Q_NULLPTR));
        staticMissionText->setText(QApplication::translate("main_window", "Missionsablauf", Q_NULLPTR));
        placeHolder->setText(QApplication::translate("main_window", "-- gamescreen --", Q_NULLPTR));
        colonyName->setText(QApplication::translate("main_window", "Aktuelle Kolonie:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
