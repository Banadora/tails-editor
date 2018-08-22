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

    getImgFiles();
}

xMainWindow::~xMainWindow() {
    delete ui;
    delete block;
}

void xMainWindow::getImgFiles() {
    //assume the directory exists and contains some files and you want all jpg and JPG files
    QDir directory(":/img");
    QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    foreach (QString filename, images) {
        if (filename != "background.png" && filename != "selection.png") {
            ui->ImagesList->addItem(filename);
        }
    }
    ui->blockIcon->setIcon(QIcon(":/img/blank.png"));
}

void xMainWindow::mousePressEvent(QMouseEvent *e) {
    qDebug() << "~~~~ New click ~~~~";
    clickedPt = e->pos();
    qDebug() << clickedPt;
    editor->setSelectPos(e->pos().x(), e->pos().y());
}

void xMainWindow::on_ImagesList_currentTextChanged(const QString &arg1) {
    ui->blockIcon->setIcon(QIcon(":/img/" + arg1));
}

void xMainWindow::on_placeBlock_clicked() {
    block = new xBlock(ui->ImagesList->currentText(), ui->isObstacleBox);
    qDebug() << ui->ImagesList->currentText();
    block->setPos(editor->selection->pos().x(), editor->selection->pos().y());
    editor->scene->addItem(block);
}
