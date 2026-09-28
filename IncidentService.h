#ifndef INCIDENTSERVICE_H
#define INCIDENTSERVICE_H

#include <vector>

class Incident;

class IncidentService {
private:
    std::vector<Incident*> incidents;

public:
    IncidentService();
    ~IncidentService();

    void addIncident(Incident* incident);
    void removeIncident(Incident* incident);

    Incident* findIncident(int id);

    void reportIncident(int id);
    void activateIncident(int id);
    void containIncident(int id);
    void resolveIncident(int id);
    void reportFalseAlarm(int id);
};

#endif