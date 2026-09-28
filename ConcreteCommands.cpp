#include "ConcreteCommands.h"

DispatchUnitCommand::DispatchUnitCommand(ResponseComponent* receiver, Incident* incident) 
    : receiver(receiver), incident(incident) {}

void DispatchUnitCommand::execute() {
    if (receiver && incident) {
        std::string action = "Dispatching unit to Incident #" + std::to_string(incident->getId()) + 
                             " at " + incident->getLocation();
        receiver->takeAction(action);
    }
}

SecureAreaCommand::SecureAreaCommand(ResponseComponent* receiver, std::string location)
    : receiver(receiver), location(location) {}

void SecureAreaCommand::execute() {
    if (receiver) {
        std::string action = "Securing area and restricting access: " + location;
        receiver->takeAction(action);
    }
}

IssueAlertCommand::IssueAlertCommand(ResponseComponent* receiver, std::string alertMessage)
    : receiver(receiver), alertMessage(alertMessage) {}

void IssueAlertCommand::execute() {
    if (receiver) {
        std::string action = "Broadcasting Emergency Alert: " + alertMessage;
        receiver->takeAction(action);
    }
}
