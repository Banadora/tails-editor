#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editor.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>

namespace Ui { class xMainWindow; }

class xMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit xMainWindow(QWidget *parent = nullptr);
    ~xMainWindow();
    void getImgFiles();

    void mousePressEvent(QMouseEvent *e);

public slots:
    void on_ImagesList_currentTextChanged(const QString &arg1);
    void on_placeBtn_clicked();
    void on_deleteBtn_clicked();
    void on_fillBtn_clicked();
    void on_clearBtn_clicked();

private slots:

    void on_saveBtn_clicked();

private:
    Ui::xMainWindow *ui;
    QPoint clickedPt;
};

#endif // MAINWINDOW_H
