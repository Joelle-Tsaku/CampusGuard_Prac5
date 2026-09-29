#include "IncidentService.h"
#include "Incident.h"

#include <algorithm>
#include <iostream>

IncidentService::IncidentService(){
}

IncidentService::~IncidentService(){
}

void IncidentService::addIncident(Incident* incident){

    if(incident == nullptr){
        std::cout << "[IncidentService] Cannot add invalid incident.\n";
        
        return;
    }

    incidents.push_back(incident);

    std::cout << "[IncidentService] Incident #" << incident->getId() << " added.\n";
}

void IncidentService::removeIncident(Incident* incident){
    incidents.erase(std::remove(incidents.begin(), incidents.end(), incident), incidents.end());
}

Incident* IncidentService::findIncident(int id){
    for(Incident* incident : incidents){
        if(incident->getId() == id){
            return incident;
        }
    }

    return nullptr;
}

void IncidentService::reportIncident(int id){
    Incident* incident = findIncident(id);

    if(incident == nullptr){
        std::cout << "[IncidentService] Incident #" << id << " not found.\n";
        
        return;
    }

    incident->report();
}

void IncidentService::activateIncident(int id){
    Incident* incident = findIncident(id);

    if(incident == nullptr){
        std::cout << "[IncidentService] Incident #" << id << " not found.\n";
        
        return;
    }

    incident->activate();
}

void IncidentService::containIncident(int id){
    Incident* incident = findIncident(id);

    if(incident == nullptr){
        std::cout << "[IncidentService] Incident #" << id << " not found.\n";
        
        return;
    }

    incident->contain();
}

void IncidentService::resolveIncident(int id){
    Incident* incident = findIncident(id);

    if(incident == nullptr){
        std::cout << "[IncidentService] Incident #" << id << " not found.\n";
        
        return;
    }

    incident->resolve();
}

void IncidentService::reportFalseAlarm(int id) {
    Incident* incident = findIncident(id);

    if(incident == nullptr){
        std::cout << "[IncidentService] Incident #" << id << " not found.\n";
        
        return;
    }

    incident->reportFalseAlarm();
}