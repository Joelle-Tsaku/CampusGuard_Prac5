#include "Incident.h"
#include "IncidentState.h"

Incident::Incident(int id, std::string type, std::string location, std::string severity):id(id), type(type), location(location), severity(severity){
    currentState = new ReportedState();
}

void Incident::activate(){
    currentState->activate(this);
}

void Incident::contain(){
    currentState->contain(this);
}

void Incident::resolve(){
    currentState->resolve(this);
}

void Incident::reportFalseAlarm(){
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
    currentState->getStatusName();
}
