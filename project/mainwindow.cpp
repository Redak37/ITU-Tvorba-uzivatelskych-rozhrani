#include "qctverec.h"
#include "dialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QShortcut>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCtverec *hlctverec = new QCtverec();
    hlctverec->addWidget(ui->frame_10);
    ui->widget_4->setLayout(hlctverec);

    QCtverec *klavesnice = new QCtverec(true);
    klavesnice->addWidget(ui->frame_klavesnice);
    ui->widget_klavesnice->setLayout(klavesnice);

    //Věci pro codebehind
    initPolicka();
    aktivni = Q_NULLPTR;
    nastavFont(15);
    reInit();
    QObject::connect(hlctverec, SIGNAL(fontChanged(int)), this, SLOT(nastavFont(int)));

    //Shortcuty, tohle se prej uklidí v parentovi :D
    QShortcut *shortcut = new QShortcut(QKeySequence("1"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey1()));
    shortcut = new QShortcut(QKeySequence("2"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey2()));
    shortcut = new QShortcut(QKeySequence("3"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey3()));
    shortcut = new QShortcut(QKeySequence("4"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey4()));
    shortcut = new QShortcut(QKeySequence("5"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey5()));
    shortcut = new QShortcut(QKeySequence("6"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey6()));
    shortcut = new QShortcut(QKeySequence("7"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey7()));
    shortcut = new QShortcut(QKeySequence("8"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey8()));
    shortcut = new QShortcut(QKeySequence("9"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkey9()));
    shortcut = new QShortcut(QKeySequence("Del"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(shortkeyDel()));
    shortcut = new QShortcut(QKeySequence("Enter"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(deaktivuj()));
    shortcut = new QShortcut(QKeySequence("0"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(rychle_prpeni()));

    centrum = ui->frame_14;
    centrum->hide();
    casPovolen = true;
    this->centralWidget()->layout()->addWidget(&nast);
    nast.hide();

    this->centralWidget()->layout()->addWidget(&zeb);
    zeb.hide();

    this->centralWidget()->layout()->addWidget(&tut);
    tut.hide();

    this->centralWidget()->layout()->addWidget(&met);
    met.hide();

    this->centralWidget()->layout()->addWidget(&men);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(casUpdate()));
    timer->start(1000);

//    Dialog *win = new Dialog(this);
//    win->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Radek a sloupec je 0 - 8
QAbstractButton * MainWindow::dejMiPolicko(int radek, int sloupec){
    return this->policka[radek][sloupec];
}

//Radek je Y, sloupec je X
QPoint MainWindow::pozicePolicka(QAbstractButton *policko){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j<9 ;j++){
            if(this->policka[i][j] == policko){
                return QPoint(j,i);
            }
        }
    }
    return QPoint(-1,-1);
}

ZAP_MODE *MainWindow::rekniModePolicka(QAbstractButton *policko){
    QPoint pos = pozicePolicka(policko);
    if(pos.x()!=-1)
        return &(modePolicka[pos.y()][pos.x()]);
    else
        return Q_NULLPTR;
}

