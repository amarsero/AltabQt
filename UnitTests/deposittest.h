#ifndef DEPOSITTEST_H
#define DEPOSITTEST_H

#include <QObject>

class DepositTest : public QObject
{
    Q_OBJECT
public:
    explicit DepositTest(QObject *parent = nullptr);
private slots:
    void SearchAll();


};

#endif // DEPOSITTEST_H
