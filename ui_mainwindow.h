/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAdd_Rectangle;
    QAction *actionAdd_Ellipse;
    QAction *actionAdd_Triangle;
    QAction *actionAdd_Text;
    QAction *actionClear;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayoutPenSettings;
    QVBoxLayout *verticalLayoutPenLabels;
    QLabel *labelPenWidth;
    QLabel *labelPenStyle;
    QLabel *labelPenCap;
    QLabel *labelPenJoin;
    QLabel *labelPenColor;
    QLabel *labelBrushStyle;
    QLabel *labelBrushColor1;
    QLabel *labelBrushColor2;
    QVBoxLayout *verticalLayoutPenSettings;
    QSlider *horizontalSliderPenWidth;
    QComboBox *comboBoxPenStyle;
    QComboBox *comboBoxPenCap;
    QComboBox *comboBoxPenJoin;
    QPushButton *pushButtonPenColor;
    QComboBox *comboBoxBrushStyle;
    QPushButton *pushButtonBrushColor1;
    QPushButton *pushButtonBrushColor2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayoutTextSettings;
    QVBoxLayout *verticalLayoutTextLabels;
    QLabel *labelText;
    QLabel *labelFont;
    QLabel *labelFontSize;
    QLabel *labelColor;
    QVBoxLayout *verticalLayoutTextSettings;
    QLineEdit *lineEditText;
    QFontComboBox *fontComboBoxFont;
    QSpinBox *spinBoxFontSize;
    QPushButton *pushButtonTextColor;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonCropSelect;
    QPushButton *pushButtonCrop;
    QPushButton *clearButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(999, 578);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAdd_Rectangle = new QAction(MainWindow);
        actionAdd_Rectangle->setObjectName("actionAdd_Rectangle");
        actionAdd_Ellipse = new QAction(MainWindow);
        actionAdd_Ellipse->setObjectName("actionAdd_Ellipse");
        actionAdd_Triangle = new QAction(MainWindow);
        actionAdd_Triangle->setObjectName("actionAdd_Triangle");
        actionAdd_Text = new QAction(MainWindow);
        actionAdd_Text->setObjectName("actionAdd_Text");
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayoutPenSettings = new QHBoxLayout();
        horizontalLayoutPenSettings->setSpacing(6);
        horizontalLayoutPenSettings->setObjectName("horizontalLayoutPenSettings");
        verticalLayoutPenLabels = new QVBoxLayout();
        verticalLayoutPenLabels->setSpacing(6);
        verticalLayoutPenLabels->setObjectName("verticalLayoutPenLabels");
        labelPenWidth = new QLabel(centralwidget);
        labelPenWidth->setObjectName("labelPenWidth");

        verticalLayoutPenLabels->addWidget(labelPenWidth);

        labelPenStyle = new QLabel(centralwidget);
        labelPenStyle->setObjectName("labelPenStyle");

        verticalLayoutPenLabels->addWidget(labelPenStyle);

        labelPenCap = new QLabel(centralwidget);
        labelPenCap->setObjectName("labelPenCap");

        verticalLayoutPenLabels->addWidget(labelPenCap);

        labelPenJoin = new QLabel(centralwidget);
        labelPenJoin->setObjectName("labelPenJoin");

        verticalLayoutPenLabels->addWidget(labelPenJoin);

        labelPenColor = new QLabel(centralwidget);
        labelPenColor->setObjectName("labelPenColor");

        verticalLayoutPenLabels->addWidget(labelPenColor);

        labelBrushStyle = new QLabel(centralwidget);
        labelBrushStyle->setObjectName("labelBrushStyle");

        verticalLayoutPenLabels->addWidget(labelBrushStyle);

        labelBrushColor1 = new QLabel(centralwidget);
        labelBrushColor1->setObjectName("labelBrushColor1");

        verticalLayoutPenLabels->addWidget(labelBrushColor1);

        labelBrushColor2 = new QLabel(centralwidget);
        labelBrushColor2->setObjectName("labelBrushColor2");

        verticalLayoutPenLabels->addWidget(labelBrushColor2);


        horizontalLayoutPenSettings->addLayout(verticalLayoutPenLabels);

        verticalLayoutPenSettings = new QVBoxLayout();
        verticalLayoutPenSettings->setSpacing(6);
        verticalLayoutPenSettings->setObjectName("verticalLayoutPenSettings");
        horizontalSliderPenWidth = new QSlider(centralwidget);
        horizontalSliderPenWidth->setObjectName("horizontalSliderPenWidth");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSliderPenWidth->sizePolicy().hasHeightForWidth());
        horizontalSliderPenWidth->setSizePolicy(sizePolicy);
        horizontalSliderPenWidth->setMinimum(1);
        horizontalSliderPenWidth->setMaximum(10);
        horizontalSliderPenWidth->setValue(2);
        horizontalSliderPenWidth->setOrientation(Qt::Orientation::Horizontal);
        horizontalSliderPenWidth->setTickPosition(QSlider::TickPosition::TicksAbove);
        horizontalSliderPenWidth->setTickInterval(2);

        verticalLayoutPenSettings->addWidget(horizontalSliderPenWidth);

        comboBoxPenStyle = new QComboBox(centralwidget);
        comboBoxPenStyle->setObjectName("comboBoxPenStyle");

        verticalLayoutPenSettings->addWidget(comboBoxPenStyle);

        comboBoxPenCap = new QComboBox(centralwidget);
        comboBoxPenCap->setObjectName("comboBoxPenCap");

        verticalLayoutPenSettings->addWidget(comboBoxPenCap);

        comboBoxPenJoin = new QComboBox(centralwidget);
        comboBoxPenJoin->setObjectName("comboBoxPenJoin");

        verticalLayoutPenSettings->addWidget(comboBoxPenJoin);

        pushButtonPenColor = new QPushButton(centralwidget);
        pushButtonPenColor->setObjectName("pushButtonPenColor");

        verticalLayoutPenSettings->addWidget(pushButtonPenColor);

        comboBoxBrushStyle = new QComboBox(centralwidget);
        comboBoxBrushStyle->setObjectName("comboBoxBrushStyle");

        verticalLayoutPenSettings->addWidget(comboBoxBrushStyle);

        pushButtonBrushColor1 = new QPushButton(centralwidget);
        pushButtonBrushColor1->setObjectName("pushButtonBrushColor1");
        pushButtonBrushColor1->setAutoFillBackground(false);
        pushButtonBrushColor1->setStyleSheet(QString::fromUtf8(""));

        verticalLayoutPenSettings->addWidget(pushButtonBrushColor1);

        pushButtonBrushColor2 = new QPushButton(centralwidget);
        pushButtonBrushColor2->setObjectName("pushButtonBrushColor2");

        verticalLayoutPenSettings->addWidget(pushButtonBrushColor2);


        horizontalLayoutPenSettings->addLayout(verticalLayoutPenSettings);


        horizontalLayout->addLayout(horizontalLayoutPenSettings);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayoutTextSettings = new QHBoxLayout();
        horizontalLayoutTextSettings->setSpacing(6);
        horizontalLayoutTextSettings->setObjectName("horizontalLayoutTextSettings");
        verticalLayoutTextLabels = new QVBoxLayout();
        verticalLayoutTextLabels->setSpacing(6);
        verticalLayoutTextLabels->setObjectName("verticalLayoutTextLabels");
        labelText = new QLabel(centralwidget);
        labelText->setObjectName("labelText");

        verticalLayoutTextLabels->addWidget(labelText);

        labelFont = new QLabel(centralwidget);
        labelFont->setObjectName("labelFont");

        verticalLayoutTextLabels->addWidget(labelFont);

        labelFontSize = new QLabel(centralwidget);
        labelFontSize->setObjectName("labelFontSize");

        verticalLayoutTextLabels->addWidget(labelFontSize);

        labelColor = new QLabel(centralwidget);
        labelColor->setObjectName("labelColor");

        verticalLayoutTextLabels->addWidget(labelColor);


        horizontalLayoutTextSettings->addLayout(verticalLayoutTextLabels);

        verticalLayoutTextSettings = new QVBoxLayout();
        verticalLayoutTextSettings->setSpacing(6);
        verticalLayoutTextSettings->setObjectName("verticalLayoutTextSettings");
        lineEditText = new QLineEdit(centralwidget);
        lineEditText->setObjectName("lineEditText");
        sizePolicy.setHeightForWidth(lineEditText->sizePolicy().hasHeightForWidth());
        lineEditText->setSizePolicy(sizePolicy);

        verticalLayoutTextSettings->addWidget(lineEditText);

        fontComboBoxFont = new QFontComboBox(centralwidget);
        fontComboBoxFont->setObjectName("fontComboBoxFont");

        verticalLayoutTextSettings->addWidget(fontComboBoxFont);

        spinBoxFontSize = new QSpinBox(centralwidget);
        spinBoxFontSize->setObjectName("spinBoxFontSize");
        spinBoxFontSize->setValue(16);

        verticalLayoutTextSettings->addWidget(spinBoxFontSize);

        pushButtonTextColor = new QPushButton(centralwidget);
        pushButtonTextColor->setObjectName("pushButtonTextColor");

        verticalLayoutTextSettings->addWidget(pushButtonTextColor);


        horizontalLayoutTextSettings->addLayout(verticalLayoutTextSettings);


        verticalLayout_3->addLayout(horizontalLayoutTextSettings);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonCropSelect = new QPushButton(centralwidget);
        pushButtonCropSelect->setObjectName("pushButtonCropSelect");

        verticalLayout_2->addWidget(pushButtonCropSelect);

        pushButtonCrop = new QPushButton(centralwidget);
        pushButtonCrop->setObjectName("pushButtonCrop");

        verticalLayout_2->addWidget(pushButtonCrop);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        verticalLayout_2->addWidget(clearButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 999, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        labelPenStyle->setBuddy(comboBoxPenStyle);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionAdd_Rectangle);
        menuEdit->addAction(actionAdd_Ellipse);
        menuEdit->addAction(actionAdd_Triangle);
        menuEdit->addAction(actionAdd_Text);
        menuEdit->addSeparator();
        menuEdit->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAdd_Rectangle->setText(QCoreApplication::translate("MainWindow", "Add Rectangle", nullptr));
        actionAdd_Ellipse->setText(QCoreApplication::translate("MainWindow", "Add Ellipse", nullptr));
        actionAdd_Triangle->setText(QCoreApplication::translate("MainWindow", "Add Triangle", nullptr));
        actionAdd_Text->setText(QCoreApplication::translate("MainWindow", "Add Text", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        labelPenWidth->setText(QCoreApplication::translate("MainWindow", "Pen Width", nullptr));
        labelPenStyle->setText(QCoreApplication::translate("MainWindow", "Pen Style", nullptr));
        labelPenCap->setText(QCoreApplication::translate("MainWindow", "Pen Cap", nullptr));
        labelPenJoin->setText(QCoreApplication::translate("MainWindow", "Pen Join", nullptr));
        labelPenColor->setText(QCoreApplication::translate("MainWindow", "Pen Color", nullptr));
        labelBrushStyle->setText(QCoreApplication::translate("MainWindow", "Brush Style", nullptr));
        labelBrushColor1->setText(QCoreApplication::translate("MainWindow", "Brush Color 1", nullptr));
        labelBrushColor2->setText(QCoreApplication::translate("MainWindow", "Brush Color 2", nullptr));
        pushButtonPenColor->setText(QCoreApplication::translate("MainWindow", "Pen Color", nullptr));
        pushButtonBrushColor1->setText(QCoreApplication::translate("MainWindow", "Brush Color 1", nullptr));
        pushButtonBrushColor2->setText(QCoreApplication::translate("MainWindow", "Brush Color 2", nullptr));
        labelText->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        labelFont->setText(QCoreApplication::translate("MainWindow", "Font", nullptr));
        labelFontSize->setText(QCoreApplication::translate("MainWindow", "Font Size", nullptr));
        labelColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        lineEditText->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        pushButtonTextColor->setText(QCoreApplication::translate("MainWindow", "Text Color", nullptr));
        pushButtonCropSelect->setText(QCoreApplication::translate("MainWindow", "Select Crop Area", nullptr));
        pushButtonCrop->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
