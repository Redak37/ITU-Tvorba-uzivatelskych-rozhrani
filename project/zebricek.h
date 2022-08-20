#ifndef ZEBRICEK_H
#define ZEBRICEK_H

#include <QFrame>

namespace Ui {
class zebricek;
}

class zebricek : public QFrame
{
    Q_OBJECT

public:
    explicit zebricek(QWidget *parent = nullptr);
    ~zebricek();

private slots:
    void on_zpet_clicked();

private:
    Ui::zebricek *ui;
};

#endif // ZEBRICEK_H
