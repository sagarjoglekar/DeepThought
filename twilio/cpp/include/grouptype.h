#ifndef GROUPTYPE_H_
#define GROUPTYPE_H_

#include <string>
#include <list>

#include "host.h"
#include "hosttype.h"

namespace twilio {

class GroupType: public HostType {
public:
    virtual ~GroupType() { }

public:
    // Returns host (instance) size for the group.
    virtual Host::HostSize getSize() = 0;

    // Returns the number of hosts (instances) for the group.
    virtual size_t getHostCount() = 0;

    // Returns the flag indicating whether host group should be activated
    // (brought into the load balancer) after successful boot or not.
    virtual bool isActiveOnBoot() = 0;

    //Returns the list of GroupTypes the group depends on.
    virtual std::list<GroupType *> getDependencies() = 0;
};

} // namespace twilio

#endif /* GROUPTYPE_H_ */
