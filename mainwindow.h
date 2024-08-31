#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MyGraphicsItems.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QInputDialog>
#include <QGraphicsSceneContextMenuEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();
    void on_actionAdd_Text_triggered();
    void on_actionAdd_Rectangle_triggered();
    void on_actionAdd_Ellipse_triggered();
    void on_actionAdd_Triangle_triggered();
    void on_clearButton_clicked();
    void on_actionChange_Style_triggered();
    void on_actionChange_Font_Style_triggered();
    void on_actionChange_Font_Color_triggered();
    void on_pushButtonPenColor_clicked();
    void on_pushButtonBrushColor1_clicked();
    void on_pushButtonBrushColor2_clicked();
    void on_pushButtonTextColor_clicked();   
    void on_pushButtonCropSelect_clicked();
    void on_pushButtonCrop_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MyGraphicsRectItem *cropRect = nullptr;
    QGraphicsItem *selectedItem = nullptr;

    QMenu *textItemContextMenu;
    QMenu *itemContextMenu;

    void setupGraphicsView();

    QPen getPen();
    QBrush getBrush();
    QFont getFont();
    QColor getFontColor();
};

#endif // MAINWINDOW_H
