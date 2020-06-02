/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QString::fromUtf8("Help"));
        Help->resize(857, 446);
        horizontalLayout_2 = new QHBoxLayout(Help);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(Help);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Help);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Help);
        QObject::connect(pushButton, SIGNAL(clicked()), Help, SLOT(close()));

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QWidget *Help)
    {
        Help->setWindowTitle(QCoreApplication::translate("Help", "Help", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">\320\237\320\276\320\274\320\276\321\211\321\214 \320\237\320\276 \320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\216 \320\224\320\260\320\275\320\275\320\276\320\271 \320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-we"
                        "ight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; font-style:italic;\">\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213:  </span><span style=\" font-size:8.25pt;\">\320\224\320\260\320\275\320\275\320\260\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\274\320\276\320\266\320\265\321\202 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214\321\201\321\217 \320\262 \320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \321\206\320\265\320\273\321\217\321\205 \320\264\320\273\321\217 \320\264\320\265\320\274\320\276\320\275\321\201\321\202\321\200\320\260\321\206\320\270\320\270 \320\274\320\276\320\264\320\265\320\273\320\270 \320\262\320\267\320\260"
                        "\320\270\320\274\320\276\320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217 \320\267\320\260\321\200\321\217\320\264\320\276\320\262 \320\270 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\321\205 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\271, \321\201\320\262\321\217\320\267\320\260\320\275\320\275\321\213\321\205 \321\201 \320\275\320\270\320\274\320\270. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; font-weight:600;\">\320\230\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217 \320\277\320\276 \320\270\321\201\320\277\320\276\320"
                        "\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\216: </span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; font-style:italic;\">\320\224\320\273\321\217 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\267\320\260\321\200\321\217\320\264\320\260\320\274\320\270 \320\222\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\272\320\275\320\276\320\277\320\272\320\270:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\232\320\275\320\276\320\277\320\272\320\260 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\227\320\260\321\200\321\217\320\264&quot; </span><span style=\" font-size:8.25pt;\">\321\201\320\273\321\203\320\266\320\270\321\202 \320\275\320\265\320\277\320\276\321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\265\320\275\320\275\320\276 \320\264\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\267\320\260\321\200\321\217\320\264\320\260 \320\275\320\260 \321\200\320\260\320\261\320\276\321\207\321\203\321\216 \320\276\320\261\320\273\320\260\321\201\321\202\321\214. \320\222 \320\277\320\276\321\217\320\262\320\270\320\262\321\210\320\265\320\274\321"
                        "\201\321\217 \320\276\320\272\320\276\321\210\320\272\320\265 \320\277\320\276\321\202\321\200\320\265\320\261\321\203\320\265\321\202\321\201\321\217 \321\203\320\272\320\260\320\267\320\260\321\202\321\214 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270 \320\267\320\260\321\200\321\217\320\264\320\260.  </span><span style=\" font-size:8.25pt; color:#aa0000;\">(\320\224\320\273\321\217 \320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\275\320\276\320\271 \321\200\320\260\320\261\320\276\321\202\321\213 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213 \321\201\321\202\320\276\320\270\321\202 \320\277\321\200\320\270\320\264\320\265\321\200\320\266\320\270\320\262\320\260\321\202\321\214\321\201\321\217 \321\200\320\265\320\260\320\273\321\214\320\275\321\213\321\205 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321"
                        "\202\320\270\320\272 \320\267\320\260\321\200\321\217\320\264\320\260, \321\202.\320\265. \320\275\320\265 \321\200\320\265\320\272\320\276\320\274\320\265\320\275\320\264\321\203\320\265\321\202\321\201\321\217 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\274\320\260\321\201\321\201\321\203 \320\267\320\260\321\200\321\217\320\264\320\260 \320\262 \320\232\320\263, \320\260 \320\265\320\263\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\262 \320\275\320\232\320\273.)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; color:#aa0000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; color:#000000;\">\320\232\320\275\320\276\320\277\320\272\320\260</span><span style=\" font-size:8.25pt; font-weight:600; col"
                        "or:#000000;\"> &quot;\320\230\320\263\320\275\320\276\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\227\320\260\321\200\321\217\320\264&quot; </span><span style=\" font-size:8.25pt; color:#000000;\">\321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \320\270\320\263\320\275\320\276\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \320\262\320\260\320\274\320\270 \320\267\320\260\321\200\321\217\320\264\320\260. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; color:#000000;\">\320\232\320\275\320\276\320\277\320\272\320\260 </span><span style=\" font-siz"
                        "e:8.25pt; font-weight:600; color:#000000;\">&quot;\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\227\320\260\321\200\321\217\320\264&quot;</span><span style=\" font-size:8.25pt; color:#000000;\">  \321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \320\262\320\260\320\274\320\270 \320\267\320\260\321\200\321\217\320\264\320\260. </span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\232\320\275\320\276"
                        "\320\277\320\272\320\260 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\227\320\260\321\200\321\217\320\264&quot;</span><span style=\" font-size:8.25pt;\"> \321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\217 \320\267\320\260\321\200\321\217\320\264\320\260 \321\201 \321\200\320\260\320\261\320\276\321\207\320\265\320\271 \320\276\320\261\320\273\320\260\321\201\321\202\320\270. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; font-style:italic;\">\320\224\320\273\321\217 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \321"
                        "\200\320\260\321\201\321\207\320\265\321\202\320\276\320\262 \320\270 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\260 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\320\276 4 \320\262\320\272\320\273\320\260\320\264\320\272\320\270:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-style:italic;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\222\320\272\320\273\320\260\320\264\320\272\320\260</span><span style=\" font-size:8.25pt; font-weight:600;\"> &quot;\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\237\320\276 \320\237\320\276\320\267\320\270\321\206\320\270\320\270&quot;</span><span styl"
                        "e=\" font-size:8.25pt;\"> \321\201\320\276\320\264\320\265\321\200\320\266\320\270\321\202 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\274\320\276\320\264\321\203\320\273\320\265 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\275\320\276\321\201\321\202\320\270 \320\270 \320\265\320\265 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\321\217\321\205, \320\277\320\276\321\202\320\265\320\275\321\206\320\270\320\260\320\273\320\265, \320\260 \321\202\320\260\320\272\320\266\320\265 \321\215\320\275\320\265\321\200\320\263\320\270\320\270 \320\277\320\276\320\273\321\217 \320\262 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \321\202\320\276\321\207\320\272\320\265. (\320\224\320\273\321\217 \321\200\320\260\320\261\320\276\321\202\321\213 \320\275\321\203\320\266\320\275\320\276 \320\262\320\262\320\265\321\201\321\202\320\270 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213"
                        " \321\201\320\260\320\274\320\276\321\201\321\202\320\276\321\217\321\202\320\265\320\273\321\214\320\275\320\276 \320\273\320\270\320\261\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \320\272\321\203\321\200\321\201\320\276\321\200) </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\222\320\272\320\273\320\260\320\264\320\272\320\260 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\240\320\260\320\261\320\276\321\202\320\260&quot;</span><span style=\" font-size:8.25pt;\"> \321\201\320\276\320\264\320\265\321\200\320\266\320\270\321\202 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\267"
                        "\320\260\321\202\321\200\320\260\321\207\320\270\320\262\320\260\320\265\320\274\320\276\320\271 \321\200\320\260\320\261\320\276\321\202\320\265 \320\277\321\200\320\270 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\270 \320\277\321\200\320\276\320\261\320\275\320\276\320\263\320\276 \320\267\320\260\321\200\321\217\320\264\320\260 \320\270\320\267 \320\276\320\264\320\275\320\276\320\271 \321\202\320\276\321\207\320\272\320\270 \320\277\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\260 \320\262 \320\264\321\200\321\203\320\263\321\203\321\216. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\222\320\272\320\273\320\260\320\264\320\272"
                        "\320\260 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\236 \320\227\320\260\321\200\321\217\320\264\320\265&quot;</span><span style=\" font-size:8.25pt;\"> \321\201\320\276\320\264\320\265\321\200\320\266\320\270\321\202 \320\277\320\276\320\273\320\275\321\203\321\216 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\274 \320\267\320\260\321\200\321\217\320\264\320\265.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-style:italic;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\222\320\272\320\273\320\260\320\264\320\272\320\260 &quot;</spa"
                        "n><span style=\" font-size:8.25pt; font-weight:600;\">\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\236 \320\241\320\270\321\201\321\202\320\265\320\274\320\265</span><span style=\" font-size:8.25pt;\">&quot; \321\201\320\276\320\264\320\265\321\200\320\266\320\270\321\202 \320\277\320\276\320\273\320\275\321\203\321\216 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \321\201\320\270\321\201\321\202\320\265\320\274\320\265 \320\267\320\260\321\200\321\217\320\264\320\276\320\262.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; font-style:italic;\">\320\235\320\270\320\266\320\265 \320\270\320\274\320\265\321\216\321\202\321\201\321\217"
                        " 4 \320\272\320\275\320\276\320\277\320\272\320\270 \320\264\320\273\321\217 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\320\265\320\271 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217 \320\267\320\260\321\200\321\217\320\264\320\276\320\262:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-style:italic;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\232\320\275\320\276\320\277\320\272\320\260 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214&quot;</span><span style=\" font-size:8.25pt;\"> \321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320"
                        "\273\321\217 \320\267\320\260\320\277\321\203\321\201\320\272\320\260 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\320\270.  </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\232\320\275\320\276\320\277\320\272\320\260 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\237\320\260\321\203\320\267\320\260&quot;</span><span style=\" font-size:8.25pt;\"> \321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\320\270.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; m"
                        "argin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\232\320\275\320\276\320\277\320\272\320\260 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 x2&quot; </span><span style=\" font-size:8.25pt;\">\321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \321\203\321\201\320\272\320\276\321\200\320\265\320\275\320\270\321\217 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\320\270 \320\262 2 \321\200\320\260\320\267\320\260. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\232\320\275\320\276\320\277\320\272\320\260 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;Edit&quot; </span><span style=\" font-size:8.25pt;\">\320\265\321\211\320\265 \320\275\320\265 \321\200\320\265\320\260\320\273\320\270\320\267\320\276\320\262\320\260\320\275\320\260 :(</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; font-style:italic;\">\320\221\320\273\320\276\320\272 &quot;\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276&quot; \321\201\320\276\320\264\320\265\321\200\320\266\320\270\321\202 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320"
                        "\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\320\270 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217 \320\267\320\260\321\200\321\217\320\264\320\276\320\262.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-style:italic;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\234\320\260\321\200\320\272\320\265\321\200 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\265\321\202\320\272\321\203&quot;</span><span style=\" font-size:8.25pt;\"> \321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \320\276\321\202\320\276\320\261\321"
                        "\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\275\320\276\320\271 \321\201\320\265\321\202\320\272\320\270.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\234\320\260\321\200\320\272\320\265\321\200 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\201\321\202\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \320\277\320\276\320\273\320\265&quot;</span><span style=\" font-size:8.25pt;\"> \321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \320"
                        "\262\321\213\320\262\320\276\320\264\320\260 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\201\321\202\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\277\320\276\320\273\321\217 \320\262 \320\264\320\260\320\275\320\275\321\213\320\271 \320\274\320\276\320\274\320\265\320\275\321\202 \320\262\321\200\320\265\320\274\320\265\320\275\320\270.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\237\320\276\320\273\320\267\321\203\320\275\320\276\320\272 </span><span style=\" font-size:8.25pt; font-weight:600;\">&quot;\320\234\320\260\321\201\321\210\321\202\320\260\320\261&quot;</span><span s"
                        "tyle=\" font-size:8.25pt;\"> \321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \320\277\321\200\320\270\320\261\320\273\320\270\320\266\320\265\320\275\320\270\321\217/\320\276\321\202\320\264\320\260\320\273\320\265\320\275\320\270\321\217 \320\262\320\270\320\264\320\260 \320\276\320\261\320\276\320\267\321\200\320\265\320\262\320\260\320\265\320\274\320\276\320\271 \320\276\320\261\320\273\320\260\321\201\321\202\320\270.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">( \320\235\320\265 \321\200\320\265\320\260\320\273\320\270\320\267\320\276\320\262\320\260\320\275 :(  )</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\"><span style=\" font-size:8.25pt;\">(\320\222\321\213\320\261\320\276\321\200 \320\272\320\260\320\274\320\265\321\200\321\213 \320\270 \321\201\321\206\320\265\320\275\321\213 \321\202\320\276\320\266\320\265 \320\275\320\265 \321\200\320\265\320\260\320\273\320\270\320\267\320\276\320\262\320\260\320\275 \320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\275\320\276 :( )</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-style:italic;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Help", "Okay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
