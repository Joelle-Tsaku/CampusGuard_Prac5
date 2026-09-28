#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include <vector>

class IncidentState; 
class Observer;

class Incident{
    private:
        int id; 
        std::vector<Observer*> observers;
        std::string type;
        std::string location;
        std::string severity;

    protected:
        IncidentState* currentState;

    public:
        Incident(int id, std::string type, std::string location, std::string severity);
        virtual ~Incident();

        // Observer Pattern methods
        void attach(Observer* observer);
        void detach(Observer* observer);
        void notify();

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