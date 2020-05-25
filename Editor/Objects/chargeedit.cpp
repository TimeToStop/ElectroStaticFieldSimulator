#include "chargeedit.h"

#include "Editor/editor.h"

unsigned long long ChargeEdit::m_amount = 0;
const int ChargeEdit::m_r = 5;

ChargeEdit::ChargeEdit(const QString &name, const Vector &pos, const Vector &init_vel, float mass, float charge, bool ignore, bool movable, Editor * const editor):
    Object(editor),
    m_name(name),
    m_init_velocity(init_vel),
    m_mass(mass),
    m_charge(charge),
    m_is_ignored(ignore),
    m_is_movable(movable)
{
    setPos(pos);
}

ChargeEdit::ChargeEdit(Editor * const editor):
    Object(editor),
    m_name("Charge " + QString::number(m_amount++)),
    m_init_velocity(),
    m_mass(1.f),
    m_charge(1.f),
    m_is_ignored(false),
    m_is_movable(true)
{
}

ChargeEdit::~ChargeEdit()
{
    Arrow* arrow = m_editor->get(this);
    if(arrow != nullptr)
    {
        m_editor->rmObject(arrow);
    }

    m_editor->rm(this);
}

void ChargeEdit::draw(QPainter& painter) const
{
    if(isSelected())
    {
        painter.setPen(QPen(QColor(255, 0, 0), 1, Qt::SolidLine));
        painter.setBrush(QBrush(QColor(255, 0, 0), Qt::SolidPattern));
    }
    else
    {
        painter.setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine));
        painter.setBrush(QBrush(QColor(0, 0, 0), Qt::SolidPattern));
    }

    QPoint p = m_editor->fromXOY(pos()).toPointF().toPoint();
    painter.drawEllipse(p.x() - m_r, p.y() - m_r, 2*m_r, 2*m_r);
}

bool ChargeEdit::intersects(const QRect& rect) const
{
    return rect.contains(m_editor->fromXOY(pos()).toPointF().toPoint());
}

bool ChargeEdit::isClose(const QPoint& _pos) const
{
    return QLineF(_pos, m_editor->fromXOY(pos()).toPointF().toPoint()).length() < m_r;
}

void ChargeEdit::setPos(const Vector& _pos)
{
    Object::setPos(_pos);
    Arrow* arrow = m_editor->get(this);
    if(arrow != nullptr)
    {
        arrow->setDest(pos());
    }
}

void ChargeEdit::movePos(const Vector& _pos)
{
    Object::movePos(_pos);
    Arrow* arrow = m_editor->get(this);
    if(arrow != nullptr)
    {
        arrow->setDest(pos());
    }
}

void ChargeEdit::setSelected(bool b)
{
    Object::setSelected(b);
    Arrow* arrow = m_editor->get(this);
    if(arrow != nullptr)
    {
        arrow->setSelected(b);
    }
}

void ChargeEdit::setInitialVelocityArrow(const Vector& vec)
{
    Arrow* arrow = m_editor->get(this);

    if(arrow == nullptr)
    {
        std::shared_ptr<Arrow> cur = std::make_shared<Arrow>(m_editor);
        m_editor->bind(cur.get(), this);
        m_editor->addObject(cur);
        arrow = cur.get();
    }

    arrow->setPos(pos() + vec);
}

void ChargeEdit::setName(const QString& name)
{
    m_name = name;
}

void ChargeEdit::setInitVelocity(const Vector& init)
{
    m_init_velocity = init;

    if(init.module() > 0.00000001f)
    {
        setInitialVelocityArrow(init);
    }
}

void ChargeEdit::setMass(float mass)
{
    m_mass = mass;
}

void ChargeEdit::setCharge(float charge)
{
    m_charge = charge;
}

void ChargeEdit::setIgnored(bool b)
{
    m_is_ignored = b;
}

void ChargeEdit::setMovable(bool b)
{
    m_is_movable = b;
}

QString ChargeEdit::name() const
{
    return m_name;
}

Vector ChargeEdit::initVelocity() const
{
    return m_init_velocity;
}

float ChargeEdit::mass() const
{
    return m_mass;
}

float ChargeEdit::charge() const
{
    return m_charge;
}

bool ChargeEdit::ignored() const
{
    return m_is_ignored;
}

bool ChargeEdit::movable() const
{
    return m_is_movable;
}

int ChargeEdit::index() const
{
    return 1;
}
