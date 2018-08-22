#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editor.h"
#include "block.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>

namespace Ui { class xMainWindow; }

class xMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit xMainWindow(QWidget *parent = nullptr);
    ~xMainWindow();
    void getImgFiles();

    void mousePressEvent(QMouseEvent *e);

private slots:

    void on_ImagesList_currentTextChanged(const QString &arg1);

    void on_placeBlock_clicked();

private:
    Ui::xMainWindow *ui;
    QPoint clickedPt;
    xBlock *block;
};

#endif // MAINWINDOW_H
