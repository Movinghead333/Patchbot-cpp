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
#include <renderwidget.h>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *missionLayoutWidget;
    QGridLayout *missionControlLayout;
    QPushButton *missionStep;
    QPushButton *missionAutomatic;
    QPushButton *missionCancel;
    QPushButton *missionPause;
    QPushButton *missionStart;
    QLabel *staticMissionText;
    QSpacerItem *verticalSpacer;
    QPushButton *changeColony;
    QLabel *staticColonyName;
    QSpacerItem *verticalSpacer_2;
    QWidget *programmingLayoutWidget;
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
    QWidget *gameWindow_2;
    QGridLayout *gameWindow;
    QScrollBar *xScrollbar;
    QScrollBar *yScrollbar;
    RenderWidget *game;

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
        main_window->setStyleSheet(QLatin1String("QWidget#centralWidget{\n"
"background-color: rgb(205, 245, 255)\n"
"}\n"
"\n"
"QWidget#missionLayoutWidget, QWidget#programmingLayoutWidget{\n"
"background-color: rgb(87, 172, 200)\n"
"}\n"
"\n"
"QLabel#staticProgramText, QLabel#staticMissionText{\n"
"color: #FFFFFF\n"
"}\n"
"\n"
"QLabel#staticColonyName{\n"
"color: #000000\n"
"}\n"
"\n"
"QPushButton, QLineEdit, QComboBox{\n"
"background-color: rgb(74, 146, 170);\n"
"color: #FFFFFF;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-color: #000000;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(98, 193, 225)\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: rgb(53, 105, 122)\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid black;\n"
"    background: rgb(74, 146, 170);\n"
"    height: 25px;\n"
"    margin: 0px 20px 0 20px;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"    background:rgb(79, 68, 90);\n"
"	border: 1px solid black;\n"
"    min-width: 20px;\n"
"}\n"
"QScrollBar::add-line:horizontal {\n"
"    border: 1px "
                        "solid black;\n"
"    background: none;\n"
"    width: 20px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 1px solid black;\n"
"    background: none;\n"
"    width: 20px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::left-arrow:horizontal{\n"
"background: rgb(79, 68, 90);\n"
"image: url(:/qt/src/textures/scrollbar/scrollArrowLeft.tga);\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal{\n"
"background: rgb(79, 68, 90);\n"
"image: url(:/qt/src/textures/scrollbar/scrollArrowRight.tga);\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid black;\n"
"    background: rgb(74, 146, 170);\n"
"    width: 25px;\n"
"    margin: 20px 0px 20px 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background:rgb(79, 68, 90);\n"
"	border: 1px solid black;\n"
"    "
                        "min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"    border: 1px solid black;\n"
"    background: none;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid black;\n"
"    background: none;\n"
"    height: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical{\n"
"background: rgb(79, 68, 90);\n"
"image: url(:/qt/src/textures/scrollbar/scrollArrowUp.tga)\n"
"}\n"
"\n"
"QScrollBar::down-arrow:vertical{\n"
"background: rgb(79, 68, 90);\n"
"image: url(:/qt/src/textures/scrollbar/scrollArrowDown.tga)\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}"));
        centralWidget = new QWidget(main_window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setStyleSheet(QLatin1String("#QPushButton {\n"
"background-color: rgb(74, 146, 170);\n"
"color: #FFFFFF;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-color: #000000\n"
"}\n"
"#QPushButton:pressed{\n"
"background-color: rgb(53, 105, 122)\n"
"}"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        missionLayoutWidget = new QWidget(centralWidget);
        missionLayoutWidget->setObjectName(QStringLiteral("missionLayoutWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(missionLayoutWidget->sizePolicy().hasHeightForWidth());
        missionLayoutWidget->setSizePolicy(sizePolicy1);
        missionControlLayout = new QGridLayout(missionLayoutWidget);
        missionControlLayout->setSpacing(6);
        missionControlLayout->setContentsMargins(11, 11, 11, 11);
        missionControlLayout->setObjectName(QStringLiteral("missionControlLayout"));
        missionControlLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        missionControlLayout->setContentsMargins(10, 10, 10, 10);
        missionStep = new QPushButton(missionLayoutWidget);
        missionStep->setObjectName(QStringLiteral("missionStep"));
        sizePolicy1.setHeightForWidth(missionStep->sizePolicy().hasHeightForWidth());
        missionStep->setSizePolicy(sizePolicy1);
        missionStep->setMinimumSize(QSize(130, 40));
        missionStep->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(8);
        missionStep->setFont(font);

        missionControlLayout->addWidget(missionStep, 2, 0, 1, 1);

        missionAutomatic = new QPushButton(missionLayoutWidget);
        missionAutomatic->setObjectName(QStringLiteral("missionAutomatic"));
        sizePolicy1.setHeightForWidth(missionAutomatic->sizePolicy().hasHeightForWidth());
        missionAutomatic->setSizePolicy(sizePolicy1);
        missionAutomatic->setMinimumSize(QSize(130, 40));
        missionAutomatic->setMaximumSize(QSize(16777215, 50));
        missionAutomatic->setFont(font);
        missionAutomatic->setStyleSheet(QStringLiteral(""));

        missionControlLayout->addWidget(missionAutomatic, 2, 1, 1, 1);

        missionCancel = new QPushButton(missionLayoutWidget);
        missionCancel->setObjectName(QStringLiteral("missionCancel"));
        sizePolicy1.setHeightForWidth(missionCancel->sizePolicy().hasHeightForWidth());
        missionCancel->setSizePolicy(sizePolicy1);
        missionCancel->setMinimumSize(QSize(130, 40));
        missionCancel->setMaximumSize(QSize(16777215, 50));
        missionCancel->setFont(font);

        missionControlLayout->addWidget(missionCancel, 1, 1, 1, 1);

        missionPause = new QPushButton(missionLayoutWidget);
        missionPause->setObjectName(QStringLiteral("missionPause"));
        sizePolicy1.setHeightForWidth(missionPause->sizePolicy().hasHeightForWidth());
        missionPause->setSizePolicy(sizePolicy1);
        missionPause->setMinimumSize(QSize(130, 40));
        missionPause->setMaximumSize(QSize(16777215, 50));
        missionPause->setFont(font);

        missionControlLayout->addWidget(missionPause, 3, 1, 1, 1);

        missionStart = new QPushButton(missionLayoutWidget);
        missionStart->setObjectName(QStringLiteral("missionStart"));
        sizePolicy1.setHeightForWidth(missionStart->sizePolicy().hasHeightForWidth());
        missionStart->setSizePolicy(sizePolicy1);
        missionStart->setMinimumSize(QSize(130, 40));
        missionStart->setMaximumSize(QSize(16777215, 50));
        missionStart->setFont(font);

        missionControlLayout->addWidget(missionStart, 1, 0, 1, 1);

        staticMissionText = new QLabel(missionLayoutWidget);
        staticMissionText->setObjectName(QStringLiteral("staticMissionText"));
        sizePolicy1.setHeightForWidth(staticMissionText->sizePolicy().hasHeightForWidth());
        staticMissionText->setSizePolicy(sizePolicy1);
        staticMissionText->setMinimumSize(QSize(0, 30));
        staticMissionText->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        staticMissionText->setFont(font1);
        staticMissionText->setAlignment(Qt::AlignCenter);

        missionControlLayout->addWidget(staticMissionText, 0, 0, 1, 2);


        gridLayout->addWidget(missionLayoutWidget, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        changeColony = new QPushButton(centralWidget);
        changeColony->setObjectName(QStringLiteral("changeColony"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(changeColony->sizePolicy().hasHeightForWidth());
        changeColony->setSizePolicy(sizePolicy2);
        changeColony->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(changeColony, 0, 1, 1, 1, Qt::AlignRight);

        staticColonyName = new QLabel(centralWidget);
        staticColonyName->setObjectName(QStringLiteral("staticColonyName"));
        staticColonyName->setFont(font1);

        gridLayout->addWidget(staticColonyName, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        programmingLayoutWidget = new QWidget(centralWidget);
        programmingLayoutWidget->setObjectName(QStringLiteral("programmingLayoutWidget"));
        gameProgramming = new QGridLayout(programmingLayoutWidget);
        gameProgramming->setSpacing(6);
        gameProgramming->setContentsMargins(11, 11, 11, 11);
        gameProgramming->setObjectName(QStringLiteral("gameProgramming"));
        gameProgramming->setContentsMargins(10, 10, 10, 10);
        directionDown = new QPushButton(programmingLayoutWidget);
        directionDown->setObjectName(QStringLiteral("directionDown"));
        directionDown->setMinimumSize(QSize(40, 40));
        directionDown->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qt/src/textures/pfeile/pfeil_unten.tga"), QSize(), QIcon::Normal, QIcon::Off);
        directionDown->setIcon(icon);
        directionDown->setIconSize(QSize(32, 32));

        gameProgramming->addWidget(directionDown, 3, 1, 1, 1);

        playerWait = new QPushButton(programmingLayoutWidget);
        playerWait->setObjectName(QStringLiteral("playerWait"));
        playerWait->setMinimumSize(QSize(40, 40));
        playerWait->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/qt/src/textures/pfeile/waitCircle.tga"), QSize(), QIcon::Normal, QIcon::Off);
        playerWait->setIcon(icon1);
        playerWait->setIconSize(QSize(32, 32));

        gameProgramming->addWidget(playerWait, 2, 1, 1, 1);

        removeCommand = new QPushButton(programmingLayoutWidget);
        removeCommand->setObjectName(QStringLiteral("removeCommand"));
        removeCommand->setMinimumSize(QSize(40, 40));
        removeCommand->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/qt/src/textures/pfeile/backArrow.tga"), QSize(), QIcon::Normal, QIcon::Off);
        removeCommand->setIcon(icon2);
        removeCommand->setIconSize(QSize(32, 32));

        gameProgramming->addWidget(removeCommand, 1, 2, 1, 1);

        staticProgramText = new QLabel(programmingLayoutWidget);
        staticProgramText->setObjectName(QStringLiteral("staticProgramText"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(staticProgramText->sizePolicy().hasHeightForWidth());
        staticProgramText->setSizePolicy(sizePolicy3);
        staticProgramText->setMinimumSize(QSize(0, 30));
        staticProgramText->setMaximumSize(QSize(16777215, 50));
        staticProgramText->setFont(font1);
        staticProgramText->setAlignment(Qt::AlignCenter);

        gameProgramming->addWidget(staticProgramText, 0, 0, 1, 5);

        directionUp = new QPushButton(programmingLayoutWidget);
        directionUp->setObjectName(QStringLiteral("directionUp"));
        directionUp->setMinimumSize(QSize(40, 40));
        directionUp->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/qt/src/textures/pfeile/pfeil_oben.tga"), QSize(), QIcon::Normal, QIcon::Off);
        directionUp->setIcon(icon3);
        directionUp->setIconSize(QSize(32, 32));

        gameProgramming->addWidget(directionUp, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gameProgramming->addItem(horizontalSpacer, 1, 3, 1, 1);

        repititionComboBox = new QComboBox(programmingLayoutWidget);
        repititionComboBox->setObjectName(QStringLiteral("repititionComboBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(repititionComboBox->sizePolicy().hasHeightForWidth());
        repititionComboBox->setSizePolicy(sizePolicy4);
        repititionComboBox->setMinimumSize(QSize(50, 30));
        repititionComboBox->setMaximumSize(QSize(16777215, 30));
        repititionComboBox->setEditable(false);

        gameProgramming->addWidget(repititionComboBox, 1, 4, 1, 1);

        directionLeft = new QPushButton(programmingLayoutWidget);
        directionLeft->setObjectName(QStringLiteral("directionLeft"));
        sizePolicy2.setHeightForWidth(directionLeft->sizePolicy().hasHeightForWidth());
        directionLeft->setSizePolicy(sizePolicy2);
        directionLeft->setMinimumSize(QSize(40, 40));
        directionLeft->setMaximumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/qt/src/textures/pfeile/pfeil_links.tga"), QSize(), QIcon::Normal, QIcon::Off);
        directionLeft->setIcon(icon4);
        directionLeft->setIconSize(QSize(32, 32));

        gameProgramming->addWidget(directionLeft, 2, 0, 1, 1);

        currentProgramLayout = new QVBoxLayout();
        currentProgramLayout->setSpacing(0);
        currentProgramLayout->setObjectName(QStringLiteral("currentProgramLayout"));
        programmDisplaySpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        currentProgramLayout->addItem(programmDisplaySpacer);

        currentProgramText = new QLineEdit(programmingLayoutWidget);
        currentProgramText->setObjectName(QStringLiteral("currentProgramText"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(currentProgramText->sizePolicy().hasHeightForWidth());
        currentProgramText->setSizePolicy(sizePolicy5);
        currentProgramText->setMinimumSize(QSize(80, 40));
        currentProgramText->setMaximumSize(QSize(16777215, 40));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(74, 146, 170, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        currentProgramText->setPalette(palette);
        QFont font2;
        font2.setUnderline(false);
        font2.setKerning(true);
        currentProgramText->setFont(font2);
        currentProgramText->setReadOnly(true);

        currentProgramLayout->addWidget(currentProgramText);

        scrollProgram = new QScrollBar(programmingLayoutWidget);
        scrollProgram->setObjectName(QStringLiteral("scrollProgram"));
        sizePolicy5.setHeightForWidth(scrollProgram->sizePolicy().hasHeightForWidth());
        scrollProgram->setSizePolicy(sizePolicy5);
        scrollProgram->setMinimumSize(QSize(0, 20));
        scrollProgram->setMaximumSize(QSize(16777215, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        scrollProgram->setPalette(palette1);
        scrollProgram->setFont(font2);
        scrollProgram->setOrientation(Qt::Horizontal);

        currentProgramLayout->addWidget(scrollProgram);


        gameProgramming->addLayout(currentProgramLayout, 2, 4, 2, 1);

        directionRight = new QPushButton(programmingLayoutWidget);
        directionRight->setObjectName(QStringLiteral("directionRight"));
        directionRight->setMinimumSize(QSize(40, 40));
        directionRight->setMaximumSize(QSize(40, 40));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/qt/src/textures/pfeile/pfeil_rechts.tga"), QSize(), QIcon::Normal, QIcon::Off);
        directionRight->setIcon(icon5);
        directionRight->setIconSize(QSize(32, 32));

        gameProgramming->addWidget(directionRight, 2, 2, 1, 1);


        gridLayout->addWidget(programmingLayoutWidget, 1, 1, 1, 1);

        gameWindow_2 = new QWidget(centralWidget);
        gameWindow_2->setObjectName(QStringLiteral("gameWindow_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(gameWindow_2->sizePolicy().hasHeightForWidth());
        gameWindow_2->setSizePolicy(sizePolicy6);
        gameWindow_2->setMinimumSize(QSize(1, 1));
        gameWindow = new QGridLayout(gameWindow_2);
        gameWindow->setSpacing(0);
        gameWindow->setContentsMargins(11, 11, 11, 11);
        gameWindow->setObjectName(QStringLiteral("gameWindow"));
        gameWindow->setContentsMargins(20, -1, 20, -1);
        xScrollbar = new QScrollBar(gameWindow_2);
        xScrollbar->setObjectName(QStringLiteral("xScrollbar"));
        sizePolicy3.setHeightForWidth(xScrollbar->sizePolicy().hasHeightForWidth());
        xScrollbar->setSizePolicy(sizePolicy3);
        xScrollbar->setMinimumSize(QSize(0, 25));
        xScrollbar->setOrientation(Qt::Horizontal);

        gameWindow->addWidget(xScrollbar, 1, 0, 1, 1);

        yScrollbar = new QScrollBar(gameWindow_2);
        yScrollbar->setObjectName(QStringLiteral("yScrollbar"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(yScrollbar->sizePolicy().hasHeightForWidth());
        yScrollbar->setSizePolicy(sizePolicy7);
        yScrollbar->setMinimumSize(QSize(25, 0));
        yScrollbar->setOrientation(Qt::Vertical);

        gameWindow->addWidget(yScrollbar, 0, 1, 1, 1);

        game = new RenderWidget(gameWindow_2);
        game->setObjectName(QStringLiteral("game"));
        sizePolicy.setHeightForWidth(game->sizePolicy().hasHeightForWidth());
        game->setSizePolicy(sizePolicy);

        gameWindow->addWidget(game, 0, 0, 1, 1);


        gridLayout->addWidget(gameWindow_2, 1, 0, 4, 1);

        gridLayout->setColumnStretch(0, 80);
        gridLayout->setColumnStretch(1, 20);
        main_window->setCentralWidget(centralWidget);

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QMainWindow *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "main_window", Q_NULLPTR));
        missionStep->setText(QApplication::translate("main_window", "Einzelschritt", Q_NULLPTR));
        missionAutomatic->setText(QApplication::translate("main_window", "Automatik", Q_NULLPTR));
        missionCancel->setText(QApplication::translate("main_window", "Abbruch", Q_NULLPTR));
        missionPause->setText(QApplication::translate("main_window", "Anhalten", Q_NULLPTR));
        missionStart->setText(QApplication::translate("main_window", "Start", Q_NULLPTR));
        staticMissionText->setText(QApplication::translate("main_window", "Missionsablauf", Q_NULLPTR));
        changeColony->setText(QApplication::translate("main_window", "Andere Kolonie...", Q_NULLPTR));
        staticColonyName->setText(QApplication::translate("main_window", "Aktuelle Kolonie:", Q_NULLPTR));
        directionDown->setText(QString());
        playerWait->setText(QString());
        removeCommand->setText(QString());
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
         << QApplication::translate("main_window", "X", Q_NULLPTR)
        );
        directionLeft->setText(QString());
        currentProgramText->setText(QApplication::translate("main_window", "W8W8W8", Q_NULLPTR));
        directionRight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
