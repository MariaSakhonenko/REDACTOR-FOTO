#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyGraphicsItems.h"
#include <QScrollBar>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QFontDialog>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QContextMenuEvent>
#include <QGraphicsSceneContextMenuEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    setupGraphicsView();

    ui->comboBoxPenStyle->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    ui->comboBoxPenStyle->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    ui->comboBoxPenStyle->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    ui->comboBoxPenStyle->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
    ui->comboBoxPenStyle->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
    ui->comboBoxPenStyle->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    ui->comboBoxPenCap->addItem(tr("Flat"), Qt::FlatCap);
    ui->comboBoxPenCap->addItem(tr("Square"), Qt::SquareCap);
    ui->comboBoxPenCap->addItem(tr("Round"), Qt::RoundCap);

    ui->comboBoxPenJoin->addItem(tr("Miter"), Qt::MiterJoin);
    ui->comboBoxPenJoin->addItem(tr("Bevel"), Qt::BevelJoin);
    ui->comboBoxPenJoin->addItem(tr("Round"), Qt::RoundJoin);

    ui->comboBoxBrushStyle->addItem(tr("Linear Gradient"), static_cast<int>(Qt::LinearGradientPattern));
    ui->comboBoxBrushStyle->addItem(tr("Radial Gradient"), static_cast<int>(Qt::RadialGradientPattern));
    ui->comboBoxBrushStyle->addItem(tr("Conical Gradient"), static_cast<int>(Qt::ConicalGradientPattern));
    ui->comboBoxBrushStyle->addItem(tr("Texture"), static_cast<int>(Qt::TexturePattern));
    ui->comboBoxBrushStyle->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    ui->comboBoxBrushStyle->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    ui->comboBoxBrushStyle->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    ui->comboBoxBrushStyle->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    ui->comboBoxBrushStyle->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    ui->comboBoxBrushStyle->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    ui->comboBoxBrushStyle->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    ui->comboBoxBrushStyle->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
    ui->comboBoxBrushStyle->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
    ui->comboBoxBrushStyle->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
    ui->comboBoxBrushStyle->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
    ui->comboBoxBrushStyle->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
    ui->comboBoxBrushStyle->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
    ui->comboBoxBrushStyle->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    ui->comboBoxBrushStyle->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    textItemContextMenu = new QMenu("Text Item Context menu", this);
    QAction *textdeleteaction = textItemContextMenu->addAction("Delete Item");
    connect(textdeleteaction, &QAction::triggered, this, [this]() { selectedItem = scene->selectedItems().first(); scene->removeItem(selectedItem); delete selectedItem; });
    QAction *textstyleaction = textItemContextMenu->addAction("Change Font Style");
    connect(textstyleaction, &QAction::triggered, this, &MainWindow::on_actionChange_Font_Style_triggered);
    QAction *textcoloraction = textItemContextMenu->addAction("Change Font Color");
    connect(textcoloraction, &QAction::triggered, this, &MainWindow::on_actionChange_Font_Color_triggered);

    itemContextMenu = new QMenu("Item Context menu", this);
    QAction *deleteaction = itemContextMenu->addAction("Delete Item");
    connect(deleteaction, &QAction::triggered, this, [this]() { selectedItem = scene->selectedItems().first(); scene->removeItem(selectedItem); delete selectedItem; });
    QAction *styleaction = itemContextMenu->addAction("Change Style");
    connect(styleaction, &QAction::triggered, this, &MainWindow::on_actionChange_Style_triggered);

    ui->pushButtonCropSelect->setEnabled(true);
    ui->pushButtonCrop->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupGraphicsView()
{
    // Настраиваем элемент QGraphicsView
    ui->graphicsView->fitInView(scene->sceneRect());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        foreach (QGraphicsItem *item, scene->selectedItems())
        {
            scene->removeItem(item);
            delete item;
        }
    }
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    selectedItem = scene->itemAt(ui->graphicsView->mapToScene(event->pos()), QTransform());
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Images (*.png *.xpm *.jpg)"));
    if (!fileName.isEmpty())
    {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull())
        {
            scene->clear();
            scene->addPixmap(pixmap);
        }
        else
        {
            QMessageBox::warning(this, tr("Error"), tr("Could not load image"));
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Images (*.png *.jpg)"));
    if (!fileName.isEmpty())
    {
        QPixmap pixmap(scene->sceneRect().size().toSize());
        QPainter painter(&pixmap);
        scene->render(&painter);
        pixmap.save(fileName);
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAdd_Text_triggered()
{
    MyGraphicsTextItem *mytext = new MyGraphicsTextItem(ui->lineEditText->text(), getFont(), getFontColor(), textItemContextMenu);
    QGraphicsTextItem *text = qgraphicsitem_cast<QGraphicsTextItem *>(mytext);
    scene->addItem(text);
    text->setFlag(QGraphicsItem::ItemIsMovable);
    text->setFlag(QGraphicsItem::ItemIsSelectable);
    text->setFlag(QGraphicsItem::ItemIsFocusable);
    text->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    text->setTextInteractionFlags(Qt::TextEditorInteraction);
}

void MainWindow::on_actionAdd_Rectangle_triggered()
{
    MyGraphicsRectItem *myrect = new MyGraphicsRectItem(0, 0, 100, 100, getPen(), getBrush(), itemContextMenu);
    QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(myrect);
    scene->addItem(rect);
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    rect->setFlag(QGraphicsItem::ItemIsSelectable);
    rect->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
}

void MainWindow::on_actionAdd_Ellipse_triggered()
{
    MyGraphicsEllipseItem *myellipse = new MyGraphicsEllipseItem(0, 0, 100, 100, getPen(), getBrush(), itemContextMenu);
    QGraphicsEllipseItem *ellipse = qgraphicsitem_cast<QGraphicsEllipseItem *>(myellipse);
    scene->addItem(ellipse);
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    ellipse->setFlag(QGraphicsItem::ItemIsSelectable);
    ellipse->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
}

void MainWindow::on_actionAdd_Triangle_triggered()
{
    QPolygonF triangle;
    triangle << QPointF(0, 0) << QPointF(100, 0) << QPointF(50, 100);
    MyGraphicsPolygonItem *mypolygon = new MyGraphicsPolygonItem(triangle, getPen(), getBrush(), itemContextMenu);
    QGraphicsPolygonItem *polygon = qgraphicsitem_cast<QGraphicsPolygonItem *>(mypolygon);
    scene->addItem(polygon);
    polygon->setFlag(QGraphicsItem::ItemIsMovable);
    polygon->setFlag(QGraphicsItem::ItemIsSelectable);
    polygon->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
}

void MainWindow::on_pushButtonCropSelect_clicked()
{
    if (!cropRect)
    {
        scene->clearSelection();
        cropRect = new MyGraphicsRectItem(QRectF(0, 0, 100, 100));
        cropRect->setPen(QPen(Qt::DashLine));
        cropRect->setBrush(Qt::NoBrush);
        cropRect->setFlag(QGraphicsItem::ItemIsMovable);
        cropRect->setFlag(QGraphicsItem::ItemIsSelectable);
        scene->addItem(cropRect);
        ui->pushButtonCropSelect->setDisabled(true);
        ui->pushButtonCrop->setEnabled(true);
    }
}


void MainWindow::on_pushButtonCrop_clicked()
{
    if (cropRect)
    {
        /*
        QRectF cropArea = cropRect->rect();
        QPixmap pixmap(scene->sceneRect().size().toSize());
        QPainter painter(&pixmap);
        scene->render(&painter);
        pixmap = pixmap.copy(cropArea.toRect());

        scene->clear();
        scene->addPixmap(pixmap);
        delete cropRect;
        cropRect = nullptr;
*/
/*
        QPixmap croppedPixmap = ui->graphicsView->grab(cropRect->rect().toRect());
        scene->clear();
        scene->addPixmap(croppedPixmap);
*/
        delete cropRect;
        cropRect = nullptr;
        ui->pushButtonCropSelect->setEnabled(true);
        ui->pushButtonCrop->setDisabled(true);
    }
}


void MainWindow::on_actionChange_Style_triggered()
{
    selectedItem = scene->selectedItems().first();
    if (!selectedItem)
    {
        QMessageBox::warning(this, tr("No Selection"), tr("Please select an item to change its fill type."));
        return;
    }

    QStringList fillTypes;
    fillTypes << "Solid" << "Gradient" << "Texture";

    bool ok;
    QString selectedFill = QInputDialog::getItem(this, tr("Select Fill Type"), tr("Fill Type:"), fillTypes, 0, false, &ok);

    if (ok && !selectedFill.isEmpty())
    {
        if (selectedFill == "Solid")
        {
            QColor color = QColorDialog::getColor(Qt::white, this, tr("Select Color"));
            if (color.isValid())
            {
                QBrush brush(color);
                if (QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(selectedItem))
                {
                    rect->setBrush(brush);
                }
                else if (QGraphicsEllipseItem *ellipse = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem))
                {
                    ellipse->setBrush(brush);
                }
                else if (QGraphicsPolygonItem *polygon = qgraphicsitem_cast<QGraphicsPolygonItem *>(selectedItem))
                {
                    polygon->setBrush(brush);
                }
            }
        }
        else if (selectedFill == "Gradient")
        {
            QColor color1 = QColorDialog::getColor(Qt::white, this, tr("Select First Color"));
            if (color1.isValid())
            {
                QColor color2 = QColorDialog::getColor(Qt::white, this, tr("Select Second Color"));
                if (color2.isValid())
                {
                    QLinearGradient gradient(0, 0, 100, 100);
                    gradient.setColorAt(0, color1);
                    gradient.setColorAt(1, color2);
                    QBrush brush(gradient);
                    if (QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(selectedItem))
                    {
                        rect->setBrush(brush);
                    }
                    else if (QGraphicsEllipseItem *ellipse = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem))
                    {
                        ellipse->setBrush(brush);
                    }
                    else if (QGraphicsPolygonItem *polygon = qgraphicsitem_cast<QGraphicsPolygonItem *>(selectedItem))
                    {
                        polygon->setBrush(brush);
                    }
                }
            }
        }
        else if (selectedFill == "Texture")
        {
            QString fileName = QFileDialog::getOpenFileName(this, tr("Open Texture File"), "", tr("Images (*.png *.jpg)"));
            if (!fileName.isEmpty())
            {
                QPixmap texture(fileName);
                if (!texture.isNull())
                {
                    QBrush brush(texture);
                    if (QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(selectedItem))
                    {
                        rect->setBrush(brush);
                    }
                    else if (QGraphicsEllipseItem *ellipse = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem))
                    {
                        ellipse->setBrush(brush);
                    }
                    else if (QGraphicsPolygonItem *polygon = qgraphicsitem_cast<QGraphicsPolygonItem *>(selectedItem))
                    {
                        polygon->setBrush(brush);
                    }
                }
                else
                {
                    QMessageBox::warning(this, tr("Error"), tr("Could not load texture"));
                }
            }
        }
    }
}

