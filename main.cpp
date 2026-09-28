#include <iostream>
#include "Incident.h"
#include "IncidentState.h"

// #include "ResponseComponent.h"
// #include "Command.h"

int main() {
    std::cout << "Campus Guard System Initializing..." << std::endl;

    Incident incident1(1, "car crash", "Main Gate", "high");
    incident1.getStatus();

    incident1.report();
    incident1.getStatus();



    
    // ---------------------------------------------------------
    // Scenario 1: Command + Mediator Workflow
    // ---------------------------------------------------------
    // Instantiate receivers, configure mediator, execute commands

    // ---------------------------------------------------------
    // Scenario 2: Facade + Adapter Workflow
    // ---------------------------------------------------------
    // Instantiate legacy adapter, trigger high-level facade workflow

    return 0;
}