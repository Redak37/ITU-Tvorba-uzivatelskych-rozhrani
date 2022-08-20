#include "tutorial.h"
#include "ui_tutorial.h"
#include "mainwindow.h"


tutorial::tutorial(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::tutorial)
{
    ui->setupUi(this);
    obr[0].load("../ITU/resources/tut1.jpg");
    obr[1].load("../ITU/resources/tut2.jpg");
    obr[2].load("../ITU/resources/tut3.jpg");
    obr[3].load("../ITU/resources/tut4.jpg");
    obr[4].load("../ITU/resources/tut5.jpg");
    aktivniObr=0;
    ui->label->setPixmap(obr[aktivniObr]);
    ui->prev->setDisabled(true);
}

tutorial::~tutorial()
{
    delete ui;
}

void tutorial::on_zpet_clicked()
{
    this->hide();
    MainWindow *par = (MainWindow*) this->parent()->parent();
    par->men.show();
}

void tutorial::on_next_clicked()
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

void tutorial::on_prev_clicked()
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