void MainWindow::on_actionChange_Font_Style_triggered()
{
    selectedItem = scene->selectedItems().first();
    if (!selectedItem)
    {
        QMessageBox::warning(this, tr("No Selection"), tr("Please select an item to change its Font Style."));
        return;
    }

    if (QGraphicsTextItem *text = qgraphicsitem_cast<QGraphicsTextItem *>(selectedItem))
    {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, text->font(), this);
        if (ok)
        {
            text->setFont(font);
        }
    }
}

void MainWindow::on_actionChange_Font_Color_triggered()
{
    selectedItem = scene->selectedItems().first();
    if (!selectedItem)
    {
        QMessageBox::warning(this, tr("No Selection"), tr("Please select an item to change its fill type."));
        return;
    }

    QColor color = QColorDialog::getColor(Qt::white, this, tr("Select Color"));
    if (color.isValid())
    {
        if (QGraphicsTextItem *text = qgraphicsitem_cast<QGraphicsTextItem *>(selectedItem))
        {
            text->setDefaultTextColor(color);
        }
    }
}

void MainWindow::on_clearButton_clicked()
{
    scene->clear();
}

void MainWindow::on_pushButtonPenColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->pushButtonPenColor->palette().buttonText().color(), this, tr("Select Color"));
    if (color.isValid())
    {
        QPalette pal = ui->pushButtonPenColor->palette();
        pal.setColor(QPalette::ButtonText, color);
        ui->pushButtonPenColor->setPalette(pal);
        ui->pushButtonPenColor->update();
    }
}

