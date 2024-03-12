#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DSI_Debug.h"
#include <QPainter>
#include "BasicAlgorithm.h"

class Grids_V : public QMainWindow
{
    Q_OBJECT

public:
    Grids_V(QWidget *parent = Q_NULLPTR);
    int outfilepath_num;
    void Readfile(std::string p);
    double Dist(double x1, double x2, double y1, double y2);
    int have;

private slots:
    void on_open_clicked();
    void on_close_clicked();
    void on_clear_clicked();
    void on_IDW_clicked();
    void Showpointset();
    void Creatbody();
    void CreateGrids();
    void CreateGrids1();
    void G_IN_Poly();
    void MMM();

    void paintEvent(QPaintEvent*);

private:
    Ui::DSI_DebugClass ui;
    QString file_path_;
};
