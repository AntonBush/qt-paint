#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workspace.h"
#include "penciltool.h"

#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    workspace = new Workspace(this);
    ui->graphicsView->setScene(workspace);
    ui->graphicsView->setSceneRect(Workspace::defaultWorkspaceRect);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pencilToolButton_clicked()
{
    int width = ui->comboBoxWidth->currentIndex() + 1;
    workspace->setActiveTool(std::make_shared<PencilTool>(workspace->getCanvas(), Qt::black, width));
}


void MainWindow::on_eraserToolButton_clicked()
{
    int width = ui->comboBoxWidth->currentIndex() + 1;
    workspace->setActiveTool(std::make_shared<PencilTool>(workspace->getCanvas(), Qt::white, width));
}