void MainWindow::on_pushButtonBrushColor1_clicked()
{
    QColor color = QColorDialog::getColor(ui->pushButtonBrushColor1->palette().buttonText().color(), this, tr("Select Color"));
    if (color.isValid())
    {
        QPalette pal = ui->pushButtonBrushColor1->palette();
        pal.setColor(QPalette::ButtonText, color);
        ui->pushButtonBrushColor1->setPalette(pal);
        ui->pushButtonBrushColor1->update();
    }
}

void MainWindow::on_pushButtonBrushColor2_clicked()
{
    QColor color = QColorDialog::getColor(ui->pushButtonBrushColor2->palette().buttonText().color(), this, tr("Select Color"));
    if (color.isValid())
    {
        QPalette pal = ui->pushButtonBrushColor2->palette();
        pal.setColor(QPalette::ButtonText, color);
        ui->pushButtonBrushColor2->setPalette(pal);
        ui->pushButtonBrushColor2->update();
    }
}

void MainWindow::on_pushButtonTextColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->pushButtonTextColor->palette().buttonText().color(), this, tr("Select Color"));
    if (color.isValid())
    {
        QPalette pal = ui->pushButtonTextColor->palette();
        pal.setColor(QPalette::ButtonText, color);
        ui->pushButtonTextColor->setPalette(pal);
        ui->pushButtonTextColor->update();
    }
}

