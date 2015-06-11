/*
 * grouptypeimpl.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ykhodosh
 */

#ifndef GROUPTYPEIMPL_H_
#define GROUPTYPEIMPL_H_

#include "host.h"
#include "grouptype.h"

namespace twilio
{

class GroupTypeImpl: public GroupType
{
public:
    GroupTypeImpl ();
    virtual ~GroupTypeImpl () {
        // TODO Auto-generated destructor stub
    }

public:
    // Returns the host (instance) type ID.
    virtual std::string getId() { return this->id_; }

    // Returns the host (instance) type (role).
    virtual std::string getType() { return this->type_; }

    // Returns the host (instance) type description.
    virtual std::string getDescription() { return this->description_; }

    // Returns host (instance) size for the group.
    virtual Host::HostSize getSize() { return this->size_; }

    // Returns the number of hosts (instances) for the group.
    virtual size_t getHostCount() { return this->count_; }

    // Returns the flag indicating whether host group should be activated
    // (brought into the load balancer) after successful boot or not.
    virtual bool isActiveOnBoot() { return this->activate_; }

    //Returns the list of GroupTypes the group depends on.
    virtual std::list<GroupType *> getDependencies() {
        return this->dependencies_;
    }

private:
    std::string id_;
    std::string type_;
    std::string description_;
    size_t count_;
    bool activate_;
    Host::HostSize size_;
    std::list<GroupType *> dependencies_;
};

} /* namespace twilio */

#endif /* GROUPTYPEIMPL_H_ */
