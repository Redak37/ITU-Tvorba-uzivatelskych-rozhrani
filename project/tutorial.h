#ifndef TUTORIAL_H
#define TUTORIAL_H

#define POCET_OBR 5

#include <QFrame>

namespace Ui {
class tutorial;
}

class tutorial : public QFrame
{
    Q_OBJECT

public:
    explicit tutorial(QWidget *parent = nullptr);
    ~tutorial();

private slots:
    void on_zpet_clicked();

    void on_next_clicked();

    void on_prev_clicked();

private:
    Ui::tutorial *ui;
    QPixmap obr[POCET_OBR];
    int aktivniObr;
};

#endif // TUTORIAL_H
