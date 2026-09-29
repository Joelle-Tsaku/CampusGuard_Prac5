#include "LegacyPoliceSystem.h"

void LegacyPoliceSystem::requestPoliceBackup(std::string locationCode, std::string severityLevel) {
    std::cout << ">>> [EXTERNAL CITY POLICE API] Backup dispatched to Zone: " 
              << locationCode << " | Threat Level: " << severityLevel << " <<<\n";
}
