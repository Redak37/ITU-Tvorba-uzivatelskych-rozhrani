#include "nastaveni.h"
#include "ui_nastaveni.h"
#include "mainwindow.h"

nastaveni::nastaveni(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::nastaveni)
{
    ui->setupUi(this);
}

nastaveni::~nastaveni()
{
    delete ui;
}

void nastaveni::on_zpet_clicked()
{
    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->men.show();
}

void nastaveni::on_casomira_clicked()
{
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->casomira();
    if(par->hodiny == true){
        ui->casomira->setText("Časomíra: zapnuto");
    } else {
        ui->casomira->setText("Časomíra: vypnuto");
    }
}

void nastaveni::zmenNapoveda(bool n){
    if(n)
        ui->napoveda->setText("Nápověda: zapnuto");
    else
        ui->napoveda->setText("Nápověda: vypnuto");

}

void nastaveni::on_napoveda_clicked()
{
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->stiknutaNapoveda();
}
