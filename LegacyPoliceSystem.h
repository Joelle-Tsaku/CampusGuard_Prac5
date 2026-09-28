#ifndef LEGACY_POLICE_SYSTEM_H
#define LEGACY_POLICE_SYSTEM_H

#include <string>
#include <iostream>

// The Adaptee: An external or legacy service with an incompatible interface.
// Notice it does NOT inherit from ResponseComponent and has a totally different method signature.
class LegacyPoliceSystem {
public:
    void requestPoliceBackup(std::string locationCode, std::string severityLevel);
};

#endif
