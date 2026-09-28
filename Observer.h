#ifndef OBSERVER_H
#define OBSERVER_H

class Incident;

class Observer {
public:
    virtual ~Observer() = default;

    // Called by the Subject (Incident) when its state changes
    virtual void update(Incident* incident) = 0;
};

#endif
