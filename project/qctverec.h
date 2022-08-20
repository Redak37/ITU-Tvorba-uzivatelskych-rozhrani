#ifndef QCTVEREC_H
#define QCTVEREC_H

#include <QLayout>

class QCtverec : public QLayout{
    Q_OBJECT

public:
    QCtverec();
    QCtverec(bool top);
    ~QCtverec() override;

    void add(QLayoutItem *item);
    void addItem(QLayoutItem *item) override;
    void addWidget(QWidget* widget);
    //Nova funkce na replacovani itemu
    QLayoutItem*replaceItem(QLayoutItem* item);

    QSize sizeHint() const override;
    QSize minimumSize() const override;
    QLayoutItem *itemAt(int index) const override;
    QLayoutItem *takeAt(int index) override;
    void setGeometry(const QRect &rect) override;
    int count() const override;


    bool mamItem() const;

signals:
    void fontChanged(int newValue);

private:
    QLayoutItem *item;
    QRect *geometry;
    QRect *old;
    bool alwaysTop;
    int font;
};

#endif // QCTVEREC_H
