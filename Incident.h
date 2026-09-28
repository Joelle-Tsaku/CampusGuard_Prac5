#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

// Forward declaration for the State pattern (Joelle's task)
class IncidentState;

class Incident {
private:
    std::string id;
    std::string type;
    int severity;
    IncidentState* currentState; // Ownership policy must be managed in the .cpp

public:
    Incident(std::string id, std::string type, int severity);
    virtual ~Incident(); 

    // Methods for Joelle's State pattern and your Observer pattern to hook into
    void changeState(IncidentState* newState);
    std::string getStatus() const;
    std::string getId() const { return id; }
};

#endif