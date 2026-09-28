#include "IncidentState.h"
#include <iostream>

// RESOLVED STATE    
void ResolvedState::report(Incident* incident){
    std::cout << "Invalid Transition: Incident has already been resolved.";
}
void ResolvedState::activate(Incident* incident){
    std::cout << "Invalid Transition: Incident has already been resolved.";
}
void ResolvedState::contain(Incident* incident){
    std::cout << "Invalid Transition: Incident has already been resolved.";
}
void ResolvedState::resolve(Incident* incident){
    std::cout << "Invalid Transition: Incident has already been resolved.";
}
void ResolvedState::reportFalseAlarm(Incident* incident){
    std::cout << "Invalid Transition: Incident has already been resolved.";
}

std::string ResolvedState::getStatusName(){
    return "Resolved";
}