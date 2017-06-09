/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tracking;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_7;
    QTextEdit *previewHeight;
    QTextEdit *height;
    QTextEdit *width;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *ViewMode;
    QTextEdit *jumpFrame;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QVBoxLayout *verticalLayout;
    QPushButton *loadVideo;
    QPushButton *pushButton_3;
    QPushButton *Track_B;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_4;
    QLabel *sadd;
    QTextEdit *erosionIterations;
    QLabel *sadd_2;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QTextEdit *threshold;
    QLabel *sdadw;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_9;
    QTextEdit *textEdit;
    QLabel *frame;
    QWidget *data;
    QWidget *tab3;
    QGridLayout *gridLayout_3;
    QLabel *background;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(913, 613);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        tabWidget->setFont(font);
        tracking = new QWidget();
        tracking->setObjectName(QStringLiteral("tracking"));
        gridLayout_2 = new QGridLayout(tracking);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget_2 = new QTabWidget(tracking);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_10 = new QGridLayout(tab);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_7 = new QGridLayout(groupBox_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        previewHeight = new QTextEdit(groupBox_2);
        previewHeight->setObjectName(QStringLiteral("previewHeight"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(previewHeight->sizePolicy().hasHeightForWidth());
        previewHeight->setSizePolicy(sizePolicy1);
        previewHeight->setMinimumSize(QSize(0, 24));
        previewHeight->setMaximumSize(QSize(50, 24));
        previewHeight->setFont(font);
        previewHeight->setInputMethodHints(Qt::ImhDigitsOnly);
        previewHeight->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        previewHeight->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        previewHeight->setTabChangesFocus(true);
        previewHeight->setLineWrapMode(QTextEdit::NoWrap);
        previewHeight->setAcceptRichText(false);

        gridLayout_7->addWidget(previewHeight, 4, 4, 1, 1);

        height = new QTextEdit(groupBox_2);
        height->setObjectName(QStringLiteral("height"));
        sizePolicy1.setHeightForWidth(height->sizePolicy().hasHeightForWidth());
        height->setSizePolicy(sizePolicy1);
        height->setMinimumSize(QSize(0, 24));
        height->setMaximumSize(QSize(40, 24));
        height->setFont(font);
        height->setInputMethodHints(Qt::ImhDigitsOnly);
        height->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        height->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        height->setTabChangesFocus(true);
        height->setLineWrapMode(QTextEdit::NoWrap);
        height->setAcceptRichText(false);

        gridLayout_7->addWidget(height, 3, 4, 1, 1);

        width = new QTextEdit(groupBox_2);
        width->setObjectName(QStringLiteral("width"));
        sizePolicy1.setHeightForWidth(width->sizePolicy().hasHeightForWidth());
        width->setSizePolicy(sizePolicy1);
        width->setMinimumSize(QSize(0, 24));
        width->setMaximumSize(QSize(40, 24));
        width->setFont(font);
        width->setInputMethodHints(Qt::ImhDigitsOnly);
        width->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        width->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        width->setTabChangesFocus(true);
        width->setLineWrapMode(QTextEdit::NoWrap);
        width->setAcceptRichText(false);

        gridLayout_7->addWidget(width, 2, 4, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(150, 24));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label, 2, 3, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(0, 24));
        label_2->setMaximumSize(QSize(150, 24));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_2, 3, 3, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(0, 24));
        label_3->setMaximumSize(QSize(150, 24));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_3, 4, 3, 1, 1);

        ViewMode = new QComboBox(groupBox_2);
        ViewMode->setObjectName(QStringLiteral("ViewMode"));
        sizePolicy1.setHeightForWidth(ViewMode->sizePolicy().hasHeightForWidth());
        ViewMode->setSizePolicy(sizePolicy1);
        ViewMode->setMinimumSize(QSize(93, 24));
        ViewMode->setMaximumSize(QSize(16777215, 24));

        gridLayout_7->addWidget(ViewMode, 0, 3, 1, 1);

        jumpFrame = new QTextEdit(groupBox_2);
        jumpFrame->setObjectName(QStringLiteral("jumpFrame"));
        sizePolicy1.setHeightForWidth(jumpFrame->sizePolicy().hasHeightForWidth());
        jumpFrame->setSizePolicy(sizePolicy1);
        jumpFrame->setMinimumSize(QSize(100, 24));
        jumpFrame->setMaximumSize(QSize(100, 24));
        jumpFrame->setSizeIncrement(QSize(20, 20));
        jumpFrame->setBaseSize(QSize(20, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(10);
        jumpFrame->setFont(font1);
        jumpFrame->setInputMethodHints(Qt::ImhDigitsOnly);
        jumpFrame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        jumpFrame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        jumpFrame->setTabChangesFocus(true);
        jumpFrame->setAcceptRichText(false);

        gridLayout_7->addWidget(jumpFrame, 1, 3, 1, 1);


        gridLayout_10->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(0, 24));
        pushButton->setMaximumSize(QSize(16777215, 24));

        gridLayout_6->addWidget(pushButton, 2, 1, 1, 1);

        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout_6->addWidget(radioButton, 0, 1, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setChecked(true);

        gridLayout_6->addWidget(radioButton_2, 1, 1, 1, 1);

        pushButton->raise();
        radioButton_2->raise();
        radioButton->raise();

        gridLayout_10->addWidget(groupBox_3, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        loadVideo = new QPushButton(tab);
        loadVideo->setObjectName(QStringLiteral("loadVideo"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(loadVideo->sizePolicy().hasHeightForWidth());
        loadVideo->setSizePolicy(sizePolicy3);
        loadVideo->setMinimumSize(QSize(0, 24));
        loadVideo->setMaximumSize(QSize(16777215, 24));
        loadVideo->setFont(font);

        verticalLayout->addWidget(loadVideo);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        Track_B = new QPushButton(tab);
        Track_B->setObjectName(QStringLiteral("Track_B"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Track_B->sizePolicy().hasHeightForWidth());
        Track_B->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(Track_B);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        gridLayout_10->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget_2->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_12 = new QGridLayout(tab_3);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy5);
        groupBox_4->setMaximumSize(QSize(500, 16777215));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        checkBox_4 = new QCheckBox(groupBox_4);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        gridLayout_4->addWidget(checkBox_4, 0, 0, 2, 1);

        sadd = new QLabel(groupBox_4);
        sadd->setObjectName(QStringLiteral("sadd"));
        sizePolicy2.setHeightForWidth(sadd->sizePolicy().hasHeightForWidth());
        sadd->setSizePolicy(sizePolicy2);
        sadd->setMinimumSize(QSize(0, 24));
        sadd->setMaximumSize(QSize(50, 24));
        sadd->setFont(font);
        sadd->setAutoFillBackground(false);
        sadd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(sadd, 0, 1, 2, 1);

        erosionIterations = new QTextEdit(groupBox_4);
        erosionIterations->setObjectName(QStringLiteral("erosionIterations"));
        sizePolicy2.setHeightForWidth(erosionIterations->sizePolicy().hasHeightForWidth());
        erosionIterations->setSizePolicy(sizePolicy2);
        erosionIterations->setMinimumSize(QSize(0, 24));
        erosionIterations->setMaximumSize(QSize(40, 24));
        erosionIterations->setFont(font);
        erosionIterations->setLayoutDirection(Qt::LeftToRight);
        erosionIterations->setAutoFillBackground(false);
        erosionIterations->setInputMethodHints(Qt::ImhDigitsOnly);
        erosionIterations->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        erosionIterations->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        erosionIterations->setTabChangesFocus(true);
        erosionIterations->setLineWrapMode(QTextEdit::NoWrap);
        erosionIterations->setAcceptRichText(false);

        gridLayout_4->addWidget(erosionIterations, 0, 2, 2, 2);

        sadd_2 = new QLabel(groupBox_4);
        sadd_2->setObjectName(QStringLiteral("sadd_2"));
        sizePolicy2.setHeightForWidth(sadd_2->sizePolicy().hasHeightForWidth());
        sadd_2->setSizePolicy(sizePolicy2);
        sadd_2->setMinimumSize(QSize(0, 24));
        sadd_2->setMaximumSize(QSize(50, 24));
        sadd_2->setFont(font);
        sadd_2->setAutoFillBackground(false);
        sadd_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(sadd_2, 1, 3, 2, 1);

        checkBox_3 = new QCheckBox(groupBox_4);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout_4->addWidget(checkBox_3, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 1, 0, 1, 2);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy6);
        groupBox_5->setMaximumSize(QSize(500, 16777215));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        threshold = new QTextEdit(groupBox_5);
        threshold->setObjectName(QStringLiteral("threshold"));
        sizePolicy3.setHeightForWidth(threshold->sizePolicy().hasHeightForWidth());
        threshold->setSizePolicy(sizePolicy3);
        threshold->setMinimumSize(QSize(0, 24));
        threshold->setMaximumSize(QSize(50, 24));
        threshold->setFont(font);
        threshold->setAutoFillBackground(false);
        threshold->setInputMethodHints(Qt::ImhDigitsOnly);
        threshold->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        threshold->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        threshold->setTabChangesFocus(true);
        threshold->setLineWrapMode(QTextEdit::NoWrap);
        threshold->setAcceptRichText(false);

        gridLayout_8->addWidget(threshold, 0, 1, 1, 1);

        sdadw = new QLabel(groupBox_5);
        sdadw->setObjectName(QStringLiteral("sdadw"));
        sizePolicy2.setHeightForWidth(sdadw->sizePolicy().hasHeightForWidth());
        sdadw->setSizePolicy(sizePolicy2);
        sdadw->setMinimumSize(QSize(0, 24));
        sdadw->setMaximumSize(QSize(100, 24));
        sdadw->setFont(font);
        sdadw->setAutoFillBackground(false);
        sdadw->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(sdadw, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_5, 0, 0, 1, 2);


        gridLayout_12->addWidget(groupBox, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        gridLayout_12->addLayout(verticalLayout_2, 0, 1, 1, 1);

        tabWidget_2->addTab(tab_3, QString());

        gridLayout_2->addWidget(tabWidget_2, 3, 0, 1, 1);

        groupBox_6 = new QGroupBox(tracking);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_9 = new QGridLayout(groupBox_6);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        textEdit = new QTextEdit(groupBox_6);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_9->addWidget(textEdit, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 3, 2, 1, 1);

        frame = new QLabel(tracking);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy7);
        frame->setMaximumSize(QSize(16777215, 500));
        QFont font2;
        font2.setPointSize(11);
        frame->setFont(font2);
        frame->setMouseTracking(false);
        frame->setFocusPolicy(Qt::ClickFocus);
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setFrameShadow(QFrame::Plain);
        frame->setScaledContents(false);
        frame->setAlignment(Qt::AlignCenter);
        frame->setMargin(0);
        frame->setIndent(0);

        gridLayout_2->addWidget(frame, 0, 0, 1, 3);

        tabWidget->addTab(tracking, QString());
        data = new QWidget();
        data->setObjectName(QStringLiteral("data"));
        tabWidget->addTab(data, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QStringLiteral("tab3"));
        gridLayout_3 = new QGridLayout(tab3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        background = new QLabel(tab3);
        background->setObjectName(QStringLiteral("background"));

        gridLayout_3->addWidget(background, 0, 0, 1, 1);

        tabWidget->addTab(tab3, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(radioButton_2, SIGNAL(toggled(bool)), pushButton, SLOT(setDisabled(bool)));

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Display:", Q_NULLPTR));
        previewHeight->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">500</span></p></body></html>", Q_NULLPTR));
        height->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">50</span></p></body></html>", Q_NULLPTR));
        width->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">50</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Width (cm)", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Height (cm)", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Preview Height (px)", Q_NULLPTR));
        ViewMode->clear();
        ViewMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Grayscale", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Subtraction", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Threshold", Q_NULLPTR)
        );
#ifndef QT_NO_STATUSTIP
        jumpFrame->setStatusTip(QApplication::translate("MainWindow", "Enter frame number and press enter", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        jumpFrame->setPlaceholderText(QApplication::translate("MainWindow", "Jump to frame", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Background selection:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Set Background", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Define", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "First frame", Q_NULLPTR));
        loadVideo->setText(QApplication::translate("MainWindow", "Load Video", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        Track_B->setText(QApplication::translate("MainWindow", "Track", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindow", "Video", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Filtering:", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Apply:", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("MainWindow", "Erosion", Q_NULLPTR));
        sadd->setText(QApplication::translate("MainWindow", "# itrs", Q_NULLPTR));
        erosionIterations->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">2</span></p></body></html>", Q_NULLPTR));
        sadd_2->setText(QApplication::translate("MainWindow", "# itrs", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "Dilation", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Contour Threshold:", Q_NULLPTR));
        threshold->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">20</span></p></body></html>", Q_NULLPTR));
        sdadw->setText(QApplication::translate("MainWindow", "Value:", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Tracking filters", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        frame->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tracking), QApplication::translate("MainWindow", "Tracking", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(data), QApplication::translate("MainWindow", "Data", Q_NULLPTR));
        background->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("MainWindow", "Background", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
