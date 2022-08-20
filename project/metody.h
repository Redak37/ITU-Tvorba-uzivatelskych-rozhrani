#ifndef METODY_H
#define METODY_H

#define POCET_OBR 5

#include <QFrame>

namespace Ui {
class metody;
}

class metody : public QFrame
{
    Q_OBJECT

public:
    explicit metody(QWidget *parent = nullptr);
    ~metody();

private slots:
    void on_zpet_clicked();

    void on_prev_clicked();

    void on_next_clicked();

private:
    Ui::metody *ui;
    QPixmap obr[POCET_OBR];
    int aktivniObr;
};

#endif // METODY_H
