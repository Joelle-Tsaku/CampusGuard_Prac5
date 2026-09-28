#include "ConcreteCommands.h"

DispatchUnitCommand::DispatchUnitCommand(ResponseUnit* receiver, Incident* incident) 
    : receiver(receiver), incident(incident) {}

void DispatchUnitCommand::execute() {
    if (receiver && incident) {
        // Calls the base response method on any generic ResponseUnit
        receiver->respond(incident);
    }
}

SecureAreaCommand::SecureAreaCommand(FacilitiesTeam* receiver, Incident* incident)
    : receiver(receiver), incident(incident) {}

void SecureAreaCommand::execute() {
    if (receiver && incident) {
        // Uses Joelle's specific FacilitiesTeam method
        receiver->reportAreaSafety(incident);
    }
}

IssueAlertCommand::IssueAlertCommand(AlertService* receiver, Incident* incident)
    : receiver(receiver), incident(incident) {}

void IssueAlertCommand::execute() {
    if (receiver && incident) {
        // Uses Joelle's specific AlertService method
        receiver->sendEmergencyAlert(incident);
    }
}