void MainWindow::initPolicka(){
    for(int radek = 1; radek <= 9; radek++){
        for(int sloupec = 1; sloupec <= 9; sloupec++){

            switch(radek){
                case 1:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_1;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_2;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_3;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_10;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_11;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_12;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_19;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_20;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_21;
                        break;
                    }
                    break;
                case 2:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_4;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_5;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_6;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_13;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_14;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_15;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_22;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_23;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_24;
                        break;
                    }
                    break;
                case 3:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_7;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_8;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_9;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_16;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_17;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_18;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_25;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_26;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_27;
                        break;
                    }
                    break;
                case 4:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_28;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_29;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_30;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_37;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_38;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_39;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_46;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_47;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_48;
                        break;
                    }
                    break;
                case 5:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_31;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_32;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_33;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_40;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_41;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_42;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_49;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_50;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_51;
                        break;
                    }
                    break;
                case 6:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_34;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_35;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_36;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_43;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_44;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_45;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_52;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_53;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_54;
                        break;
                    }
                    break;
                case 7:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_55;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_56;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_57;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_64;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_65;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_66;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_73;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_74;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_75;
                        break;
                    }
                    break;
                case 8:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_58;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_59;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_60;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_67;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_68;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_69;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_76;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_77;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_78;
                        break;
                    }
                    break;
                case 9:
                    switch(sloupec){
                    case 1:
                        this->policka[radek-1][sloupec-1] = ui->but_61;
                        break;
                    case 2:
                        this->policka[radek-1][sloupec-1] = ui->but_62;
                        break;
                    case 3:
                        this->policka[radek-1][sloupec-1] = ui->but_63;
                        break;
                    case 4:
                        this->policka[radek-1][sloupec-1] = ui->but_70;
                        break;
                    case 5:
                        this->policka[radek-1][sloupec-1] = ui->but_71;
                        break;
                    case 6:
                        this->policka[radek-1][sloupec-1] = ui->but_72;
                        break;
                    case 7:
                        this->policka[radek-1][sloupec-1] = ui->but_79;
                        break;
                    case 8:
                        this->policka[radek-1][sloupec-1] = ui->but_80;
                        break;
                    case 9:
                        this->policka[radek-1][sloupec-1] = ui->but_81;
                        break;
                    }
                    break;
            }
        }
    }
}

void MainWindow::reInit(){
    //Další inity
    for(int i = 0; i < 9; i++){
        for(int j = 0; j<9 ;j++){
            act[i][j] = start[i][j];
            if (start[i][j] == 0){
                modePolicka[i][j] = NIC;
                policka[i][j]->setText(CM);
                this->policka[i][j]->setStyleSheet(StylNeaktivni.arg(this->font));
            }
            else {
                modePolicka[i][j] = VYGEN;
                policka[i][j]->setText(QString::number(start[i][j]));
                this->policka[i][j]->setStyleSheet(StylDisabled.arg(this->font));
            }
        }
    }
    this->mode = PERO;
    prepniAktivni(Q_NULLPTR);
    vyhrane = false;
    posledniZmenene = Q_NULLPTR;
    posledniZmena = NENI;
    posledniHodnota = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 11 ;k++){
                tuzka[i][j][k] = ' ';
                if(k == 3 || k == 7)
                    tuzka[i][j][k] = '\n';
            }
            //tuzka[i][j][11] = '\0';
        }
    }
    ui->tl_pero->setStyleSheet("background-color: rgb(150, 150, 255);\
                               border-style: solid;\
                               border-width: 1px;\
                               border-color: blue;");
    ui->tl_guma->setStyleSheet("");
    ui->tl_tuzka->setStyleSheet("");
    setCas(0);
}

void MainWindow::prepniAktivni(QAbstractButton *policko){
    ZAP_MODE *modpol = rekniModePolicka(this->aktivni);
    if(this->aktivni == policko && this->aktivni != Q_NULLPTR){
        //deaktivovat
        if(*modpol == TUZKA)
            this->aktivni->setStyleSheet(StylNeaktivni.arg(this->font/2));
        else if(*modpol == CHYBA && napoveda)
            this->aktivni->setStyleSheet(StylErr.arg(this->font));
        else
            this->aktivni->setStyleSheet(StylNeaktivni.arg(this->font));
        this->aktivni = Q_NULLPTR;
        return;
    }
    else if(this->aktivni != Q_NULLPTR){
        //deaktivovat
        if(*modpol == TUZKA)
            this->aktivni->setStyleSheet(StylNeaktivni.arg(this->font/2));
        else if(*modpol == CHYBA && napoveda)
            this->aktivni->setStyleSheet(StylErr.arg(this->font));
        else
            this->aktivni->setStyleSheet(StylNeaktivni.arg(this->font));
    }
    //Tady se aktivuje novy
    this->aktivni = policko;
    modpol = rekniModePolicka(policko);
    if(this->aktivni != Q_NULLPTR){
        if(*modpol == TUZKA)
            policko->setStyleSheet(StylAktivni.arg(this->font/2));
        else
            policko->setStyleSheet(StylAktivni.arg(this->font));
    }
}

