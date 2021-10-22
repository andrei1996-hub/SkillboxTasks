//
// Created by andrei1996 on 21/10/2021.
//

#include <iostream>
#include <sstream>
using namespace std;

enum switchboard {
    GENERAL_SUPPLY = 1,
    OUTLETS_HOUSE = 2,
    LIGHTING_INDOORS = 4,
    LIGHTING_OUTDOORS = 8,
    HEATING_INDOORS = 16,
    HEATING_WATER_SUPPLY = 32,
    AIR_COND_INDOORS = 64
};

void sensorInput(stringstream& buf) {
    buf.str("");
    cout << "Input sequence: outdoor temperature, indoor temperature, "
        << "outdoor movement(yes/no), light in house(on/off):" << endl;
    string str;
    getline(cin , str);
    buf << str;
}

void lightingIndoors(int time, string &light, int& color, int& state) {
    if (light == "on") {
        state |= LIGHTING_INDOORS;
        switch (time) {
            case 16:
                color = 4700;
                break;
            case 17:
                color = 4200;
                break;
            case 18:
                color = 3700;
                break;
            case 19:
                color = 3200;
                break;
            case 20:
                color = 2700;
                break;
            case 0:
                color = 5000;
                break;
        }
    } else state &= (~LIGHTING_INDOORS);
}

void lightingOutdoors (int hour, string const &move, int &state) {
    if (hour >= 16 && hour <= 23 || hour >= 0 && hour <= 5 && move == "yes") state |= LIGHTING_OUTDOORS;
    if (hour > 5 && hour < 16 || move == "no") state &= (~LIGHTING_OUTDOORS);
}

void climateControl (double outTemp, double inTemp, int &state) {
    if (outTemp <= 0)  state |= HEATING_WATER_SUPPLY;
    if (outTemp > 5) state &= (~HEATING_WATER_SUPPLY);
    if (inTemp < 22) state |= HEATING_INDOORS;
    if (inTemp >= 25 ) state &= (~HEATING_INDOORS);
    if (inTemp >= 30) state |= AIR_COND_INDOORS;
    if (inTemp <= 25) state &= (~AIR_COND_INDOORS);
}

void switchboardState(stringstream &text, int state, int color) {
    text.str("");
    text.clear();
    text << "\nSwitchboard state: \n" ;
    if (state & GENERAL_SUPPLY) text << "General electrical supply: \"on\"\n";
    else text << "General electrical supply: \"off\"\n";
    if (state & OUTLETS_HOUSE) text << "House outlets(220V): \"on\"\n";
    else text << "House outlets(220V): \"off\"\n";
    if (state & LIGHTING_INDOORS) text << "House lighting: \"on\", color temperature: " << color << "К\n";
    else text << "House lighting: \"off\"\n";
    if (state & LIGHTING_OUTDOORS) text << "Outdoor lighting: \"on\"\n";
    else text << "Outdoor lighting: \"off\"\n";
    if (state & HEATING_INDOORS) text << "Indoor heating: \"on\"\n";
    else text << "Indoor heating: \"off\"\n";
    if (state & HEATING_WATER_SUPPLY) text << "Water supply heating: \"on\"\n";
    else text << "Water supply heating: \"off\"\n";
    if (state & AIR_COND_INDOORS) text << "Air conditioning: \"on\"\n";
    else text << "Air conditioning: \"off\"\n";
}

int main() {
    int sbState = 0;
    stringstream textBuffer;
    textBuffer.str("");
    string timer;
    int lightTemperature = 5000;
    double outsideTemp, insideTemp;
    string outdoorMovement = "no", lightingInside = "off";

    sbState |= GENERAL_SUPPLY;
    sbState |= OUTLETS_HOUSE;

    for (int d = 1; d <= 2; ++d)
    {
        for (int h = 0; h < 24; ++h) {
            timer = to_string(h) + ":" + "00";
            cout << "Day " << d << ". Time: " << timer << endl;
            sensorInput(textBuffer);
            textBuffer >> outsideTemp >> insideTemp >> outdoorMovement >> lightingInside;
            climateControl(outsideTemp, insideTemp, sbState);
            lightingOutdoors(h, outdoorMovement, sbState);
            lightingIndoors(h, lightingInside, lightTemperature, sbState);
            switchboardState(textBuffer, sbState, lightTemperature);
            cout << textBuffer.str() << endl;
        }
    }
}

