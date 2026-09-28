#ifndef RESPONSE_COMPONENT_H
#define RESPONSE_COMPONENT_H

#include <string>

// Forward declaration if Joelle uses a Mediator pointer in the base class
class Mediator; 

class ResponseComponent {
protected:
    Mediator* mediator; // Often required for the Colleague role

public:
    virtual ~ResponseComponent() = default;
    
    // Abstract method to be implemented by Security, Medical, Facilities, etc.
    virtual void takeAction(const std::string& actionDetails) = 0;
    
    void setMediator(Mediator* m) {
        mediator = m;
    }
};

#endif