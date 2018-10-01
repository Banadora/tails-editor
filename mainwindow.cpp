#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editor.h"

#include <QDir>
#include <QString>
#include <QIcon>
#include <QDebug>

xEditor *editor;

xMainWindow::xMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::xMainWindow)
{
    ui->setupUi(this);

    editor = new xEditor(ui->view->width()-2, ui->view->height()-2);
    editor->scene->setBackgroundBrush(QBrush(QImage(":/img/background.png")));
    ui->view->setScene(editor->scene);

    focusedBox = 1; //1:blocks, 2:enemies
    getImgFiles();
}

xMainWindow::~xMainWindow() {
    delete ui;
}

void xMainWindow::getImgFiles() {
    //get all blocks images
    QDir directory(":/img");
    QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    foreach (QString filename, images) {
        if (filename != "background.png" && filename != "selection.png" && filename != "redfilter.png") {
            ui->ImagesList_blocks->addItem(filename);
        }
    }
    ui->blockIcon->setIcon(QIcon(":/img/blank.png"));

    //get all enemies images
    directory.setPath(":/img/enemies");
    images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    foreach (QString filename, images) {
            ui->ImagesList_enemies->addItem(filename);
    }
    ui->enemyIcon->setIcon(QIcon(":/img/blank.png"));
}

void xMainWindow::mousePressEvent(QMouseEvent *e) {
    if (    (e->pos().x() >= 0)  &&  (e->pos().x() <= nbBlocksX*PixelsX)  &&  (e->pos().y() >= 0)  &&  (e->pos().y() <= nbBlocksY*PixelsY)    ) {
        qDebug() << "~~~~ New click ~~~~";
        clickedPt = e->pos();
        qDebug() << clickedPt;
        editor->setSelectPos(e->pos().x(), e->pos().y());
    }

    setFocus(); //free focus of other items when clicking on void spot
}

void xMainWindow::on_ImagesList_blocks_currentTextChanged(const QString &arg1) {
    focusedBox = 1;
    ui->blockIcon->setIcon(QIcon(":/img/" + arg1));
}

void xMainWindow::on_placeBtn_clicked() {
    if (focusedBox==1) { editor->placeBlock(ui->ImagesList_blocks->currentText(), ui->isObstacleBox->checkState()); }
    else if (focusedBox==2) { editor->placeEnemy(ui->ImagesList_enemies->currentText()); }
}

void xMainWindow::on_deleteBtn_clicked() {
    if (focusedBox==1) { editor->placeBlock("blank", true); }
}

void xMainWindow::on_fillBtn_clicked() {
    if (focusedBox==1) { editor->fillMap(ui->ImagesList_blocks->currentText(), ui->isObstacleBox->checkState()); }
}

void xMainWindow::on_clearBtn_clicked() {
    if (focusedBox==1) { editor->fillMap("blank", true); }
}

void xMainWindow::on_saveBtn_clicked() {
    editor->saveMap(ui->nameEdit->text());
}

void xMainWindow::on_loadBtn_clicked() {
    editor->loadMap(ui->nameEdit->text());
}

void xMainWindow::on_ImagesList_enemies_currentTextChanged(const QString &arg1)
{
    focusedBox = 2;
    ui->enemyIcon->setIcon(QIcon(":/img/enemies/" + arg1));
}
