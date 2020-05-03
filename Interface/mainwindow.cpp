#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->m_show_grid->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showGrid(int val)
{
    ui->m_engine->setDrawGrid(val == Qt::Checked);
    ui->m_engine->repaint();
}
