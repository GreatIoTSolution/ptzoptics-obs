#ifndef CONSTANTS_H
#define CONSTANTS_H

#define PORT_NUM 5678

#define MAX_BUFFER_SIZE 32

#define COMPACT_VIEW 0
#define ADVANCED_VIEW 1

#define PREVIEW_WIDTH 658



#define DEFAULT_SETTINGS_PATH "/ptzoptics-controller/settings.ini"
#define DOWNLOAD_FILE_DEST_PREFIX "/ptzoptics-controller/downloads/snapshot_"
#define DOWNLOAD_FILE_URI "/snapshot.jpg"


#define DEFAULT_CAMERA_IP "0.0.0.0"

#define DEFAULT_CAMERA1_NAME "Camera1"
#define DEFAULT_CAMERA1_NAME_KEY "cam1_name"
#define DEFAULT_CAMERA2_NAME "Camera2"
#define DEFAULT_CAMERA2_NAME_KEY "cam2_name"
#define DEFAULT_CAMERA3_NAME "Camera3"
#define DEFAULT_CAMERA3_NAME_KEY "cam3_name"
#define DEFAULT_CAMERA4_NAME "Camera4"
#define DEFAULT_CAMERA4_NAME_KEY "cam4_name"
#define DEFAULT_CAMERA5_NAME "Camera5"
#define DEFAULT_CAMERA5_NAME_KEY "cam5_name"
#define DEFAULT_CAMERA6_NAME "Camera6"
#define DEFAULT_CAMERA6_NAME_KEY "cam6_name"
#define DEFAULT_CAMERA7_NAME "Camera7"
#define DEFAULT_CAMERA7_NAME_KEY "cam7_name"
#define DEFAULT_CAMERA8_NAME "Camera8"
#define DEFAULT_CAMERA8_NAME_KEY "cam8_name"

#define DEFAULT_CAMERA1_IP_KEY "cam1_ip"
#define DEFAULT_CAMERA2_IP_KEY "cam2_ip"
#define DEFAULT_CAMERA3_IP_KEY "cam3_ip"
#define DEFAULT_CAMERA4_IP_KEY "cam4_ip"
#define DEFAULT_CAMERA5_IP_KEY "cam5_ip"
#define DEFAULT_CAMERA6_IP_KEY "cam6_ip"
#define DEFAULT_CAMERA7_IP_KEY "cam7_ip"
#define DEFAULT_CAMERA8_IP_KEY "cam8_ip"

#define READ_DATA_INTERVAL 500//if queries are appended, you can increase the interval

#define SETTING_KEY_PANSPEED "pan_speed"
#define SETTING_KEY_TILTSPEED "tilt_speed"
#define SETTING_KEY_ZOOMSPEED "zoom_speed"
#define SETTING_KEY_FOCUSSPEED "focus_speed"
#define SETTING_KEY_PANTILTLOCK "pantilt_lock"

#define SETTING_KEY_AEMODE "aemode"
#define SETTING_KEY_SHUTTER_SPEED "shutter_speed"
#define SETTING_KEY_IRIS "iris"
#define SETTING_KEY_BRIGHTNESS "brightness"

#define SETTING_SELECTED_JOYSTICK "selected_joystick"
#define SETTING_JOYSTICK_AVAILABLE "is joystick available"
#define SETTING_HOTKEY_AVAILABLE "is hotkey available"

#define BTN_START 9
#define BTN_BACK 8
#define BTN_LB 4
#define BTN_LT 6
#define BTN_RB 5
#define BTN_RT 7
#define BTN_X 3
#define BTN_Y 0
#define BTN_A 2
#define BTN_B 1
#define BTN_TL 10
#define BTN_TR 11




#endif // CONSTANTS_H
