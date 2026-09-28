#include "Incident.h"
#include "IncidentState.h"
#include <iostream>

Incident::Incident(int id, std::string type, std::string location, std::string severity):id(id), type(type), location(location), severity(severity){
    currentState = nullptr;
}

Incident::~Incident(){
    delete currentState;
}

void Incident::report(){
    if(currentState == nullptr){
        currentState = new ReportedState();
        std::cout << "Incident reported.";

        return; 
    }

    currentState->report(this);
}

void Incident::activate(){
    if(currentState == nullptr){
        std::cout << "Invalid transition: Incident should be reported first.";
        return; 
    }
    currentState->activate(this);
}

void Incident::contain(){
    if(currentState == nullptr){
        std::cout << "Invalid transition: Incident should be reported first.";
        return; 
    }
    currentState->contain(this);
}

void Incident::resolve(){
    if(currentState == nullptr){
        std::cout << "Invalid transition: Incident should be reported first.";
        return; 
    }
    currentState->resolve(this);
}

void Incident::reportFalseAlarm(){
    if(currentState == nullptr){
        std::cout << "Invalid transition: Incident should be reported first.";
        return; 
    }
    currentState->reportFalseAlarm(this); 
}

void Incident::setState(IncidentState* newState){
    if(currentState != nullptr){
        delete currentState;
    }
    currentState = newState;
}

std::string Incident::getLocation() const {
    return location;
}

std::string Incident::getSeverity() const {
    return severity; 
}

std::string Incident::getType() const {
    return type; 
}

int Incident::getId() const {
    return id; 
}

std::string Incident::getStatus() const {
    if(currentState == nullptr){
        return "Unreported";
    }

    return currentState->getStatusName();
}
