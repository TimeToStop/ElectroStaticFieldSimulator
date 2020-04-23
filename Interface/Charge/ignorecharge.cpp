#include "ignorecharge.h"

IgnoreCharge::IgnoreCharge(const QStringList&, QWidget *parent):
    QDialog(parent)
{

}

IgnoreCharge::~IgnoreCharge()
{
}

std::vector<size_t> IgnoreCharge::indexToIgnore() const
{
    return std::vector<size_t>();
}
