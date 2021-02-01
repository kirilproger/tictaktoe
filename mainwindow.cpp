#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWhite();
    connect(ui->a11,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->a12,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->a13,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->a21,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->a22,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->a23,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->a31,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->a32,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->a33,&QPushButton::clicked,this,&MainWindow::btnClicked);
    connect(ui->actrest,&QAction::triggered,this,&MainWindow::setWhite);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setWhite(){
    QPixmap pix1(":/res/white.png");
    QIcon white(pix1);
    ui->a11->setIcon(white);
    ui->a12->setIcon(white);
    ui->a13->setIcon(white);
    ui->a21->setIcon(white);
    ui->a22->setIcon(white);
    ui->a23->setIcon(white);
    ui->a31->setIcon(white);
    ui->a32->setIcon(white);
    ui->a33->setIcon(white);
    btns.clear();
    WinGame=0;
}

void MainWindow::IfWin(QToolButton *a, QToolButton *b, QToolButton *c){
    QPixmap pix2(":/res/winzero.png");
    QIcon winzero(pix2);
    QPixmap pix3(":/res/wincross.png");
    QIcon wincross(pix3);
    if(btns[a]>0 && btns[a]==btns[b] && btns[b]==btns[c]){
        WinGame=true;
        if(btns[a]==1){
            a->setIcon(winzero);
            b->setIcon(winzero);
            c->setIcon(winzero);
        }else{
            a->setIcon(wincross);
            b->setIcon(wincross);
            c->setIcon(wincross);
        }
    }
}
void MainWindow::btnClicked(){
     QToolButton* buttonSender = qobject_cast<QToolButton*>(sender());
     if(btns[buttonSender]>0 || WinGame){
        return;
     }
    if(k%2==0){
        QPixmap pix1(":/res/cross.png");
        QIcon cross(pix1);
        buttonSender->setIcon(cross);
        btns[buttonSender]=2;
        k++;
    }else{
        QPixmap pix1(":/res/zero.png");
        QIcon zero(pix1);
        buttonSender->setIcon(zero);
        btns[buttonSender]=1;
        k++;
    }
    //if win
    //horizontal
    IfWin(ui->a11,ui->a12,ui->a13);
    IfWin(ui->a21,ui->a22,ui->a23);
    IfWin(ui->a31,ui->a32,ui->a33);
    //vertical
    IfWin(ui->a11,ui->a21,ui->a31);
    IfWin(ui->a12,ui->a22,ui->a32);
    IfWin(ui->a13,ui->a23,ui->a33);
    //diagonals
    IfWin(ui->a11,ui->a22,ui->a33);
    IfWin(ui->a13,ui->a22,ui->a31);
}