void MainWindow::zapisCislo(int cislo){
    //qDebug() << "Zapisuju " <<cislo << " na " << this->aktivni <<endl;
    if(this->aktivni != Q_NULLPTR){
        ZAP_MODE *modpol = rekniModePolicka(this->aktivni);
        QPoint poz = pozicePolicka(this->aktivni);
        if(mode == TUZKA){
            int nc;
            nc = cislo - 1;
            if(cislo > 3){
                nc++;
                if(cislo > 6){
                    nc++;
                }
            }
            if(tuzka[poz.x()][poz.y()][nc] == char( cislo + '0'))
                tuzka[poz.x()][poz.y()][nc] = ' ';
            else
                tuzka[poz.x()][poz.y()][nc] = char( cislo + '0');

            posledniZmenene = this->aktivni;
            posledniZmena = Z_TUZKA;
            posledniHodnota = cislo;
        }
        if(mode >= *modpol){
            if(mode == TUZKA){
                QString *novy = new QString();
                for (int i = 0; i < 11; ++i) {
                    if (tuzka[poz.x()][poz.y()][i] == ' ')
                        novy->append(CM);
                    else
                        novy->append(tuzka[poz.x()][poz.y()][i]);

                    if (tuzka[poz.x()][poz.y()][i] != '\n' && i != 2 && i != 6 && i != 10)
                        novy->append(CM);
                }

                *modpol = mode;
                this->aktivni->setText(*novy);
                this->aktivni->setStyleSheet(StylAktivni.arg(this->font/2));
            } else {
                int c;
                if(*modpol==PERO || *modpol==CHYBA)
                    c = this->aktivni->text().toInt();
                else
                    c = 0;

                this->aktivni->setStyleSheet(StylAktivni.arg(this->font));
                this->aktivni->setText(QString::number(cislo));
                posledniZmenene = this->aktivni;
                posledniZmena = Z_PERO;
                posledniHodnota = c;
                act[poz.y()][poz.x()] = char(cislo);
                *modpol = mode;
                if(napoveda){
                    for (int i = 0; i < 9; i++) {
                        if (act[poz.y()][i] == cislo && policka[poz.y()][i] != this->aktivni) {
                            this->aktivni->setStyleSheet(StylErr.arg(this->font));
                            *modpol = CHYBA;
                            if (*(rekniModePolicka(policka[poz.y()][i])) != VYGEN){
                                policka[poz.y()][i]->setStyleSheet(StylErr.arg(this->font));
                                this->modePolicka[poz.y()][i] = CHYBA;
                            }
                        }
                        if (act[i][poz.x()] == cislo && policka[i][poz.x()] != this->aktivni) {
                            this->aktivni->setStyleSheet(StylErr.arg(this->font));
                            *modpol = CHYBA;
                            if (*(rekniModePolicka(policka[i][poz.x()])) != VYGEN){
                                policka[i][poz.x()]->setStyleSheet(StylErr.arg(this->font));
                                this->modePolicka[i][poz.x()] = CHYBA;
                            }
                        }
                        if (act[poz.y()/3*3+i/3][poz.x()/3*3+i%3] == cislo && policka[poz.y()/3*3+i/3][poz.x()/3*3+i%3] != this->aktivni) {
                            this->aktivni->setStyleSheet(StylErr.arg(this->font));
                            *modpol = CHYBA;
                            if (*(rekniModePolicka(policka[poz.y()/3*3+i/3][poz.x()/3*3+i%3])) != VYGEN){
                                policka[poz.y()/3*3+i/3][poz.x()/3*3+i%3]->setStyleSheet(StylErr.arg(this->font));
                                this->modePolicka[poz.y()/3*3+i/3][poz.x()/3*3+i%3] = CHYBA;
                            }
                        }
                    }
                }
            }
        }
    }
}


