#ifndef TYPES_H
#define TYPES_H

#include <QObject>
#include <QList>

using std::string;

///
/// \brief Encapsulate a unit of CPU Information as name and value
/// e.g name: "cache size", value: "4096 KB"
/// derives from QObject to be used as C++ Model in the QT Model-View architechture
///
class CPUInfoElement: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QString value READ getValue CONSTANT)

public:
    CPUInfoElement(const string& name, const string& value,
                   QObject* parent = 0);
    QString getName() const;
    QString getValue() const;

private:
    string _name;
    string _value;
};

/// \brief Holds info about single CPU Core
using CPUInfo = QList<QObject*>;

/// \brief Holds info about all CPU cores
using CPUInfoList = std::vector<CPUInfo>;


#endif // TYPES_H
