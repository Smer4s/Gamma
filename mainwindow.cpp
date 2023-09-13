#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtablewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setTable();
    this->setComboBox();
    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle("Gamma");
    this->setWindowIcon(QIcon(":/Images/Icon.png"));
}

void MainWindow::output(int index)
{
    bool major = ui->maj->isChecked();
    sf.setScale(index,major);
    QVector<QVector<Note>> note = sf.getScale();

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            ui->table->setItem(i,j, new QTableWidgetItem(""));
        }
    }
    sf.clear();

    QTableWidgetItem* item;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            if(note[i][j].penta)
            {
                item = ui->table->item(i, j);
                if (item == 0)
                {
                    item = new QTableWidgetItem("");
                    ui->table->setItem(i, j, item);
                }
                item->setBackground(QBrush(Qt::cyan));
                continue;
            }
            if(note[i][j].hl)
            {
                item = ui->table->item(i, j);
                if (item == 0)
                {
                    item = new QTableWidgetItem("");
                    ui->table->setItem(i, j, item);
                }
                item->setBackground(QBrush(Qt::lightGray));
            }
        }
    }
    delete item;
}

void MainWindow::setTable()
{
    ui->table->setRowCount(6);
    ui->table->setColumnCount(25);
    ui->table->resize(771,222);

    QStringList headers;
    for(int i = 0; i < 25; i++)
    {
        headers.append(QVariant(i).toString());
    }
    ui->table->setHorizontalHeaderLabels(headers);

    for(int i = 0; i < 25; i++)
    {
        ui->table->setColumnWidth(i,20);
    }

    ui->table->setSelectionMode(QAbstractItemView::NoSelection);
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::setComboBox()
{
    QStringList Note = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    for(int i = 0; i < 12; i++)
    {
        ui->comboBox->insertItem(i,Note[i]);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    output(index);
}


void MainWindow::on_min_clicked()
{
    output(ui->comboBox->currentIndex());
}


void MainWindow::on_maj_clicked()
{
    output(ui->comboBox->currentIndex());
}

