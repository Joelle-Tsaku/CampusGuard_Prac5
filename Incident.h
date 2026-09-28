#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
class IncidentState; 

class Incident{
    private:
        int id; 
        std::string type;
        std::string location;
        std::string severity;

    protected:
        IncidentState* currentState;

    public:
        Incident(int id, std::string type, std::string location, std::string severity);
        ~Incident();

        void report();
        void activate();
        void contain();
        void resolve();
        void reportFalseAlarm();
        void setState(IncidentState* newState);

        std::string getLocation() const;
        std::string getSeverity() const;
        std::string getType() const;
        int getId() const;
        std::string getStatus() const;
};

#endif