/********************************************************************************
** Form generated from reading UI file 'AddWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

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

class Ui_Add_window
{
public:
    QGridLayout *gridLayout;
    QRadioButton *RLERadioButton;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *BrowseLineEdit;
    QLineEdit *AppendLineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *BrowseButton;
    QPushButton *AppendButton;
    QRadioButton *HuffmanRadioButton;
    QLabel *dPath;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Ok;

    void setupUi(QDialog *Add_window)
    {
        if (Add_window->objectName().isEmpty())
            Add_window->setObjectName(QString::fromUtf8("Add_window"));
        Add_window->resize(526, 328);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/img/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        Add_window->setWindowIcon(icon);
        gridLayout = new QGridLayout(Add_window);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RLERadioButton = new QRadioButton(Add_window);
        RLERadioButton->setObjectName(QString::fromUtf8("RLERadioButton"));
        QFont font;
        font.setPointSize(11);
        RLERadioButton->setFont(font);
        RLERadioButton->setCheckable(true);
        RLERadioButton->setChecked(true);

        gridLayout->addWidget(RLERadioButton, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BrowseLineEdit = new QLineEdit(Add_window);
        BrowseLineEdit->setObjectName(QString::fromUtf8("BrowseLineEdit"));
        BrowseLineEdit->setFont(font);

        verticalLayout_2->addWidget(BrowseLineEdit);

        AppendLineEdit = new QLineEdit(Add_window);
        AppendLineEdit->setObjectName(QString::fromUtf8("AppendLineEdit"));
        AppendLineEdit->setFont(font);

        verticalLayout_2->addWidget(AppendLineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        BrowseButton = new QPushButton(Add_window);
        BrowseButton->setObjectName(QString::fromUtf8("BrowseButton"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setKerning(true);
        BrowseButton->setFont(font1);
        BrowseButton->setCursor(QCursor(Qt::PointingHandCursor));
        BrowseButton->setAutoDefault(true);

        verticalLayout->addWidget(BrowseButton);

        AppendButton = new QPushButton(Add_window);
        AppendButton->setObjectName(QString::fromUtf8("AppendButton"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        AppendButton->setFont(font2);
        AppendButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(AppendButton);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        HuffmanRadioButton = new QRadioButton(Add_window);
        HuffmanRadioButton->setObjectName(QString::fromUtf8("HuffmanRadioButton"));
        HuffmanRadioButton->setEnabled(true);
        HuffmanRadioButton->setFont(font);
        HuffmanRadioButton->setCheckable(true);
        HuffmanRadioButton->setChecked(false);

        gridLayout->addWidget(HuffmanRadioButton, 3, 0, 1, 1);

        dPath = new QLabel(Add_window);
        dPath->setObjectName(QString::fromUtf8("dPath"));
        dPath->setFont(font);

        gridLayout->addWidget(dPath, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(498, 86, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(366, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Ok = new QPushButton(Add_window);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setFont(font);

        horizontalLayout_2->addWidget(Ok);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 1);


        retranslateUi(Add_window);

        QMetaObject::connectSlotsByName(Add_window);
    } // setupUi

    void retranslateUi(QDialog *Add_window)
    {
        Add_window->setWindowTitle(QApplication::translate("Add_window", "Archive name", nullptr));
        RLERadioButton->setText(QApplication::translate("Add_window", "RLE", nullptr));
        BrowseButton->setText(QApplication::translate("Add_window", "Browse", nullptr));
        AppendButton->setText(QApplication::translate("Add_window", "Append..", nullptr));
        HuffmanRadioButton->setText(QApplication::translate("Add_window", "Huffman", nullptr));
        dPath->setText(QApplication::translate("Add_window", "Archive name", nullptr));
        Ok->setText(QApplication::translate("Add_window", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_window: public Ui_Add_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
