#include "IncidentState.h"
#include <iostream>

// ACTIVE STATE 
void ActiveState::report(Incident* incident){
    std::cout << "Invalid Transition: Incident has already been reported and is active.";
}
void ActiveState::activate(Incident* incident){
    std::cout << "Invalid Transition: Incident is already active.";
}
void ActiveState::contain(Incident* incident){
    incident->setState(new ContainedState());
}
void ActiveState::resolve(Incident* incident){
    incident->setState(new ResolvedState());
}
void ActiveState::reportFalseAlarm(Incident* incident){
    std::cout << "Invalid Transition: Incident is not a false alarm and is already active.";
}

std::string ActiveState::getStatusName(){
    return "Active";
}