void MainWindow::klavesnice_handler(QAbstractButton* kl){
    //qDebug() << kl <<endl;
    if(kl->objectName() == "kl_1"){
        zapisCislo(1);
    }
    else if(kl->objectName() == "kl_2"){
        zapisCislo(2);
    }
    else if(kl->objectName() == "kl_3"){
        zapisCislo(3);
    }
    else if(kl->objectName() == "kl_4"){
        zapisCislo(4);
    }
    else if(kl->objectName() == "kl_5"){
        zapisCislo(5);
    }
    else if(kl->objectName() == "kl_6"){
        zapisCislo(6);
    }
    else if(kl->objectName() == "kl_7"){
        zapisCislo(7);
    }
    else if(kl->objectName() == "kl_8"){
        zapisCislo(8);
    }
    else if(kl->objectName() == "kl_9"){
        zapisCislo(9);
    }
}

void MainWindow::sudoku_handler(QAbstractButton* kl){
    //qDebug() << kl << "Obsah je '" << kl->text() << "'"<<endl;
    ZAP_MODE *modpol = rekniModePolicka(kl);
    if(*modpol == VYGEN)
        return;
    if(mode == GUMA){
        QPoint poz = pozicePolicka(kl);

        QString *novy = new QString();
        for(int i = 0; i < 11; ++i){
            if(tuzka[poz.x()][poz.y()][i] == ' ')
                novy->append(CM);
            else
                novy->append(tuzka[poz.x()][poz.y()][i]);

            if (tuzka[poz.x()][poz.y()][i] != '\n' && i != 2 && i != 6 && i != 10)
                novy->append(CM);
        }
        //Prostě po gumě je tam TUZKA
        if(*modpol == PERO || *modpol==CHYBA){
            int cislo = kl->text().toInt();
            qDebug() << "Text: " << kl->text() << " cislo: " << cislo;
            posledniZmenene = kl;
            posledniZmena = Z_GUMA;
            posledniHodnota = cislo;
        }
        *modpol = TUZKA;
        act[poz.y()][poz.x()] = 0;
        kl->setText(*novy);
        kl->setStyleSheet(StylNeaktivni.arg(this->font/2));
    }
    else{
        prepniAktivni(kl);
    }
}

//Projde vsechna policka a nastavim jim font, ktery nam vratil QCtverec
void MainWindow::nastavFont(int font)
{
//    //qDebug() << "Volam nastavFont: "<<font;
    this->font = font;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int pouzifont = font;
            if(this->modePolicka[i][j] == TUZKA)
                pouzifont = pouzifont/2;
            if(this->policka[i][j] == this->aktivni)
                this->policka[i][j]->setStyleSheet(StylAktivni.arg(pouzifont));
            else if(this->modePolicka[i][j] == VYGEN)
                this->policka[i][j]->setStyleSheet(StylDisabled.arg(pouzifont));
            else if(this->modePolicka[i][j] == CHYBA && napoveda)
                this->policka[i][j]->setStyleSheet(StylErr.arg(pouzifont));
            else
                this->policka[i][j]->setStyleSheet(StylNeaktivni.arg(pouzifont));
        }
    }

}

void MainWindow::on_tl_pero_clicked()
{
    mode = PERO;
    ui->tl_pero->setStyleSheet("background-color: rgb(150, 150, 255);\
                               border-style: solid;\
                               border-width: 1px;\
                               border-color: blue;");
    ui->tl_guma->setStyleSheet("");
    ui->tl_tuzka->setStyleSheet("");
}

void MainWindow::on_tl_tuzka_clicked()
{

    if(this->centrum != Q_NULLPTR)
        //qDebug() << this->centrum->width() <<" x " << this->centrum->height();
    mode = TUZKA;
    ui->tl_tuzka->setStyleSheet("background-color: rgb(150, 150, 255);\
                               border-style: solid;\
                               border-width: 1px;\
                               border-color: blue;");
    ui->tl_guma->setStyleSheet("");
    ui->tl_pero->setStyleSheet("");
}

