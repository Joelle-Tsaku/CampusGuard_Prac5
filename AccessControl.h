#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H

#include <string>
#include <vector>

class AccessControl {
    private:
        std::vector<std::string> lockedAreas;

    public:
        AccessControl(){}
        virtual ~AccessControl(){}

        virtual void lockArea(const std::string& area) = 0;
        virtual void unlockArea(const std::string& area) = 0;

        bool isAreaLocked(const std::string& area) const;
};

#endif