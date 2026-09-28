#include "IncidentState.h"
#include <iostream>

// REPORTED STATE
void ReportedState::report(Incident* incident){
    std::cout << "Invalid Transition: Incident has already been reported.";
}

void ReportedState::activate(Incident* incident){
    incident->setState(new ActiveState());
}

void ReportedState::contain(Incident* incident){
    std::cout << "Invalid Transition.";
}

void ReportedState::resolve(Incident* incident){
    std::cout << "Invalid Transition.";
}

void ReportedState::reportFalseAlarm(Incident* incident){
    incident->setState(new FalseAlarmState());
    std::cout << "Incident: " << incident->getType() << " is a false alarm.";
}

std::string ReportedState::getStatusName(){
    return "Reported"; 
}