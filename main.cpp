#include <QMetaObject>
#include <QVariant>
#include <QMetaProperty>
#include <QDebug>
#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "models.h"

void setListProperty(const QSharedPointer<Entity> &entity, QList<QSharedPointer<Entity>> &list, const QMetaProperty &property)  {
    QVariant var;
    var.setValue<QList<QSharedPointer<Entity>>>(list);
    qDebug() << "Write" << property.write(entity.data(), var);
}

int main() {
    QSharedPointer<Person> p = QSharedPointer<Person>(new Person());
    const QMetaObject *mo = p->metaObject();
    QMetaProperty prop = mo->property(2);
    QList<QSharedPointer<Entity>> list;
    list.append(p);
    QSharedPointer<Entity> e = list.at(0);
    setListProperty(e, list, prop);
    return 0;
}
