#ifndef POLICE_ADAPTER_H
#define POLICE_ADAPTER_H

#include "ResponseUnit.h"
#include "LegacyPoliceSystem.h"
#include "Incident.h"
#include <string>

// The Adapter: Inherits from the Target interface (ResponseUnit) 
// but translates the calls to the Adaptee (LegacyPoliceSystem)
class PoliceAdapter : public ResponseUnit {
private:
    LegacyPoliceSystem* legacySystem;

public:
    PoliceAdapter(LegacyPoliceSystem* legacySystem, Mediator* mediator = nullptr);
    
    // Rule 4: Clear defensible destruction policy (Adapter cleans up Adaptee)
    ~PoliceAdapter() override;

    // The standardized method expected by Joelle's system
    void respond(Incident* incident) override;
};

#endif
