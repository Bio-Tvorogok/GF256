#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include "gf.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    int currIndex = 0;
    Ui::MainWindow *ui;

private:
    bool isHex(const QString &str);
};

#endif // MAINWINDOW_H
