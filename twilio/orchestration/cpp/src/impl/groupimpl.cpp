/*
 * groupimpl.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: ykhodosh
 */

#include "groupimpl.h"

namespace twilio
{

GroupImpl::GroupImpl () {
    // TODO Auto-generated constructor stub
}

// Starts booting new group. As the group boots it will go through
// GroupState.BOOTING state and end up in GroupState.RUNNING
// state when the process is complete. Group boot is complete when all hosts
// in a group are booted and in HostState.RUNNING state.
void GroupImpl::boot() {
    // TODO Auto-generated method stub
}

// Initiates the shut down of the host (instance). As the host is shutting
// down it will go through HostState.SHUTTING_DOWN state and end up
// in HostState.SHUTDOWN when the process is complete.
//
// Note that active hosts (in LB) cannot be shut down. They must be taken
// out of the load balancer first.
void GroupImpl::shutdown() {
    // TODO Auto-generated method stub
}

} /* namespace twilio */
