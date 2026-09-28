#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    virtual ~Command() = default;
    
    // The core interface for all operator actions
    virtual void execute() = 0;
};

#endif