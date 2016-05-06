#include <QMetaObject>
#include <QVariant>
#include <QMetaProperty>
#include <QDebug>
#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "models.h"

void setListProperty(const QSharedPointer<Entity> &entity,
                     QList<QSharedPointer<Entity>> &list, const QMetaProperty &property)  {
    QVariant var;
    var.setValue<QList<QSharedPointer<Entity>>>(list);
    qDebug() << "Write" << property.write(entity.data(), var);
}

int main() {
    QSharedPointer<Entity> p = QSharedPointer<Entity>(new Person());
    const QMetaObject *mo = p->metaObject();
    QMetaProperty prop = mo->property(1);
    QList<QSharedPointer<Entity>> list;
    list.append(p);
    setListProperty(p, list, prop);
    return 0;
}
