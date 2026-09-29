#ifndef EMERGENCYFACADE_H
#define EMERGENCYFACADE_H

class Incident;
class IncidentService;
class Mediator;
class AccessControl;
class AlertService; 

class EmergencyFacade{
    private:
        IncidentService* incidentService;
        Mediator* mediator;
        AccessControl* accessControl;
        AlertService* alertService; 

    public: 
        EmergencyFacade( IncidentService* incidentService, Mediator* mediator, AccessControl* accessControl, AlertService* alertService);
        ~EmergencyFacade();
        void initiateEmergency(Incident* incident);
        void evacuateArea(Incident* incident);
        void resolveEmergency(Incident* incident);
};

#endif