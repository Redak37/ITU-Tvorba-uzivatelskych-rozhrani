#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include <QDebug>

menu::menu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    ui->tl_pokracovat->hide();
    obtiznost = LEHKA;
}

menu::~menu()
{
    delete ui;
}

void menu::on_nova_hra_clicked()
{
    ui->tl_pokracovat->show();
    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->reInit();
    par->centrum->show();
}

void menu::on_tl_pokracovat_clicked()
{
    this->hide();
    //gamewin->setCentralWidget(gamewin);
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->centrum->show();
}

void menu::on_tl_konec_clicked()
{
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->konec();
}

void menu::on_tl_settings_clicked()
{
    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->nast.show();
}

void menu::on_tl_zebricek_clicked()
{
    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->zeb.show();
}

void menu::on_metody_res_clicked()
{
    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->met.show();
}

void menu::on_tutorial_clicked()
{
    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->tut.show();
}

void menu::on_obtiznost_clicked()
{
    switch(obtiznost){
    case LEHKA:
        obtiznost = STREDNI;
        ui->obtiznost->setText("Obtížnost: Střední");
        break;
    case STREDNI:
        obtiznost = TEZKA;
        ui->obtiznost->setText("Obtížnost: Těžká");
        break;
    case TEZKA:
        obtiznost = LEHKA;
        ui->obtiznost->setText("Obtížnost: Lehká");
        break;
    }
}
