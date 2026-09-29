#ifndef MEDIATOR_H
#define MEDIATOR_H

class Incident;
class ResponseUnit;

#include <string>
#include <vector>

class Mediator{
    public:
        Mediator(){};
        virtual ~Mediator(){};
        virtual void notify(ResponseUnit* sender, Incident* incident, const std::string& event) = 0;
};


class ResponseMediator : public Mediator {
    private:
        std::vector<ResponseUnit*> unitsList;

    public:
        ResponseMediator(){};
        ~ResponseMediator(){};

        void addUnit(ResponseUnit* unit);
        void removeUnit(ResponseUnit* unit);

        void notify(ResponseUnit* sender, Incident* incident, const std::string& event) override;
};


#endif