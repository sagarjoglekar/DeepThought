/*
 * hostimpl.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ykhodosh
 */

#ifndef HOSTIMPL_H_
#define HOSTIMPL_H_

#include "host.h"
#include "hosttypeimpl.h"

namespace twilio
{

class HostImpl: public Host
{
public:
    HostImpl ();
    virtual ~HostImpl () {
        // TODO Auto-generated destructor stub
    }

public:
    // Returns the host (instance) ID.
    std::string getId() { return this->id_; }

    // Returns host (instance) type.
    std::string getType() { return this->type_.getType(); }

    // Returns host (instance) description.
    std::string getDescription() { return this->description_; }

    // Returns host (instance) size.
    Host::HostSize getSize() { return this->size_; }

    // Returns current host (instance) state.
    Host::HostState getState() { return this->state_; }

    // Returns current host (instance) load balancer state.
    bool isActive() { return this->active_; }

    // Starts booting new host (instance). As the host boots it will go through
    // HostState.BOOTING and HostState.CONFIGURING states. When
    // a host is up and running it will transition to HostState.RUNNING.
    void boot();

    // Activates the host (instance), which will put it into the load balancer.
    void activate();

    // De-activates the host (instance), which will take it out of the load
    // balancer.
    void deactivate();

    // Initiates the shut down of the host (instance). As the host is shutting
    // down it will go through HostState.SHUTTING_DOWN state and end up
    // HostState.SHUTDOWN when the process is complete.
    //
    // Note that active hosts (in LB) cannot be shut down. They must be taken
    // out of the load balancer first.
    void shutdown();

private:
    std::string id_;
    std::string description_;
    HostTypeImpl type_;
    volatile bool active_;
    Host::HostSize size_;
    volatile HostState state_;
};

} /* namespace twilio */

#endif /* HOSTIMPL_H_ */
