/********************************************************************************
** Form generated from reading UI file 'ExtractWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRACTWINDOW_H
#define UI_EXTRACTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Extract_window
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *BrowseLineEdit;
    QLineEdit *AppendLineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *BrowseButton;
    QPushButton *AppendButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OK;
    QRadioButton *RLERadioButton;
    QRadioButton *HuffmanRadioButton;
    QLabel *dPath;

    void setupUi(QDialog *Extract_window)
    {
        if (Extract_window->objectName().isEmpty())
            Extract_window->setObjectName(QString::fromUtf8("Extract_window"));
        Extract_window->resize(602, 361);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/img/ExtractTo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Extract_window->setWindowIcon(icon);
        gridLayout = new QGridLayout(Extract_window);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BrowseLineEdit = new QLineEdit(Extract_window);
        BrowseLineEdit->setObjectName(QString::fromUtf8("BrowseLineEdit"));
        QFont font;
        font.setPointSize(11);
        BrowseLineEdit->setFont(font);

        verticalLayout_2->addWidget(BrowseLineEdit);

        AppendLineEdit = new QLineEdit(Extract_window);
        AppendLineEdit->setObjectName(QString::fromUtf8("AppendLineEdit"));
        AppendLineEdit->setFont(font);

        verticalLayout_2->addWidget(AppendLineEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        BrowseButton = new QPushButton(Extract_window);
        BrowseButton->setObjectName(QString::fromUtf8("BrowseButton"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        BrowseButton->setFont(font1);

        verticalLayout->addWidget(BrowseButton);

        AppendButton = new QPushButton(Extract_window);
        AppendButton->setObjectName(QString::fromUtf8("AppendButton"));
        AppendButton->setFont(font1);

        verticalLayout->addWidget(AppendButton);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 225, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(757, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OK = new QPushButton(Extract_window);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setFont(font);

        horizontalLayout->addWidget(OK);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        RLERadioButton = new QRadioButton(Extract_window);
        RLERadioButton->setObjectName(QString::fromUtf8("RLERadioButton"));
        RLERadioButton->setFont(font);
        RLERadioButton->setCheckable(true);
        RLERadioButton->setChecked(true);

        gridLayout->addWidget(RLERadioButton, 2, 0, 1, 1);

        HuffmanRadioButton = new QRadioButton(Extract_window);
        HuffmanRadioButton->setObjectName(QString::fromUtf8("HuffmanRadioButton"));
        HuffmanRadioButton->setEnabled(true);
        HuffmanRadioButton->setFont(font);
        HuffmanRadioButton->setChecked(false);

        gridLayout->addWidget(HuffmanRadioButton, 3, 0, 1, 1);

        dPath = new QLabel(Extract_window);
        dPath->setObjectName(QString::fromUtf8("dPath"));
        dPath->setFont(font);

        gridLayout->addWidget(dPath, 0, 0, 1, 1);


        retranslateUi(Extract_window);

        QMetaObject::connectSlotsByName(Extract_window);
    } // setupUi

    void retranslateUi(QDialog *Extract_window)
    {
        Extract_window->setWindowTitle(QApplication::translate("Extract_window", "Extract to...", nullptr));
        BrowseButton->setText(QApplication::translate("Extract_window", "Browse", nullptr));
        AppendButton->setText(QApplication::translate("Extract_window", "Append..", nullptr));
        OK->setText(QApplication::translate("Extract_window", "OK", nullptr));
        RLERadioButton->setText(QApplication::translate("Extract_window", "RLE decompress", nullptr));
        HuffmanRadioButton->setText(QApplication::translate("Extract_window", "Huffman decompress", nullptr));
        dPath->setText(QApplication::translate("Extract_window", "Destination path", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Extract_window: public Ui_Extract_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRACTWINDOW_H