void MainWindow::on_tl_guma_clicked()
{
    prepniAktivni(Q_NULLPTR);
    mode = GUMA;
    ui->tl_guma->setStyleSheet("background-color: rgb(150, 150, 255);\
                               border-style: solid;\
                               border-width: 1px;\
                               border-color: blue;");
    ui->tl_tuzka->setStyleSheet("");
    ui->tl_pero->setStyleSheet("");
}

void MainWindow::shortkey1(){
    if(!centrum->isHidden()){
        zapisCislo(1);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 1;
            } else {
                this->rychly_vyber(1);
            }
        }
    }
}
void MainWindow::shortkey2(){
    if(!centrum->isHidden()){
        zapisCislo(2);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 2;
            } else {
                this->rychly_vyber(2);
            }
        }
    }
}
void MainWindow::shortkey3(){
    if(!centrum->isHidden()){
        zapisCislo(3);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 3;
            } else {
                this->rychly_vyber(3);
            }
        }
    }
}
void MainWindow::shortkey4(){
    if(!centrum->isHidden()){
        zapisCislo(4);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 4;
            } else {
                this->rychly_vyber(4);
            }
        }
    }
}
void MainWindow::shortkey5(){
    if(!centrum->isHidden()){
        zapisCislo(5);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 5;
            } else {
                this->rychly_vyber(5);
            }
        }
    }
}
void MainWindow::shortkey6(){
    if(!centrum->isHidden()){
        zapisCislo(6);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 6;
            } else {
                this->rychly_vyber(6);
            }
        }
    }
}
void MainWindow::shortkey7(){
    if(!centrum->isHidden()){
        zapisCislo(7);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 7;
            } else {
                this->rychly_vyber(7);
            }
        }
    }
}
void MainWindow::shortkey8(){
    if(!centrum->isHidden()){
        zapisCislo(8);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 8;
            } else {
                this->rychly_vyber(8);
            }
        }
    }
}
void MainWindow::shortkey9(){
    if(!centrum->isHidden()){
        zapisCislo(9);
        if(this->aktivni == Q_NULLPTR){
            if(kl_glob_vyber == 0){
                kl_glob_vyber = 9;
            } else {
                this->rychly_vyber(9);
            }
        }
    }
}

void MainWindow::deaktivuj(){
    if(!centrum->isHidden())
        prepniAktivni(Q_NULLPTR);
}
void MainWindow::rychle_prpeni(){
    if(mode == PERO){
        on_tl_tuzka_clicked();
    }
    else if(mode == TUZKA){
        on_tl_pero_clicked();
    }
    else if(mode == GUMA){
        on_tl_pero_clicked();
    }
}

void MainWindow::shortkeyDel(){
    if(!centrum->isHidden()){
        ZAP_MODE *modpol = rekniModePolicka(this->aktivni);
        QPoint poz = pozicePolicka(this->aktivni);

        QString *novy = new QString();
        for(int i = 0; i < 11; ++i){
            if(tuzka[poz.x()][poz.y()][i] == ' ')
                novy->append(CM);
            else
                novy->append(tuzka[poz.x()][poz.y()][i]);

            if (tuzka[poz.x()][poz.y()][i] != '\n' && i != 2 && i != 6 && i != 10)
                novy->append(CM);
        }
        //Prostě po gumě je tam TUZKA
        if(*modpol == PERO || *modpol==CHYBA){
            int cislo = this->aktivni->text().toInt();
            //qDebug() << "Text: " << this->aktivni->text() << " cislo: " << cislo;
            posledniZmenene = this->aktivni;
            posledniZmena = Z_GUMA;
            posledniHodnota = cislo;
        }
        *modpol = TUZKA;
        act[poz.y()][poz.x()] = 0;
        this->aktivni->setText(*novy);
        this->aktivni->setStyleSheet(StylAktivni.arg(this->font/2));
    }
}

