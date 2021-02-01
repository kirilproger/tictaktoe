#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QPixmap>
#include<QPushButton>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<QMap>
#include<QAction>
#include<QToolButton>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    int k=0;
    bool WinGame=0;
    QMap<QWidget*,int>btns;
    void IfWin(QToolButton *a, QToolButton *b, QToolButton *c);
private slots:
    void btnClicked();
    void setWhite();
};

#endif // MAINWINDOW_H
