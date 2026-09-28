#include "AccessControl.h"

#include <algorithm>
#include <iostream>

AccessControl::AccessControl(){}

AccessControl::~AccessControl(){}

bool AccessControl::isAreaLocked(const std::string& area) const {

    for(const std::string& lockedArea : lockedAreas){
        if(lockedArea == area){
            return true;
        }
    }

    return false;
}

void AccessControl::lockArea(const std::string& area){
    if(isAreaLocked(area)){
        std::cout << "[Access Control] " << area << " is already locked.\n";

        return;
    }

    lockedAreas.push_back(area);

    std::cout << "[Access Control] " << area << " has been locked.\n";
}

void AccessControl::unlockArea(const std::string& area){
    if(!isAreaLocked(area)){
        std::cout << "[Access Control] " << area << " is not currently locked.\n";

        return;
    }

    lockedAreas.erase(std::remove(lockedAreas.begin(), lockedAreas.end(), area), lockedAreas.end());

    std::cout << "[Access Control] " << area << " has been unlocked.\n";
}