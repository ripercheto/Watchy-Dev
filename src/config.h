#ifndef CONFIG_H
#define CONFIG_H

#include "arduino_pins.h"
#define ENABLE_DLST true //daylight savings offset

//display
#define DISPLAY_WIDTH 200
#define DISPLAY_HEIGHT 200
//wifi
#define WIFI_AP_TIMEOUT 60
#define WIFI_AP_SSID "Watchy AP"
//menu
#define WATCHFACE_STATE -1
#define MAIN_MENU_STATE 0
#define APP_STATE 1
#define FW_UPDATE_STATE 2
#define MENU_HEIGHT 25
#define MENU_LENGTH 8 * 2
#define MENU_ITEMS_VISIBLE 7

//alarm
#define SET_ALARM_INDEX 0
#define SET_ALARM_ENABLED 1
#define SET_ALARM_HOUR 2
#define SET_ALARM_MINUTE 3
#define SET_ALARM_SUNDAY 4
#define SET_ALARM_MONDAY 5
#define SET_ALARM_TUESDAY 6
#define SET_ALARM_WEDNESDAY 7
#define SET_ALARM_THURSDAY 8
#define SET_ALARM_FRIDAY 9
#define SET_ALARM_SATURDAY 10
#define ALARM_COUNT 9

//set time
#define SET_HOUR 0
#define SET_MINUTE 1
#define SET_YEAR 2
#define SET_MONTH 3
#define SET_DAY 4
#define HOUR_12_24 24
//BLE OTA
#define BLE_DEVICE_NAME "Watchy BLE OTA"
#define WATCHFACE_NAME "Watchy 7 Segment"
#define SOFTWARE_VERSION_MAJOR 1
#define SOFTWARE_VERSION_MINOR 0
#define SOFTWARE_VERSION_PATCH 0
#define HARDWARE_VERSION_MAJOR 1
#define HARDWARE_VERSION_MINOR 0
//Versioning
#define WATCHY_LIB_VER "1.4.0"

#endif
