#ifndef POLICE_ADAPTER_H
#define POLICE_ADAPTER_H

#include "ResponseComponent.h"
#include "LegacyPoliceSystem.h"
#include <string>

// The Adapter: Inherits from the Target interface (ResponseComponent) 
// but translates the calls to the Adaptee (LegacyPoliceSystem)
class PoliceAdapter : public ResponseComponent {
private:
    LegacyPoliceSystem* legacySystem;

public:
    PoliceAdapter(LegacyPoliceSystem* legacySystem);
    
    // Rule 4: Clear defensible destruction policy (Adapter cleans up Adaptee)
    ~PoliceAdapter() override;

    // The standardized method expected by the rest of CampusGuard
    void takeAction(const std::string& actionDetails) override;
};

#endif
