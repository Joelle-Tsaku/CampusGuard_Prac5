#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

class Mediator;
class Incident;
#include <string>

class ResponseUnit{
    protected:
        std::string name; 
        Mediator* mediator; 
        bool dispatched;

    public:
        ResponseUnit(std::string name, Mediator* mediator);
        virtual ~ResponseUnit();
        virtual void respond(Incident* incident) = 0;
        bool isDispatched();
        std::string getName() const;
};

class SecurityTeam : public ResponseUnit {
    public:
        SecurityTeam(Mediator* mediator);
        ~SecurityTeam(){}

        void respond(Incident* incident); 
        void dispatch(Incident* incident); 

        void reportMedicalEmergency(Incident* incident); 
        void reportAreaSafety(Incident* incident); 
};

class MedicalTeam : public ResponseUnit {
    public:
        MedicalTeam(Mediator* mediator);
        ~MedicalTeam(){}

        void respond(Incident* incident); 
        void dispatch(Incident* incident); 

        void requestAccess(Incident* incident); 
};

class FacilitiesTeam : public ResponseUnit {
    public:
        FacilitiesTeam(Mediator* mediator);
        ~FacilitiesTeam(){}

        void respond(Incident* incident); 
        void dispatch(Incident* incident);

        void reportAreaSafety(Incident* incident); 
};

class AlertService : public ResponseUnit {
    public:
        AlertService(Mediator* mediator);
        ~AlertService(){}

        void respond(Incident* incident);

        void sendEvacuationAlert(Incident* incident); 
        void sendEmergencyAlert(Incident* incident); 
        void sendSafetyAlert(Incident* incident);
};

#endif
