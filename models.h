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
    Q_PROPERTY(QSharedPointer<Person> sp READ getSp WRITE setSp)
    Q_PROPERTY(Person* spAgain READ getSpAgain WRITE setSpAgain)
    QSharedPointer<Person> getSp() const
    {
    return this->sp;
    }

    void setSp(const QSharedPointer<Person> &value)
    {
    this->sp = value;
    }

    Person *getSpAgain() const
    {
    return spAgain;
    }

    void setSpAgain(Person *value)
    {
    spAgain = value;
    }


private:
    QList<QSharedPointer<Person>> p;
    QSharedPointer<Person> sp;
    Person *spAgain;
    QList<QSharedPointer<Person>> getP() const {
        return p;
    }
    void setP(const QList<QSharedPointer<Person>> &value) {
        p = value;
    }
};

#endif // PERSON_H
