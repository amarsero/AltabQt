#ifndef DEPOSITTEST_H
#define DEPOSITTEST_H

#include <QObject>
#include <deposit.h>
#include <QtTest>

class DepositTest : public QObject
{
    Q_OBJECT
public:
    explicit DepositTest(QObject *parent = nullptr);

private:
    Deposit deposit;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void SearchAll();
};

#endif // DEPOSITTEST_H
