#ifndef MENU_H
#define MENU_H

#include <QFrame>

enum OBTIZNOST{LEHKA, STREDNI, TEZKA};

namespace Ui {
class menu;
}

class menu : public QFrame
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_nova_hra_clicked();

    void on_tl_pokracovat_clicked();

    void on_tl_konec_clicked();

    void on_tl_settings_clicked();

    void on_tl_zebricek_clicked();

    void on_metody_res_clicked();

    void on_tutorial_clicked();

    void on_obtiznost_clicked();

private:
    Ui::menu *ui;
    OBTIZNOST obtiznost;
};

#endif // MENU_H