void MainWindow::on_tl_zpet_clicked()
{
    if(posledniZmenene == Q_NULLPTR || posledniZmena == NENI)
        return;
    ZAP_MODE *modpol = rekniModePolicka(posledniZmenene);
    QPoint poz = pozicePolicka(posledniZmenene);
    if(posledniZmena == Z_PERO){
        //Přepsali jsme tužku nebo nic, vracíme tužku
        if(posledniHodnota == 0){
            QString *novy = new QString();
            for(int i = 0; i < 11; ++i){
                if(tuzka[poz.x()][poz.y()][i] == ' ')
                    novy->append(CM);
                else
                    novy->append(tuzka[poz.x()][poz.y()][i]);

                if (tuzka[poz.x()][poz.y()][i] != '\n' && i != 2 && i != 6 && i != 10)
                    novy->append(CM);
            }
            act[poz.y()][poz.x()] = 0;
            //Prostě po gumě je tam TUZKA
            if(*modpol == PERO || *modpol==CHYBA){
                //Poslední změna je na stejném políčku, hodnota je to číslo, který dáváme pryč - takže změna je vpodstatě Z_GUMA
                int cislo = posledniZmenene->text().toInt();
                posledniZmena = Z_GUMA;
                posledniHodnota = cislo;
            }
            *modpol = TUZKA;

            posledniZmenene->setText(*novy);
            if(posledniZmenene == this->aktivni)
                posledniZmenene->setStyleSheet(StylAktivni.arg(this->font/2));
            else
                posledniZmenene->setStyleSheet(StylNeaktivni.arg(this->font/2));
        }
        //Přepsali jsme pero, změna zůstává pero, jen se prohodí ty hodnoty
        else{
            int cislo = posledniZmenene->text().toInt();
            posledniZmenene->setText(QString::number(posledniHodnota));
            act[poz.y()][poz.x()] = char(posledniHodnota);
            posledniHodnota = cislo;
        }
    }
    else if(posledniZmena == Z_TUZKA){
        int nc;
        nc = posledniHodnota - 1;
        if(posledniHodnota > 3){
            nc++;
            if(posledniHodnota > 6){
                nc++;
            }
        }
        if(tuzka[poz.x()][poz.y()][nc] == char( posledniHodnota + '0'))
            tuzka[poz.x()][poz.y()][nc] = ' ';
        else
            tuzka[poz.x()][poz.y()][nc] = char( posledniHodnota + '0');

        //Pokus je poslední změna tužka, tak se ani jeden parametr poslední změny nemění

        //Pokud je mode tužka, tak aktualizujeme hodnoty
        if(*modpol == TUZKA){
            QString *novy = new QString();
            for (int i = 0; i < 11; ++i) {
                if (tuzka[poz.x()][poz.y()][i] == ' ')
                    novy->append(CM);
                else
                    novy->append(tuzka[poz.x()][poz.y()][i]);

                if (tuzka[poz.x()][poz.y()][i] != '\n' && i != 2 && i != 6 && i != 10)
                    novy->append(CM);
            }

            posledniZmenene->setText(*novy);
            if(posledniZmenene == this->aktivni)
                posledniZmenene->setStyleSheet(StylAktivni.arg(this->font/2));
            else
                posledniZmenene->setStyleSheet(StylNeaktivni.arg(this->font/2));
        }
    }
    //posledniZmena == Z_GUMA
    else{
        //Předtím jsme vygumovali pero, teď tedy musíme znovu zapsat perem

        *modpol = PERO;
        posledniZmenene->setText(QString::number(posledniHodnota));
        posledniZmena = Z_PERO;
        act[poz.y()][poz.x()] = char(posledniHodnota);
        posledniHodnota = 0;
        if(posledniZmenene == this->aktivni)
            posledniZmenene->setStyleSheet(StylAktivni.arg(this->font));
        else
            posledniZmenene->setStyleSheet(StylNeaktivni.arg(this->font));
    }
}


