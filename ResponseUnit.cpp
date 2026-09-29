#include "ResponseUnit.h"
#include "Mediator.h"
#include "Incident.h"
#include <iostream>

ResponseUnit::ResponseUnit(std::string name, Mediator* mediator) : name(name), mediator(mediator), dispatched(false){}

ResponseUnit::~ResponseUnit(){}

std::string ResponseUnit::getName() const {
    return name; 
}

bool ResponseUnit::isDispatched() {
    return dispatched;
}

// SECURITY TEAM
SecurityTeam::SecurityTeam(Mediator* mediator) : ResponseUnit("Security Team", mediator){}

void SecurityTeam::respond(Incident* incident){
    dispatch(incident);
}

void SecurityTeam::dispatch(Incident* incident){
    dispatched = true; 

    std::cout << "[Security] Dispatched to " << incident->getLocation() << std::endl;
}

void SecurityTeam::reportMedicalEmergency(Incident* incident){
    std::cout << "[Security] Medical Emergency detected. \n";

    mediator->notify(this, incident, "MEDICAL_NEEDED");
}

void SecurityTeam::reportAreaSafety(Incident* incident){
    std::cout << "[Security] Area reported unsafe. \n";

    mediator->notify(this, incident, "UNSAFE_AREA");
}

// MEDICAL TEAM
MedicalTeam::MedicalTeam(Mediator* mediator) : ResponseUnit("Medical Team", mediator){}

void MedicalTeam::respond(Incident* incident){
    dispatch(incident);
}

void MedicalTeam::dispatch(Incident* incident){
    dispatched = true; 

    std::cout << "[Medical] Dispatched to " << incident->getLocation() << std::endl;
}

void MedicalTeam::requestAccess(Incident* incident){
    std::cout << "[Medical] Area is unsafe. Requesting security. \n";

    mediator->notify(this, incident, "SECURITY_NEEDED");
}

// FACILITIES TEAM 
FacilitiesTeam::FacilitiesTeam(Mediator* mediator) : ResponseUnit("Facilities Team", mediator){}

void FacilitiesTeam::respond(Incident* incident){
    dispatch(incident);
}
void FacilitiesTeam::dispatch(Incident* incident){
    dispatched = true; 

    std::cout << "[Facilities] Dispatched to " << incident->getLocation() << std::endl;
}
void FacilitiesTeam::reportAreaSafety(Incident* incident){
    mediator->notify(this, incident, "AREA_UNSAFE");
}

// ALERT SERVICE
AlertService::AlertService(Mediator* mediator) : ResponseUnit("Alert Service", mediator){}

void AlertService::respond(Incident* incident){
    sendEmergencyAlert(incident);
}

void AlertService::sendEvacuationAlert(Incident* incident){
    std::cout << "[ALERT] Emergency at " << incident->getLocation() << std::endl;
} 

void AlertService::sendEmergencyAlert(Incident* incident){
    std::cout << "[ALERT] Evacuate " << incident->getLocation() << " immediately! \n";
}

void AlertService::sendSafetyAlert(Incident* incident){
    std::cout << "[ALERT] " << incident->getLocation() << " is now safe. \n";
}