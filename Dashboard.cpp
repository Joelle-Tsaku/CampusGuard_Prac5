#include "Dashboard.h"
#include "Incident.h"
#include <iostream>

void Dashboard::update(Incident* incident) {
    if (incident != nullptr) {
        std::cout << "\n=== [DASHBOARD UPDATE] ===" << std::endl;
        std::cout << "Incident ID : " << incident->getId() << std::endl;
        std::cout << "Type        : " << incident->getType() << std::endl;
        std::cout << "Location    : " << incident->getLocation() << std::endl;
        std::cout << "Severity    : " << incident->getSeverity() << std::endl;
        
        // This relies on Joelle's State pattern implementation
        // std::cout << "New Status  : " << incident->getStatus() << std::endl;
        
        std::cout << "==========================\n" << std::endl;
    }
}