void MainWindow::setCas(int newcas){
    this->cas = newcas;
    if(casPovolen){
        int min = cas / 60;
        int sec = cas % 60;
        QString vys;
        vys.append(QString::number(min).rightJustified(2, '0'));
        vys.append(":");
        vys.append(QString::number(sec).rightJustified(2, '0'));
        ui->tl_cas->setText(vys);
    }
}


void MainWindow::casUpdate(){
    if(centrum->isHidden() || vyhrane)
        return;
    cas++;
    if(casPovolen){
        int min = cas / 60;
        int sec = cas % 60;
        QString vys;
        vys.append(QString::number(min).rightJustified(2, '0'));
        vys.append(":");
        vys.append(QString::number(sec).rightJustified(2, '0'));
        ui->tl_cas->setText(vys);
    }
}

void MainWindow::on_tl_cas_clicked()
{
    if(casPovolen){
        casPovolen = false;
        ui->tl_cas->setText("Čas");
    }
    else{
        casPovolen = true;
        int min = cas / 60;
        int sec = cas % 60;
        QString vys;
        vys.append(QString::number(min).rightJustified(2, '0'));
        vys.append(":");
        vys.append(QString::number(sec).rightJustified(2, '0'));
        ui->tl_cas->setText(vys);
    }
}

void MainWindow::casomira()
{
    if(hodiny == false){
        hodiny = true;
        ui->tl_cas->show();
    } else {
        hodiny = false;
        ui->tl_cas->hide();
    }
}

void MainWindow::on_tl_menu_clicked()
{
    centrum->hide();
    men.show();
}

void MainWindow::konec(){
    this->close();
}

void MainWindow::on_tl_napoveda_clicked()
{
    if(napoveda){
        this->nast.zmenNapoveda(false);
        napoveda = false;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j<9 ;j++){
                if (modePolicka[i][j] == CHYBA){
                    if(this->aktivni == this->policka[i][j])
                        this->policka[i][j]->setStyleSheet(StylAktivni.arg(this->font));
                    else
                        this->policka[i][j]->setStyleSheet(StylNeaktivni.arg(this->font));
                }
            }
        }
    }
    else{
        this->nast.zmenNapoveda(true);
        napoveda = true;
    }
}

void MainWindow::stiknutaNapoveda(){
    on_tl_napoveda_clicked();
}

void MainWindow::rychly_vyber(int cislo)
{
    int v_cislo = kl_glob_vyber;
    kl_glob_vyber = 0;

    int p_slop = 0;
    int p_rad = 0;

    switch(v_cislo){
        case 7: p_slop = 0; p_rad = 0; break;
        case 8: p_slop = 3; p_rad = 0; break;
        case 9: p_slop = 6; p_rad = 0; break;

        case 4: p_slop = 0; p_rad = 3; break;
        case 5: p_slop = 3; p_rad = 3; break;
        case 6: p_slop = 6; p_rad = 3; break;

        case 1: p_slop = 0; p_rad = 6; break;
        case 2: p_slop = 3; p_rad = 6; break;
        case 3: p_slop = 6; p_rad = 6; break;
    }

    switch(cislo){
        case 7: p_slop += 0; p_rad += 0; break;
        case 8: p_slop += 1; p_rad += 0; break;
        case 9: p_slop += 2; p_rad += 0; break;

        case 4: p_slop += 0; p_rad += 1; break;
        case 5: p_slop += 1; p_rad += 1; break;
        case 6: p_slop += 2; p_rad += 1; break;

        case 1: p_slop += 0; p_rad += 2; break;
        case 2: p_slop += 1; p_rad += 2; break;
        case 3: p_slop += 2; p_rad += 2; break;
    }

    //qDebug("p_slop %d, p_rad %d\n", p_slop, p_rad);
    if(modePolicka[p_rad][p_slop] != VYGEN)
        prepniAktivni(dejMiPolicko(p_rad, p_slop));

}
