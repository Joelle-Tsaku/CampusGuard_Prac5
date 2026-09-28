#include "PoliceAdapter.h"

PoliceAdapter::PoliceAdapter(LegacyPoliceSystem* legacySystem) : legacySystem(legacySystem) {}

PoliceAdapter::~PoliceAdapter() {
    if (legacySystem != nullptr) {
        delete legacySystem;
    }
}

void PoliceAdapter::takeAction(const std::string& actionDetails) {
    // 1. Translate the generic CampusGuard 'actionDetails' string into the legacy API's expected format.
    // In a real system we might parse JSON or a formatted string. Here we'll do a simple mock translation.
    std::string locationCode = "ZONE-UNKNOWN";
    std::string severity = "CRITICAL";

    // Basic parsing logic
    if (actionDetails.find("North") != std::string::npos) {
        locationCode = "ZONE-N1";
    } else if (actionDetails.find("South") != std::string::npos) {
        locationCode = "ZONE-S1";
    }

    // 2. Delegate the call to the legacy system
    legacySystem->requestPoliceBackup(locationCode, severity);
}
