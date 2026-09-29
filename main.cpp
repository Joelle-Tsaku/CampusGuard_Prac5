#include <iostream>
#include "Incident.h"
#include "Dashboard.h"
#include "ControlPanel.h"
#include "ConcreteCommands.h"
#include "Mediator.h"
#include "ResponseUnit.h"
#include "EmergencyFacade.h"
#include "IncidentService.h"
#include "AccessControl.h"
#include "PoliceAdapter.h"
#include "LegacyPoliceSystem.h"

int main() {
    std::cout << "\n============================================\n";
    std::cout << "  CAMPUS GUARD SYSTEM INITIALIZING...       \n";
    std::cout << "============================================\n";

    // =========================================================
    // SCENARIO 1: Command + Mediator + Observer + State
    // =========================================================
    std::cout << "\n>>> SCENARIO 1: Minor Incident Escalation <<<\n\n";
    
    // 1. Observer & State Setup
    Dashboard dashboard; // Concrete Observer
    Incident* incident1 = new Incident(101, "Suspicious Activity", "North Library", "Low");
    incident1->attach(&dashboard);
    
    std::cout << "-- Operator reports the incident --\n";
    incident1->report();   // State -> Reported, notifies Dashboard
    incident1->activate(); // State -> Active, notifies Dashboard

    // 2. Mediator Setup
    ResponseMediator* mediator = new ResponseMediator();
    SecurityTeam* security = new SecurityTeam(mediator);
    MedicalTeam* medical = new MedicalTeam(mediator);
    
    mediator->addUnit(security);
    mediator->addUnit(medical);

    // 3. Command Setup
    ControlPanel controlPanel; // Invoker
    Command* dispatchSec = new DispatchUnitCommand(security, incident1);
    
    std::cout << "\n-- Operator uses Command Panel to dispatch Security --\n";
    controlPanel.executeCommand(dispatchSec); // Triggers security->respond()

    // 4. Mediator Coordination
    std::cout << "\n-- Security team discovers injuries and requests Medical via Mediator --\n";
    security->reportMedicalEmergency(incident1); // Mediator auto-dispatches MedicalTeam

    std::cout << "\n-- Incident Contained and Resolved --\n";
    incident1->contain();
    incident1->resolve();

    // =========================================================
    // SCENARIO 2: Facade + Adapter + State
    // =========================================================
    std::cout << "\n============================================\n";
    std::cout << ">>> SCENARIO 2: Major Campus Emergency <<<\n\n";

    Incident* incident2 = new Incident(202, "Fire Outbreak", "Chemistry Lab", "Critical");
    incident2->attach(&dashboard); // Attach observer here too!
    
    // 1. Facade Subsystems
    IncidentService* incService = new IncidentService();
    incService->addIncident(incident2);
    
    AccessControl* accessCtrl = new AccessControl();
    AlertService* alerts = new AlertService(mediator);
    mediator->addUnit(alerts);

    EmergencyFacade facade(incService, mediator, accessCtrl, alerts);

    std::cout << "-- Operator triggers Facade for full emergency lockdown --\n";
    // Facade triggers activateIncident, Mediator SECURITY_NEEDED, AccessControl lockArea, AlertService
    incident2->report(); // Must be reported before Facade can activate it
    facade.initiateEmergency(incident2);
    facade.evacuateArea(incident2);

    // 2. Adapter Setup
    std::cout << "\n-- System Adapter automatically requests City Police backup --\n";
    LegacyPoliceSystem* legacyPolice = new LegacyPoliceSystem();
    PoliceAdapter* policeAdapter = new PoliceAdapter(legacyPolice, mediator);
    
    // Adapter seamlessly uses standard ResponseUnit interface to call legacy API
    policeAdapter->respond(incident2);

    std::cout << "\n-- Facade resolves the emergency --\n";
    facade.resolveEmergency(incident2);

    // =========================================================
    // MEMORY CLEANUP
    // =========================================================
    // Delete all dynamically allocated objects to pass Valgrind memory leak tests
    delete incident1;
    delete incident2;
    delete security;
    delete medical;
    delete alerts;
    delete policeAdapter; // Note: Adapter deletes legacyPolice internally!
    delete mediator;
    delete incService;
    delete accessCtrl;
    
    // Note: ControlPanel deletes its commands automatically in its destructor!

    std::cout << "\n============================================\n";
    std::cout << "  CAMPUS GUARD SYSTEM SHUTTING DOWN...      \n";
    std::cout << "============================================\n\n";

    return 0;
}