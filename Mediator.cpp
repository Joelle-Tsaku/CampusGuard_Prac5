#include "Mediator.h"
#include "ResponseUnit.h"
#include "Incident.h"
#include <iostream>
#include <algorithm>

void ResponseMediator::addUnit(ResponseUnit* unit){
    unitsList.push_back(unit);
}

void ResponseMediator::removeUnit(ResponseUnit* unit){
    unitsList.erase(std::remove(unitsList.begin(), unitsList.end(), unit), unitsList.end());
}

void ResponseMediator::notify(ResponseUnit* sender, Incident* incident, const std::string& event){
    std::string senderName = sender ? sender->getName() : "System";

    if(event == "MEDICAL_NEEDED"){
        std::cout << "[Mediator] " << senderName << " reported that medical assistance is needed. \n";
        
        for(ResponseUnit* unit: unitsList){
            if(unit->getName() == "Medical Team" && !unit->isDispatched()){
                unit->respond(incident);
                break;
            }
        }
    }
    else if(event == "AREA_UNSAFE"){
        std::cout << "[Mediator] " << senderName << " reported an unsafe area...Coordinating medical response \n";

        for(ResponseUnit* unit: unitsList){
            if((unit->getName() == "Security Team" || unit->getName() == "Alert Service")  && !unit->isDispatched()){
                unit->respond(incident);
                break; 
            }
        }
    }
    else if(event == "SECURITY_NEEDED"){
        std::cout << "[Mediator] " << senderName << " reported security is needed \n";
        
        for(ResponseUnit* unit: unitsList){
            if(unit->getName() == "Security Team"  && !unit->isDispatched()){
                unit->respond(incident);
                break;
            }
        } 
    }
}
