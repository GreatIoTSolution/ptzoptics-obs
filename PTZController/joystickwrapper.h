#ifndef JOYSTICKWRAPPER_H
#define JOYSTICKWRAPPER_H

#include <QObject>
#include <QJoysticks.h>
#include <QSettings>
class JoystickWrapper : public QObject
{
    Q_OBJECT
public:
    explicit JoystickWrapper(QObject *parent = nullptr);
    ~JoystickWrapper();
    QStringList getJoystickNames();
private:
    int currentJoystickId;
    bool isJoystickEnabled;
    QSettings *settings;
    bool validEvent(int js);

    bool xPressed, yPressed, aPressed;//for control leminance and contrast and hue

public slots:
    void joystickCountChanged();

    void joystickPOVChanged(const int js , const int pov , const int angle);
    void joystickAxisChanged(const int js , const int axis , const double value);
    void joystickButtonChanged(const int js , const int button , const bool pressed);

signals:
    void osdMenuBtnTriggered();
    void enterBtnTriggered();
    void backBtnTriggered();
    void moveLeftBtnTriggered();
    void moveRightBtnTriggered();
    void moveTopBtnTriggered();
    void moveBottomBtnTriggered();
    void moveTopLeftBtnTriggered();
    void moveTopRightBtnTriggered();
    void moveBottomRightBtnTriggered();
    void moveBottomLeftBtnTriggered();
    void moveStop();
    void moveHome();
    void zoomInBtnTriggered();
    void zoomOutBtnTriggered();
    void zoomStop();
    void focusInBtnTriggered();
    void focusOutBtnTriggered();
    void focusStop();
    void focusStateChange();
    void luminanceChangeTriggered(bool increase);
    void contrastChangeTriggered(bool increase);
    void hueChangeTriggered(bool increase);
    void callPreset(int presetNum);
    void switchCamera(int cameraNum);

};

#endif // JOYSTICKWRAPPER_H
