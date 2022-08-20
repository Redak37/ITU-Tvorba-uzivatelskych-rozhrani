#include "zebricek.h"
#include "ui_zebricek.h"
#include "mainwindow.h"

zebricek::zebricek(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::zebricek)
{
    ui->setupUi(this);
}

zebricek::~zebricek()
{
    delete ui;
}

void zebricek::on_zpet_clicked()
{
    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->men.show();
}