QPen MainWindow::getPen()
{
    int width = ui->horizontalSliderPenWidth->value();
    Qt::PenStyle penstyle = Qt::PenStyle(ui->comboBoxPenStyle->itemData(ui->comboBoxPenStyle->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(ui->comboBoxPenCap->itemData(ui->comboBoxPenCap->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(ui->comboBoxPenJoin->itemData(ui->comboBoxPenJoin->currentIndex(), Qt::UserRole).toInt());
    return QPen(ui->pushButtonPenColor->palette().buttonText().color(), width, penstyle, cap, join);
}

QBrush MainWindow::getBrush()
{
    QBrush brush;
    Qt::BrushStyle brushstyle = Qt::BrushStyle(ui->comboBoxBrushStyle->itemData(ui->comboBoxBrushStyle->currentIndex(), Qt::UserRole).toInt());
    if (brushstyle == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, ui->pushButtonBrushColor1->palette().buttonText().color());
        linearGradient.setColorAt(1.0, ui->pushButtonBrushColor2->palette().buttonText().color());
        brush = linearGradient;
    } else if (brushstyle == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, ui->pushButtonBrushColor1->palette().buttonText().color());
        radialGradient.setColorAt(1.0, ui->pushButtonBrushColor2->palette().buttonText().color());
        brush = radialGradient;
    } else if (brushstyle == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, ui->pushButtonBrushColor1->palette().buttonText().color());
        conicalGradient.setColorAt(1.0, ui->pushButtonBrushColor2->palette().buttonText().color());
        brush = conicalGradient;
    } else {
        brush = QBrush(ui->pushButtonBrushColor1->palette().buttonText().color(), brushstyle);
    }
    return brush;
}

QFont MainWindow::getFont()
{
    QFont font(ui->fontComboBoxFont->currentFont());
    font.setPixelSize(ui->spinBoxFontSize->value());
    return font;
}

QColor MainWindow::getFontColor()
{
    return QColor(ui->pushButtonTextColor->palette().buttonText().color());
}
