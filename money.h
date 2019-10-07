#ifndef MONEY_H
#define MONEY_H

#include<QGraphicsTextItem>

class Money : public QGraphicsTextItem
{
public:
    Money(QGraphicsItem* parent=0);
    void money_increase();
    void money_decrease(int decrease_num);
    int get_money();
private:
    int money;
};


#endif // MONEY_H
