#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include "Incident.h"
#include <string>

class IncidentState{
    public:
        virtual void report(Incident* incident) = 0;
        virtual void activate(Incident* incident) = 0;
        virtual void contain(Incident* incident) = 0;
        virtual void resolve(Incident* incident) = 0;
        virtual void reportFalseAlarm(Incident* incident) = 0;

        virtual std::string getStatusName() = 0;

        virtual ~IncidentState(){}
};

// INCIDENT STATES
class ReportedState : public IncidentState {
    public: 
        void report(Incident* incident);
        void activate(Incident* incident);
        void contain(Incident* incident);
        void resolve(Incident* incident);
        void reportFalseAlarm(Incident* incident);

        std::string getStatusName();
        ~ReportedState(){}
};

class ActiveState : public IncidentState {
    public: 
        void report(Incident* incident);
        void activate(Incident* incident);
        void contain(Incident* incident);
        void resolve(Incident* incident);
        void reportFalseAlarm(Incident* incident);

        std::string getStatusName();
        ~ActiveState(){}
};

class ContainedState : public IncidentState {
    public:     
        void report(Incident* incident);
        void activate(Incident* incident);
        void contain(Incident* incident);
        void resolve(Incident* incident);
        void reportFalseAlarm(Incident* incident);

        std::string getStatusName();
        ~ContainedState(){}
};

class ResolvedState : public IncidentState {
    public:
        void report(Incident* incident);
        void activate(Incident* incident);
        void contain(Incident* incident);
        void resolve(Incident* incident);
        void reportFalseAlarm(Incident* incident);

        std::string getStatusName();
        ~ResolvedState(){}
};

class FalseAlarmState : public IncidentState {
    public:
        void report(Incident* incident);
        void activate(Incident* incident);
        void contain(Incident* incident);
        void resolve(Incident* incident);
        void reportFalseAlarm(Incident* incident);

        std::string getStatusName();
        ~FalseAlarmState(){}
};


#endif