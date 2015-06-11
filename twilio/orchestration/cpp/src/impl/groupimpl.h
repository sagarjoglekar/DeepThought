/*
 * groupimpl.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ykhodosh
 */

#ifndef GROUPIMPL_H_
#define GROUPIMPL_H_

#include "group.h"
#include "grouptypeimpl.h"

namespace twilio
{

class GroupImpl: public Group
{
public:
    GroupImpl ();
    virtual ~GroupImpl () {
        // TODO Auto-generated destructor stub
    }

public:
    // Returns the group ID.
    virtual std::string getId() { return this->id_; }

    // Returns group type.
    virtual std::string getType() { return this->type_.getType(); }

    // Returns group description.
    virtual std::string getDescription() { return this->description_; }

    // Returns current group state.
    virtual GroupState getState() = 0;

    // Returns the list of hosts in a group.
    virtual std::list<Host *> getHosts() { return this->hosts_; }

    // Starts booting new group. As the group boots it will go through
    // GroupState.BOOTING state and end up in GroupState.RUNNING
    // state when the process is complete. Group boot is complete when all hosts
    // in a group are booted and in HostState.RUNNING state.
    virtual void boot();

    // Initiates the shut down of the host (instance). As the host is shutting
    // down it will go through HostState.SHUTTING_DOWN state and end up
    // in HostState.SHUTDOWN when the process is complete.
    //
    // Note that active hosts (in LB) cannot be shut down. They must be taken
    // out of the load balancer first.
    virtual void shutdown();

private:
    std::string id_;
    std::string description_;
    GroupTypeImpl type_;
    std::list<Host *> hosts_;
    volatile Group::GroupState state_;
};

} /* namespace twilio */

#endif /* GROUPIMPL_H_ */
