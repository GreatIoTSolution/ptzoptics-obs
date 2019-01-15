#include "joystickwrapper.h"
#include <QDebug>
#include "sdl/SDL.h"
#include <QStandardPaths>
#include "constants.h"

#define STICK_THRESHOULD 0.2
JoystickWrapper::JoystickWrapper(QObject *parent) : QObject(parent)
{
    settings = new QSettings(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + DEFAULT_SETTINGS_PATH , QSettings::IniFormat);
//    QJoysticks::getInstance()->setVirtualJoystickRange(0.8);
    QJoysticks::getInstance()->setVirtualJoystickEnabled(false);
    connect(QJoysticks::getInstance() , SIGNAL(countChanged()) , this , SLOT(joystickCountChanged()));
    connect(QJoysticks::getInstance() , SIGNAL(povChanged(int,int,int)) , this , SLOT(joystickPOVChanged(int,int,int)));
    connect(QJoysticks::getInstance() , SIGNAL(axisChanged(int,int,qreal)) , this , SLOT(joystickAxisChanged(int,int,qreal)));
    connect(QJoysticks::getInstance() , SIGNAL(buttonChanged(int,int,bool)) , this , SLOT(joystickButtonChanged(int,int,bool)));
    xPressed = false;
    yPressed = false;
    aPressed = false;

}
JoystickWrapper::~JoystickWrapper()
{
    delete settings;
}
QStringList JoystickWrapper::getJoystickNames()
{
    return QJoysticks::getInstance()->deviceNames();
}
void JoystickWrapper::joystickCountChanged()
{
    xPressed = false;
    yPressed = false;
    aPressed = false;

    qDebug()<<QJoysticks::getInstance()->count();
}
void JoystickWrapper::joystickPOVChanged(const int js , const int pov , const int angle)
{
    if(validEvent(js))
    {
        switch(angle)
        {
        case 0:
            emit moveTopBtnTriggered();
            break;
        case 45:
            emit moveTopRightBtnTriggered();
            break;
        case 90:
            emit moveRightBtnTriggered();
            break;
        case 135:
            emit moveBottomRightBtnTriggered();
            break;
        case 180:
            emit moveBottomBtnTriggered();
            break;
        case 225:
            emit moveBottomLeftBtnTriggered();
            break;
        case 270:
            emit moveLeftBtnTriggered();
            break;
        case 315:
            emit moveTopLeftBtnTriggered();
            break;
        case -1:
            emit moveStop();
            break;
        default:
            break;
        }
    }
}
void JoystickWrapper::joystickAxisChanged(const int js , const int axis , const double value)
{
    if(validEvent(js))
    {
        switch(axis)
        {
        case 3://TR
            if(value > STICK_THRESHOULD)
                emit moveRightBtnTriggered();
            else if(value < -STICK_THRESHOULD)
                emit moveLeftBtnTriggered();
            else
                emit moveStop();
            break;

        case 4://TR
            if(value > STICK_THRESHOULD)
                emit moveBottomBtnTriggered();
            else if(value < -STICK_THRESHOULD)
                emit moveTopBtnTriggered();
            else
                emit moveStop();
            break;

        case 1://TL
            if(value > STICK_THRESHOULD)
                emit switchCamera(1);
            else if(value < - STICK_THRESHOULD)
                emit switchCamera(3);
            break;

        case 0://TL
            if(value > STICK_THRESHOULD)
                emit switchCamera(2);
            else if(value < - STICK_THRESHOULD)
                emit switchCamera(4);
            break;

        default:
            break;
        }
    }
}
void JoystickWrapper::joystickButtonChanged(const int js , const int button , const bool pressed)
{
    if(validEvent(js))
    {
        switch(button)
        {
        case BTN_START:
            if(!pressed)
                emit enterBtnTriggered();
            break;
        case BTN_BACK:
            if(!pressed)
                emit backBtnTriggered();
            break;
        case BTN_X:
            if(!pressed)
                emit callPreset(2);
            break;
        case BTN_Y:
            if(!pressed)
                emit callPreset(3);
            break;
        case BTN_A:
            if(!pressed)
                emit callPreset(1);
            break;
        case BTN_B:
            if(!pressed)
                emit focusStateChange();
            break;
        case BTN_TL:
            if(!pressed)
                emit osdMenuBtnTriggered();
            break;
        case BTN_TR:
            if(!pressed)
                emit moveHome();
        case BTN_LB:
            if(pressed)
                emit zoomInBtnTriggered();
            else
                emit zoomStop();
            break;
        case BTN_RB:
            if(pressed)
                emit zoomOutBtnTriggered();
            else
                emit zoomStop();
            break;
        case BTN_LT:
            if(pressed)
                emit focusInBtnTriggered();
            else
                emit focusStop();
            break;
        case BTN_RT:
            if(pressed)
                emit focusOutBtnTriggered();
            else
                emit focusStop();
            break;
        default:
            break;
        }
    }
}
bool JoystickWrapper::validEvent(int js)
{
    if(!settings->value(SETTING_JOYSTICK_AVAILABLE , false).toBool())
        return false;
    if(js != settings->value(SETTING_SELECTED_JOYSTICK))
        return false;
    return true;
}
