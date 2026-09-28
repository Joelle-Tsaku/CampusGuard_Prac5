#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

#include "Command.h"
#include <vector>

// This acts as the Invoker in the Command Pattern
class ControlPanel {
private:
    std::vector<Command*> commandHistory;

public:
    ~ControlPanel();
    
    // Executes a command and takes ownership of its memory
    void executeCommand(Command* command);
};

#endif
