#include "EmergencyFacade.h"
#include <iostream>

EmergencyFacade::EmergencyFacade( IncidentService* incidentService, ResponseUnit* mediator, AccessControl* accessControl, AlertService* alertService)
    : incidentService(incidentService), mediator(mediator), accessControl(accessControl), alertService(alertService) {}

EmergencyFacade::~EmergencyFacade(){}

void EmergencyFacade::initiateEmergency(Incident* incident){
    if(incident == nullptr){
        std::cout << "[Facade] Cannot instantiate emergency: Incident is empty. \n";
        
        return; 
    }

    std::cout << "\n[Facade] Initiating emergency response for incident #" << incident->getId() << std::endl;

    incidentService->activateIncident(incident->getId());

    mediator->notify(nullptr, incident, "SECURITY_NEEDED");

    accessControl->lockArea(incident->getLocation());
    
    alertService->sendEmergencyAlert(incident); 

    std::cout << "[Facade] Emergency response initialised. \n"; 
}

void EmergencyFacade::evacuateArea(Incident* incident){
    if(incident == nullptr){
        std::cout << "[Facade] Invalid incident.\n";
        return;
    }

    std::cout << "\n EVACUATING AREA \n";

    accessControl->lockArea(
        incident->getLocation()
    );

    mediator->notify(
        nullptr,
        incident,
        "SECURITY_NEEDED"
    );

    alertService->sendEvacuationAlert(
        incident
    );
}

void EmergencyFacade::resolveEmergency(Incident* incident){
    if(incident == nullptr){
        std::cout << "[Facade] Invalid incident.\n";
        return;
    }

    std::cout << "\n RESOLVING EMERGENCY \n";

    incidentService->resolveIncident(incident->getId());

    accessControl->unlockArea(incident->getLocation());

    alertService->sendSafetyAlert(incident);

    std::cout << "EMERGENCY RESOLVED\n";
}
