#include "include/types.h"

CPUInfoElement::CPUInfoElement(const string& name, const string& value,
                               QObject* parent): QObject(parent)
{
    _name = name;
    _value = value;
}

QString CPUInfoElement::getName() const
{
    return QString::fromStdString(_name);
}

QString CPUInfoElement::getValue() const
{
    return QString::fromStdString(_value);
}

