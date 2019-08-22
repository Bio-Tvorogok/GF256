#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //GF::Out(579080835);
    ui->lineOut->setReadOnly(true);
    ui->lineEdit1->setValidator( new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit2->setValidator( new QRegExpValidator(QRegExp("[0-9]+")));
    on_comboBox_currentIndexChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    //qDebug() << index;
    switch (index) {
    case 0:
        currIndex = index;
        ui->lineEdit2->setEnabled(true);
        break;
    case 1:
        currIndex = index;
        ui->lineEdit2->setEnabled(true);
        break;
    case 2:
        currIndex = index;
        ui->lineEdit2->setEnabled(false);
        break;
    case 3:
        currIndex = index;
        ui->lineEdit2->setEnabled(false);
        break;
    }

}

void MainWindow::on_pushButton_clicked()
{
    QString text1 = ui->lineEdit1->text();
    QString text2 = "";
    if (currIndex < 2)
        text2 = ui->lineEdit2->text();
    switch (currIndex) {
    case 0: {
            auto res = GF::Plus(text1.toUInt(), text2.toUInt());
            ui->lineOut->clear();
            ui->lineOut->setText(QString::number(res));
    }
        break;
    case 1: {
            auto res = GF::Multiply(text1.toUInt(), text2.toUInt());
            ui->lineOut->clear();
            ui->lineOut->setText(QString::number(res));
    }
        break;
    case 2: {
            auto res = GF::MultiplicativeInverse(text1.toUInt());
            ui->lineOut->clear();
            ui->lineOut->setText(QString::number(res));
    }
        break;
    case 3: {
            auto res = GF::Out(text1.toUInt());
            ui->lineOut->clear();
            ui->lineOut->setText(res);
    }
        break;
    }
}

bool MainWindow::isHex(const QString &str)
{
    QRegExp reg("[0-9]+");
    return reg.indexIn(str) != -1;
}
