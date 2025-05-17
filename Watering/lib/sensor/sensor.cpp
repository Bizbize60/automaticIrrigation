#include <sensor.hpp>
#include <Arduino.h>
int humidity = 0;
int wet=65;
int dry=195;
void initSensor(){
    pinMode(36,INPUT);
    analogReadResolution(8);
}

int readSensor(){
    return measureHumidity(analogRead(36));
}

int measureHumidity(int analogresult){
    humidity=map(analogresult,wet,dry,100,0);
    return humidity;
}