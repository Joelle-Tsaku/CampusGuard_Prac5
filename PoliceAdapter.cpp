#include "PoliceAdapter.h"
#include <iostream>

PoliceAdapter::PoliceAdapter(LegacyPoliceSystem* legacySystem, Mediator* mediator) 
    : ResponseUnit("CityPoliceAdapter", mediator), legacySystem(legacySystem) {}

PoliceAdapter::~PoliceAdapter() {
    if (legacySystem != nullptr) {
        delete legacySystem;
    }
}

void PoliceAdapter::respond(Incident* incident) {
    if (!incident) return;

    // 1. Translate the Incident into the legacy API's expected format.
    std::string locationCode = "ZONE-UNKNOWN";
    std::string severity = incident->getSeverity();

    // Basic parsing logic
    if (incident->getLocation().find("North") != std::string::npos) {
        locationCode = "ZONE-N1";
    } else if (incident->getLocation().find("South") != std::string::npos) {
        locationCode = "ZONE-S1";
    }

    // 2. Delegate the call to the legacy system
    legacySystem->requestPoliceBackup(locationCode, severity);
}
