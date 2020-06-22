#ifndef SERIALIZATIONTEST_H
#define SERIALIZATIONTEST_H

#include <QObject>
#include <QtTest>

#include <memory>
#include <sstream>

#include <shortcutentry.h>
#include <serializableobject.h>
#include <deserializableobject.h>

class SerializationTest : public QObject
{
    Q_OBJECT
public:
	SerializationTest();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void ShortcutEntrySerialization();

};

#endif // SERIALIZATIONTEST_H
