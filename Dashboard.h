#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "Observer.h"

class Dashboard : public Observer {
public:
    Dashboard() = default;
    virtual ~Dashboard() = default;

    // Triggered automatically whenever an incident changes state
    void update(Incident* incident) override;
};

#endif
