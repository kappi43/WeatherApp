#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <engine.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setTemp(double temperature);
    ~MainWindow();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
    Engine engine;
};
#endif // MAINWINDOW_H
