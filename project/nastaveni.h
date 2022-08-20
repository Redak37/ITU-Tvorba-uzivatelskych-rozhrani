#ifndef NASTAVENI_H
#define NASTAVENI_H

#include <QFrame>

namespace Ui {
class nastaveni;
}

class nastaveni : public QFrame
{
    Q_OBJECT

public:
    explicit nastaveni(QWidget *parent = nullptr);
    ~nastaveni();
    void zmenNapoveda(bool n);

private slots:
    void on_zpet_clicked();

    void on_casomira_clicked();

    void on_napoveda_clicked();

private:
    Ui::nastaveni *ui;
};

#endif // NASTAVENI_H
