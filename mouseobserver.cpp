 #include "MouseObserver.h"

MouseObserver::MouseObserver(QWidget* pwgt):QLabel(pwgt)
{
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions\n(Press a mouse button)");

}

void MouseObserver::mousePressEvent(QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse Pressed");
}

void MouseObserver::mouseReleaseEvent(QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse Released");
}

void MouseObserver::mouseMoveEvent(QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse Is Moving");
}

void MouseObserver::dumpEvent(QMouseEvent *pe, const QString &strMessage)
{
    setText(strMessage
            + "\n buttons() = " + buttonsInfo(pe)
            + "\n x() = " + QString::number(pe->x())
            + "\n y() = " + QString::number(pe->y())
            + "\n globalX() = " + QString::number(pe->globalX())
            + "\n globalY() = " + QString::number(pe->globalY())
            + "\n modifiers() = " + modifiersInfo(pe));
}

QString MouseObserver::modifiersInfo(QMouseEvent *pe)
{
    QString strModifiers;

    if(pe->modifiers() & Qt::ShiftModifier)
    {
        strModifiers += "Shift ";
    }
    if(pe->modifiers() & Qt::ControlModifier)
    {
        strModifiers += "Control ";
    }
    if(pe->modifiers() & Qt::AltModifier)
    {
        strModifiers += "Alt";
    }
    return strModifiers;
}

QString MouseObserver::buttonsInfo(QMouseEvent *pe)
{
    QString strButtons;
    if(pe->buttons() & Qt::LeftButton)
    {
        strButtons += "Left ";
    }
    if(pe->button() & Qt::RightButton)
    {
        strButtons += "Right ";
    }
    if(pe->button() & Qt::MidButton)
    {
        strButtons += "Middle";
    }
    return strButtons;
}
