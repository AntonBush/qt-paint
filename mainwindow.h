#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "workspace.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pencilToolButton_clicked();

    void on_eraserToolButton_clicked();

private:
    Ui::MainWindow *ui;
    Workspace * workspace;
};
#endif // MAINWINDOW_H
