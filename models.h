#ifndef PERSON_H
#include <QObject>
#include <QList>
#include <QSharedPointer>
#define PERSON_H
class Entity : public QObject {
    Q_OBJECT
  public:
    Entity(QObject *parent = nullptr) : QObject(parent) { }
    virtual ~Entity() { }
};

class Person : public Entity {
    Q_OBJECT
  public:
    Person() : Entity() { }
    Q_PROPERTY(QList<QSharedPointer<Person>> p READ getP WRITE setP)
  private:
    QList<QSharedPointer<Person>> p;
    QList<QSharedPointer<Person>> getP() const {
        return p;
    }
    void setP(const QList<QSharedPointer<Person>> &value) {
        p = value;
    }
};

#endif // PERSON_H
