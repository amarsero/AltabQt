#include <QObject>
#include <QTest>

class Persistence : public QObject
{
    Q_OBJECT

public:
    Persistence();
    ~Persistence();
private:

private slots:
    void initTestCase();
    void cleanupTestCase();
    void Save();
};

Persistence::Persistence()
{

}

void Persistence::initTestCase()
{

}

void Persistence::cleanupTestCase()
{
}

void Persistence::Save()
{

}

QTEST_APPLESS_MAIN(Persistence)

#include "tst_serialization.moc"
