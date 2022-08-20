#include "qctverec.h"
#include <QDebug>

QCtverec::QCtverec()
{
    item = Q_NULLPTR;
    old = new QRect(0, 0, 0, 0);
    geometry = new QRect(0, 0, 0, 0);
    alwaysTop = false;
}
QCtverec::QCtverec(bool top)
{
    item = Q_NULLPTR;
    old = new QRect(0, 0, 0, 0);
    geometry = new QRect(0, 0, 0, 0);
    alwaysTop = top;
}
QCtverec::~QCtverec()
{
//    delete item; //Že prej mám mazat ten item...
    delete this->geometry;
    delete this->old;
}
//mamItem
bool QCtverec::mamItem() const{
    return this->item != Q_NULLPTR;
}

//Pridavani prvku
void QCtverec::addItem(QLayoutItem *item){
    if(!mamItem())
        replaceItem(item);
}
void QCtverec::add(QLayoutItem *item){
    if(!mamItem())
        replaceItem(item);
}
void QCtverec::addWidget(QWidget* widget){
    if(!mamItem()){
        QWidgetItem *itemik = new QWidgetItem(widget);
        replaceItem(itemik);
    }
}
QLayoutItem* QCtverec::replaceItem(QLayoutItem* item) {
    QLayoutItem* old = this->item;
    this->item = item;
    item->setGeometry(*(this->geometry));
    return old;
}

//Veci s velikosti...
QSize QCtverec::sizeHint() const{
    return this->item->minimumSize();
}
QSize QCtverec::minimumSize() const{
    return this->item->minimumSize();
}

//Todle je standart - nutnost
QLayoutItem *QCtverec::itemAt(int index) const{
    if(mamItem() && index == 0){
        return this->item;
    }
    return Q_NULLPTR;
}
QLayoutItem *QCtverec::takeAt(int index){
    QLayoutItem *ven;
    if(mamItem() && index == 0){
        ven = this->item;
        this->item = Q_NULLPTR;
        return ven;
    }
    return Q_NULLPTR;
}
int QCtverec::count() const {
    return mamItem();
}
//Toto je to, kde z toho udelame Ctverec
void QCtverec::setGeometry(const QRect &rect){
    //Pokud nemám item nebo se mi nezměnil obdelník, tak nepřepočítávám.
    if(!mamItem() || rect == *old){
        return;
    }
    //Tady si teda zapamatuju novej "old rect"
    QRect* smazatRect = this->old;
    this->old = new QRect(rect.topLeft(), rect.size());
    delete smazatRect;

    //Velikost musi byt width = height. Takže musím vzít to kratší.
    QSize velikost = rect.size();
    if(rect.height() >= rect.width())
        velikost.setHeight(rect.width());
    else
        velikost.setWidth(rect.height());

    //Já potřebuju vypočítat horní roh toho mýho itemu. Jako příklad vezmu, když to mám vyšší než širší.
    //Tak u šířky (x-coord) je to jasný - prostě 0 (react.width = velikost.width)
    //No a výšku když to chci vidět uprostřed, tak potřebuju mít stejně nahoře tak i dole.
    //Tudíž když vezmu půlku dostupnýho místa a odčtu od toho půlku místa, který zabírám, tak mi vyjde moje souřadnice!
    QPoint kamStim;
    if(alwaysTop)
        kamStim = QPoint(rect.width()/2 - velikost.width()/2, 0);
    else
        kamStim = QPoint(rect.width()/2 - velikost.width()/2, rect.height()/2 - velikost.height()/2);

    QRect* smazat = this->geometry;
    /* Cache the calculated geometry. */
    this->geometry = new QRect(kamStim, velikost);
    delete smazat;
    this->item->setGeometry(*this->geometry);
//    qDebug() << "Velikost: " << velikost.width();
    int newfont = (int)(velikost.width()*15/400.0);
    //Vždycky minimálně 15
    newfont = newfont >= 15 ? newfont : 15;
    if(font != newfont){
        font = newfont;
        emit fontChanged(font);
    }
};
