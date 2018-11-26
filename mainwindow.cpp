#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editor.h"
#include "weapon.h"

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
    QDir directory(":/img/blocks");
    QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    foreach (QString filename, images) {
            filename.remove(".png");
            ui->ImagesList_blocks->addItem(filename);
    }
    ui->blockIcon->setIcon(QIcon(":/img/blocks/blank.png"));

    //get all enemies images
    directory.setPath(":/img/enemies");
    images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    foreach (QString filename, images) {
            filename.remove(".png");
            ui->ImagesList_enemies->addItem(filename);
    }
    ui->enemyIcon->setIcon(QIcon(":/img/enemies/blank.png"));

    //get all enemies weapons
    directory.setPath(":/anim");
    images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    foreach (QString filename, images) {
            filename.remove(".png");
            ui->WeaponsList_enemies->addItem(filename);
    }
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
    ui->blockIcon->setIcon(QIcon(":/img/blocks/" + arg1));
}

void xMainWindow::on_placeBtn_clicked() {
    if (focusedBox==1) { editor->placeBlock(ui->ImagesList_blocks->currentText(), ui->isObstacleBox->checkState()); }
    else if (focusedBox==2) { editor->placeEnemy(ui->ImagesList_enemies->currentText(), ui->enemyHP->value(), ui->WeaponsList_enemies->currentText()); }
}

void xMainWindow::on_deleteBtn_clicked() {
    if (focusedBox==1) { editor->placeBlock("blank", true); }
    else if (focusedBox==2) { editor->placeEnemy("blank", 0, 0); }
}

void xMainWindow::on_fillBtn_clicked() {
    if (focusedBox==1) { editor->fillMap(ui->ImagesList_blocks->currentText(), ui->isObstacleBox->checkState()); }
}

void xMainWindow::on_clearBtn_clicked() {
    if (focusedBox==1) { editor->fillMap("blank", true); }
}

void xMainWindow::on_saveBtn_clicked() {
    editor->saveMap(ui->nameEdit->text(), ui->nameNorth->text(), ui->nameEast->text(), ui->nameSouth->text(), ui->nameWest->text());
}

void xMainWindow::on_loadBtn_clicked() {
    editor->loadMap(ui->nameEdit->text());
    ui->nameNorth->setText(editor->map->getMapNorth());
    ui->nameEast->setText(editor->map->getMapEast());
    ui->nameSouth->setText(editor->map->getMapSouth());
    ui->nameWest->setText(editor->map->getMapWest());
}

void xMainWindow::on_ImagesList_enemies_currentTextChanged(const QString &arg1)
{
    focusedBox = 2;
    ui->enemyIcon->setIcon(QIcon(":/img/enemies/" + arg1));
}

void xMainWindow::on_WeaponsList_enemies_currentTextChanged(const QString &arg1)
{
    xWeapon weapon;
    ui->enemyDmg->setValue(weapon.getDmg(ui->WeaponsList_enemies->currentText()));

    qDebug() << "Weapon text :" + ui->WeaponsList_enemies->currentText();
    qDebug() << "Weapon dmg : " + QString::number(weapon.getDmg(ui->WeaponsList_enemies->currentText()));
}
