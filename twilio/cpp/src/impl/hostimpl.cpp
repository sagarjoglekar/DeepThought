/*
 * hostimpl.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: ykhodosh
 */

#include "hostimpl.h"

namespace twilio
{

HostImpl::HostImpl () {
    // TODO Auto-generated constructor stub
}

// Starts booting new host (instance). As the host boots it will go through
// HostState.BOOTING and HostState.CONFIGURING states. When
// a host is up and running it will transition to HostState.RUNNING.
void HostImpl::boot() {
    // TODO Auto-generated method stub
}

// Activates the host (instance), which will put it into the load balancer.
void HostImpl::activate() {
    // TODO Auto-generated method stub
}

// De-activates the host (instance), which will take it out of the load
// balancer.
void HostImpl::deactivate() {
    // TODO Auto-generated method stub
}

// Initiates the shut down of the host (instance). As the host is shutting
// down it will go through HostState.SHUTTING_DOWN state and end up
// HostState.SHUTDOWN when the process is complete.
//
// Note that active hosts (in LB) cannot be shut down. They must be taken
// out of the load balancer first.
void HostImpl::shutdown() {
    // TODO Auto-generated method stub
}

} /* namespace twilio */
