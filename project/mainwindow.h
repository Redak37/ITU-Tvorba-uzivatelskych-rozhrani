#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include "menu.h"
#include "metody.h"
#include "nastaveni.h"
#include "zebricek.h"
#include "tutorial.h"

//Zapisovací mode / mode políčka. GUMA není mode políčka.
enum ZAP_MODE{NIC = 0, TUZKA, CHYBA, PERO ,GUMA, VYGEN};
//Číselná mezera. Je to taková lepší mezera. Na tohle se nastaví prázdný políčko.
const QString CM = " ";
//Styly
const QString StylNeaktivni = "background-color: rgb(230, 230, 230);\
                            color: black;\
                            border-style: solid;\
                            border-width: 1px;\
                            border-color: rgb(150, 150, 150);\
                            min-width: 40px;\
                            min-height: 40px;\
                            font: %1px;";
const QString StylAktivni = "background-color: rgb(255, 100, 100);\
                            color: black;\
                            border-style: solid;\
                            border-width: 1px;\
                            border-color: red;\
                            min-width: 40px;\
                            min-height: 40px;\
                            font: bold %1px";
const QString StylDisabled = "background-color: rgb(200, 200, 200);\
                            color: black;\
                            border-style: solid;\
                            border-width: 1px;\
                            border-color: rgb(80, 80, 80);\
                            min-width: 40px;\
                            min-height: 40px;\
                            font: %1px";
const QString StylErr = "background-color: rgb(200, 0, 150);\
                            color: black;\
                            border-style: solid;\
                            border-width: 1px;\
                            border-color: rgb(80, 80, 80);\
                            min-width: 40px;\
                            min-height: 40px;\
                            font: %1px";
enum ZMENA{NENI = 0, Z_TUZKA, Z_GUMA, Z_PERO};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QAbstractButton * dejMiPolicko(int radek, int sloupec);
    QPoint pozicePolicka(QAbstractButton *policko);
    void initPolicka();
    void reInit();
    ZAP_MODE *rekniModePolicka(QAbstractButton *policko);
    void prepniAktivni(QAbstractButton *policko);
    void zapisCislo(int cislo);
    void setCas(int newcas);
    void konec();
    void casomira();
    void stiknutaNapoveda();

    QWidget *centrum;
    nastaveni nast;
    menu men;
    zebricek zeb;
    metody met;
    tutorial tut;
    bool hodiny = true;

private slots:
    void klavesnice_handler(QAbstractButton*);
    void sudoku_handler(QAbstractButton*);
    void nastavFont(int);
    void shortkey1();
    void shortkey2();
    void shortkey3();
    void shortkey4();
    void shortkey5();
    void shortkey6();
    void shortkey7();
    void shortkey8();
    void shortkey9();
    void shortkeyDel();
    void casUpdate();
    void deaktivuj();
    void rychle_prpeni();

    void on_tl_pero_clicked();

    void on_tl_tuzka_clicked();

    void on_tl_guma_clicked();


    void on_tl_zpet_clicked();

    void on_tl_cas_clicked();

    void on_tl_menu_clicked();

    void on_tl_napoveda_clicked();

private:
    Ui::MainWindow *ui;
    ZAP_MODE modePolicka[9][9];
    QAbstractButton * policka[9][9];
    ZAP_MODE mode;
    QAbstractButton * aktivni;
    char tuzka[9][9][11];
    int font;
    char start[9][9] = {
        {3,4,0,8,2,6,0,7,1},
        {0,0,8,0,0,0,9,0,0},
        {7,6,0,0,9,0,0,4,3},
        {0,8,0,1,0,2,0,3,0},
        {0,3,0,0,0,0,0,9,0},
        {0,7,0,9,0,4,0,1,0},
        {8,2,0,0,4,0,0,5,9},
        {0,0,7,0,0,0,3,0,0},
        {4,1,0,3,8,9,0,6,2}
    };
    char act[9][9];
    ZMENA posledniZmena;
    QAbstractButton * posledniZmenene;
    int posledniHodnota;
    int cas;
    bool casPovolen;
    bool vyhrane;
    bool napoveda = true;
    int kl_glob_vyber = 0;
    void rychly_vyber(int cislo);
};

#endif // MAINWINDOW_H
