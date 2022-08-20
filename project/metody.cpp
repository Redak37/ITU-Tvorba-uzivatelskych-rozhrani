#include "metody.h"
#include "ui_metody.h"
#include "mainwindow.h"

metody::metody(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::metody)
{
    ui->setupUi(this);
    obr[0].load("../ITU/resources/met1.jpg");
    obr[1].load("../ITU/resources/met2.jpg");
    obr[2].load("../ITU/resources/met3.jpg");
    obr[3].load("../ITU/resources/met4.jpg");
    obr[4].load("../ITU/resources/met5.jpg");
    aktivniObr=0;
    ui->label->setPixmap(obr[aktivniObr]);
    ui->prev->setDisabled(true);
}

metody::~metody()
{
    delete ui;
}

void metody::on_zpet_clicked()
{

    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->men.show();
}

void metody::on_prev_clicked()
{
    if(aktivniObr <= 0){
        return;
    }
    aktivniObr--;
    if(aktivniObr == 0){
        ui->prev->setDisabled(true);
    }
    ui->next->setDisabled(false);
    ui->label->setPixmap(obr[aktivniObr]);
}

void metody::on_next_clicked()
{
    if(aktivniObr >= POCET_OBR - 1){
        return;
    }
    aktivniObr++;
    if(aktivniObr == POCET_OBR - 1){
        ui->next->setDisabled(true);
    }
    ui->prev->setDisabled(false);
    ui->label->setPixmap(obr[aktivniObr]);
}
