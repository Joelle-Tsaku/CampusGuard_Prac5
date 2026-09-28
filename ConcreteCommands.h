#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H

#include "Command.h"
#include "ResponseUnit.h"
#include "Incident.h"

class DispatchUnitCommand : public Command {
private:
    ResponseUnit* receiver;
    Incident* incident;

public:
    DispatchUnitCommand(ResponseUnit* receiver, Incident* incident);
    void execute() override;
};

class SecureAreaCommand : public Command {
private:
    FacilitiesTeam* receiver;
    Incident* incident;

public:
    // Ties specifically to the FacilitiesTeam to lock down an area
    SecureAreaCommand(FacilitiesTeam* receiver, Incident* incident);
    void execute() override;
};

class IssueAlertCommand : public Command {
private:
    AlertService* receiver;
    Incident* incident;

public:
    // Ties specifically to the AlertService to broadcast emergencies
    IssueAlertCommand(AlertService* receiver, Incident* incident);
    void execute() override;
};

#endif
