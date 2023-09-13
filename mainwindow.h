#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scalefinder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void output(int index);
    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_min_clicked();

    void on_maj_clicked();

private:
    Ui::MainWindow *ui;
    ScaleFinder sf;
    void setTable();
    void setComboBox();

};
#endif // MAINWINDOW_H
