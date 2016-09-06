#include <QString>
#include <QtTest>
#include <QMetaObject>
#include <QVariant>
#include <QMetaProperty>
#include <QDebug>
#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "models.h"

class MetapropertyWriteTest : public QObject {
    Q_OBJECT

  public:
    MetapropertyWriteTest();
    void setListProperty(const QSharedPointer<Entity> &entity,
                         QList<QSharedPointer<Entity>> &list, const QMetaProperty &property);

  private Q_SLOTS:
    void testCase1();
    void testCase2();
    void testCase3();
};

MetapropertyWriteTest::MetapropertyWriteTest() {
}

void MetapropertyWriteTest::testCase1() {
    QSharedPointer<Entity> p = QSharedPointer<Entity>(new Person());
    const QMetaObject *mo = p->metaObject();
    QMetaProperty prop = mo->property(1);
    QList<QSharedPointer<Entity>> list;
    list.append(p);
    setListProperty(p, list, prop);
}

void MetapropertyWriteTest::testCase2() {
    QSharedPointer<Entity> p = QSharedPointer<Entity>(new Person());
    const QMetaObject *mo = p->metaObject();
    QMetaProperty prop = mo->property(2);
    QVariant var;
    var.setValue<QSharedPointer<Entity>>(p);
    QVERIFY(prop.write(p.data(), var));
}

void MetapropertyWriteTest::testCase3()
{
    Entity *p = new Person();
    const QMetaObject *mo = p->metaObject();
    QMetaProperty prop = mo->property(3);
    QVariant var;
    var.setValue<Entity*>(p);
    QVERIFY(prop.write(p, var));
}


void MetapropertyWriteTest::setListProperty(const QSharedPointer<Entity> &entity,
        QList<QSharedPointer<Entity>> &list, const QMetaProperty &property)  {
    QVariant var;
    var.setValue<QList<QSharedPointer<Entity>>>(list);
    QVERIFY(property.write(entity.data(), var));
}

QTEST_APPLESS_MAIN(MetapropertyWriteTest)

#include "tst_metapropertywritetest.moc"
