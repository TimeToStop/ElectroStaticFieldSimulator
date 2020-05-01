#include "ignorecharge.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QScrollArea>
#include <QLabel>

IgnoreCharge::IgnoreCharge(const QStringList& names, QWidget *parent):
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
