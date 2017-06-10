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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
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
    QHBoxLayout *horizontalLayout_2;
    QLabel *frame;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *width;
    QTextEdit *jumpFrame;
    QComboBox *ViewMode;
    QPushButton *loadVideo;
    QTextEdit *threshold;
    QLabel *sdadw;
    QTextEdit *erosionIterations;
    QLabel *sadd;
    QLabel *label_3;
    QTextEdit *previewHeight;
    QTextEdit *height;
    QLabel *label_2;
    QWidget *data;
    QWidget *tab3;
    QGridLayout *gridLayout_3;
    QLabel *background;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(717, 613);
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
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        frame = new QLabel(tracking);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(11);
        frame->setFont(font1);
        frame->setMouseTracking(false);
        frame->setFocusPolicy(Qt::ClickFocus);
        frame->setFrameShadow(QFrame::Plain);
        frame->setScaledContents(false);
        frame->setAlignment(Qt::AlignCenter);
        frame->setMargin(0);
        frame->setIndent(0);

        horizontalLayout_2->addWidget(frame);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton = new QPushButton(tracking);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(0, 24));
        pushButton->setMaximumSize(QSize(16777215, 24));

        gridLayout_4->addWidget(pushButton, 2, 4, 1, 1);

        label = new QLabel(tracking);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label, 2, 0, 1, 1);

        width = new QTextEdit(tracking);
        width->setObjectName(QStringLiteral("width"));
        sizePolicy2.setHeightForWidth(width->sizePolicy().hasHeightForWidth());
        width->setSizePolicy(sizePolicy2);
        width->setMinimumSize(QSize(0, 24));
        width->setMaximumSize(QSize(16777215, 24));
        width->setFont(font);
        width->setInputMethodHints(Qt::ImhDigitsOnly);
        width->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        width->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        width->setTabChangesFocus(true);
        width->setLineWrapMode(QTextEdit::NoWrap);
        width->setAcceptRichText(false);

        gridLayout_4->addWidget(width, 2, 1, 1, 1);

        jumpFrame = new QTextEdit(tracking);
        jumpFrame->setObjectName(QStringLiteral("jumpFrame"));
        sizePolicy2.setHeightForWidth(jumpFrame->sizePolicy().hasHeightForWidth());
        jumpFrame->setSizePolicy(sizePolicy2);
        jumpFrame->setMinimumSize(QSize(100, 24));
        jumpFrame->setMaximumSize(QSize(100, 24));
        jumpFrame->setSizeIncrement(QSize(20, 20));
        jumpFrame->setBaseSize(QSize(20, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(10);
        jumpFrame->setFont(font2);
        jumpFrame->setInputMethodHints(Qt::ImhDigitsOnly);
        jumpFrame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        jumpFrame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        jumpFrame->setTabChangesFocus(true);
        jumpFrame->setAcceptRichText(false);

        gridLayout_4->addWidget(jumpFrame, 3, 3, 1, 1);

        ViewMode = new QComboBox(tracking);
        ViewMode->setObjectName(QStringLiteral("ViewMode"));
        sizePolicy2.setHeightForWidth(ViewMode->sizePolicy().hasHeightForWidth());
        ViewMode->setSizePolicy(sizePolicy2);
        ViewMode->setMinimumSize(QSize(93, 24));
        ViewMode->setMaximumSize(QSize(16777215, 24));

        gridLayout_4->addWidget(ViewMode, 3, 2, 1, 1);

        loadVideo = new QPushButton(tracking);
        loadVideo->setObjectName(QStringLiteral("loadVideo"));
        sizePolicy2.setHeightForWidth(loadVideo->sizePolicy().hasHeightForWidth());
        loadVideo->setSizePolicy(sizePolicy2);
        loadVideo->setMinimumSize(QSize(0, 24));
        loadVideo->setMaximumSize(QSize(16777215, 24));
        loadVideo->setFont(font);

        gridLayout_4->addWidget(loadVideo, 3, 4, 1, 1);

        threshold = new QTextEdit(tracking);
        threshold->setObjectName(QStringLiteral("threshold"));
        sizePolicy2.setHeightForWidth(threshold->sizePolicy().hasHeightForWidth());
        threshold->setSizePolicy(sizePolicy2);
        threshold->setMinimumSize(QSize(0, 24));
        threshold->setMaximumSize(QSize(16777215, 24));
        threshold->setFont(font);
        threshold->setAutoFillBackground(false);
        threshold->setInputMethodHints(Qt::ImhDigitsOnly);
        threshold->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        threshold->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        threshold->setTabChangesFocus(true);
        threshold->setLineWrapMode(QTextEdit::NoWrap);
        threshold->setAcceptRichText(false);

        gridLayout_4->addWidget(threshold, 0, 1, 1, 1);

        sdadw = new QLabel(tracking);
        sdadw->setObjectName(QStringLiteral("sdadw"));
        sizePolicy3.setHeightForWidth(sdadw->sizePolicy().hasHeightForWidth());
        sdadw->setSizePolicy(sizePolicy3);
        sdadw->setMinimumSize(QSize(0, 24));
        sdadw->setMaximumSize(QSize(16777215, 24));
        sdadw->setFont(font);
        sdadw->setAutoFillBackground(false);
        sdadw->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(sdadw, 0, 0, 1, 1);

        erosionIterations = new QTextEdit(tracking);
        erosionIterations->setObjectName(QStringLiteral("erosionIterations"));
        sizePolicy2.setHeightForWidth(erosionIterations->sizePolicy().hasHeightForWidth());
        erosionIterations->setSizePolicy(sizePolicy2);
        erosionIterations->setMinimumSize(QSize(0, 24));
        erosionIterations->setMaximumSize(QSize(16777215, 24));
        erosionIterations->setFont(font);
        erosionIterations->setAutoFillBackground(false);
        erosionIterations->setInputMethodHints(Qt::ImhDigitsOnly);
        erosionIterations->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        erosionIterations->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        erosionIterations->setTabChangesFocus(true);
        erosionIterations->setLineWrapMode(QTextEdit::NoWrap);
        erosionIterations->setAcceptRichText(false);

        gridLayout_4->addWidget(erosionIterations, 0, 3, 1, 1);

        sadd = new QLabel(tracking);
        sadd->setObjectName(QStringLiteral("sadd"));
        sizePolicy3.setHeightForWidth(sadd->sizePolicy().hasHeightForWidth());
        sadd->setSizePolicy(sizePolicy3);
        sadd->setMinimumSize(QSize(0, 24));
        sadd->setMaximumSize(QSize(16777215, 24));
        sadd->setFont(font);
        sadd->setAutoFillBackground(false);
        sadd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(sadd, 0, 2, 1, 1);

        label_3 = new QLabel(tracking);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setMinimumSize(QSize(0, 24));
        label_3->setMaximumSize(QSize(16777215, 24));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        previewHeight = new QTextEdit(tracking);
        previewHeight->setObjectName(QStringLiteral("previewHeight"));
        sizePolicy2.setHeightForWidth(previewHeight->sizePolicy().hasHeightForWidth());
        previewHeight->setSizePolicy(sizePolicy2);
        previewHeight->setMinimumSize(QSize(0, 24));
        previewHeight->setMaximumSize(QSize(16777215, 24));
        previewHeight->setFont(font);
        previewHeight->setInputMethodHints(Qt::ImhDigitsOnly);
        previewHeight->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        previewHeight->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        previewHeight->setTabChangesFocus(true);
        previewHeight->setLineWrapMode(QTextEdit::NoWrap);
        previewHeight->setAcceptRichText(false);

        gridLayout_4->addWidget(previewHeight, 3, 1, 1, 1);

        height = new QTextEdit(tracking);
        height->setObjectName(QStringLiteral("height"));
        sizePolicy2.setHeightForWidth(height->sizePolicy().hasHeightForWidth());
        height->setSizePolicy(sizePolicy2);
        height->setMinimumSize(QSize(0, 24));
        height->setMaximumSize(QSize(16777215, 24));
        height->setFont(font);
        height->setInputMethodHints(Qt::ImhDigitsOnly);
        height->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        height->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        height->setTabChangesFocus(true);
        height->setLineWrapMode(QTextEdit::NoWrap);
        height->setAcceptRichText(false);

        gridLayout_4->addWidget(height, 2, 3, 1, 1);

        label_2 = new QLabel(tracking);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setMinimumSize(QSize(0, 24));
        label_2->setMaximumSize(QSize(16777215, 24));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_2, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 4, 0, 1, 1);

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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        frame->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Set Background", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Width (cm)", Q_NULLPTR));
        width->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">50</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        jumpFrame->setStatusTip(QApplication::translate("MainWindow", "Enter frame number and press enter", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        jumpFrame->setPlaceholderText(QApplication::translate("MainWindow", "Jump to frame", Q_NULLPTR));
        ViewMode->clear();
        ViewMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Grayscale", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Subtraction", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Threshold", Q_NULLPTR)
        );
        loadVideo->setText(QApplication::translate("MainWindow", "Load Video", Q_NULLPTR));
        threshold->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">20</span></p></body></html>", Q_NULLPTR));
        sdadw->setText(QApplication::translate("MainWindow", "Threshold", Q_NULLPTR));
        erosionIterations->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">2</span></p></body></html>", Q_NULLPTR));
        sadd->setText(QApplication::translate("MainWindow", "Erosion iterations", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Preview Height (pixels)", Q_NULLPTR));
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
        label_2->setText(QApplication::translate("MainWindow", "Height (cm)", Q_NULLPTR));
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
