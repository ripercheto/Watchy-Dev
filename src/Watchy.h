#ifndef WATCHY_H
#define WATCHY_H

#include <Arduino.h>
#include <WiFiManager.h>
#include <HTTPClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include <GxEPD2_BW.h>
#include <Wire.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "DSEG7_Classic_Bold_53.h"
#include "WatchyRTC.h"
#include "BLE.h"
#include "bma.h"
#include "config.h"
#include "Preferences.h"

typedef struct weatherData {
    int8_t temperature;
    int16_t weatherConditionCode;
    bool isMetric;
    String weatherDescription;
} weatherData;

typedef struct alarmData {
    uint8_t enabled;
    int hour;
    int minute;
    uint8_t sunday;
    uint8_t monday;
    uint8_t tuesday;
    uint8_t wednesday;
    uint8_t thursday;
    uint8_t friday;
    uint8_t saturday;
} alarmData;

typedef struct watchySettings {
    // Weather Settings
    String cityID;
    String weatherAPIKey;
    String weatherURL;
    String weatherUnit;
    String weatherLang;
    int8_t weatherUpdateInterval;
    // NTP Settings
    String ntpServer;
    int gmtOffset;
    int dstOffset;
} watchySettings;

class Watchy {
   public:
    Preferences preferences;
    static WatchyRTC RTC;
    static GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display;
    tmElements_t currentTime;
    watchySettings settings;

   public:
    explicit Watchy(const watchySettings &s) : settings(s) {}  // constructor
    void init(String datetime = "");
    void deepSleep();
    static void displayBusyCallback(const void *);
    float getBatteryVoltage();
    void vibMotor(uint8_t intervalMs = 100, uint8_t length = 20);

    void handleButtonPress();
    void showMenu(byte menuIndex, bool partialRefresh = true);
    void showAbout();
    void showBuzz();
    void showAccelerometer();
    void showUpdateFW();
    void showSyncNTP();
    bool syncNTP();
    bool syncNTP(long gmt, int dst, String ntpServer);
    void setTime();
    void setAlarm();
    void checkAlarm();
    void setupWifi();
    bool connectWiFi();
    weatherData getWeatherData();
    weatherData getWeatherData(String cityID, String units, String lang, String url, String apiKey, uint8_t updateInterval);
    void updateFWBegin();

    void showWatchFace(bool partialRefresh);
    virtual void drawWatchFace();  // override this method for different watch faces

   private:
    alarmData currentAlarm;
    void drawMenuItems();
    void updateAlarmData(int index);
    void _bmaConfig();
    static void _configModeCallback(WiFiManager *myWiFiManager);
    static uint16_t _readRegister(uint8_t address, uint8_t reg, uint8_t *data, uint16_t len);
    static uint16_t _writeRegister(uint8_t address, uint8_t reg, uint8_t *data, uint16_t len);
};

extern RTC_DATA_ATTR int guiState;
extern RTC_DATA_ATTR int menuIndex;
extern RTC_DATA_ATTR BMA423 sensor;
extern RTC_DATA_ATTR bool WIFI_CONFIGURED;
extern RTC_DATA_ATTR bool BLE_CONFIGURED;

#endif
