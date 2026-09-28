#include "IncidentState.h"
#include <iostream>

void FalseAlarmState::report(Incident* incident){
    std::cout << "Invalid Transition: Incident is a false alarm.";
}
void FalseAlarmState::activate(Incident* incident){
    std::cout << "Invalid Transition: False alarm cannot be activated.";
}
void FalseAlarmState::contain(Incident* incident){
    std::cout << "Invalid Transition: False alarm cannot be contained.";
}
void FalseAlarmState::resolve(Incident* incident){
    std::cout << "Invalid Transition: Incident was marked as a false alarm.";
}
void FalseAlarmState::reportFalseAlarm(Incident* incident){
    std::cout << "Invalid Transition: Incident is already marked as a false alarm.";
}

std::string FalseAlarmState::getStatusName(){
    return "False Alarm";
}