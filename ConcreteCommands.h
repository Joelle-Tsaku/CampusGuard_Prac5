#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H

#include "Command.h"
#include "ResponseComponent.h"
#include "Incident.h"
#include <string>

class DispatchUnitCommand : public Command {
private:
    ResponseComponent* receiver;
    Incident* incident;

public:
    DispatchUnitCommand(ResponseComponent* receiver, Incident* incident);
    void execute() override;
};

class SecureAreaCommand : public Command {
private:
    ResponseComponent* receiver;
    std::string location;

public:
    SecureAreaCommand(ResponseComponent* receiver, std::string location);
    void execute() override;
};

class IssueAlertCommand : public Command {
private:
    ResponseComponent* receiver;
    std::string alertMessage;

public:
    IssueAlertCommand(ResponseComponent* receiver, std::string alertMessage);
    void execute() override;
};

#endif
