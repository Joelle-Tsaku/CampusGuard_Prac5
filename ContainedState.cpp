#include "IncidentState.h"
#include <iostream>

// CONTAINED STATE    
void ContainedState::report(Incident* incident){
    std::cout << "Invalid Transition: Incident has already been reported and is being contained.";
}
void ContainedState::activate(Incident* incident){
    std::cout << "Invalid Transition: Incident is already being contained.";
}
void ContainedState::contain(Incident* incident){
    std::cout << "Invalid Transition: Incident is already being contained.";
}
void ContainedState::resolve(Incident* incident){
    incident->setState(new ResolvedState());
}
void ContainedState::reportFalseAlarm(Incident* incident){
    std::cout << "Invalid Transition: Incident is not a false alarm and is already being contained.";
}

std::string ContainedState::getStatusName(){
    return "Contained";
}  