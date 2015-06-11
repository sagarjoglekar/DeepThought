
#ifndef GROUP_H_
#define GROUP_H_

#include <string>
#include <list>

#include "host.h"

namespace twilio {

class Group {
public:
    virtual ~Group() { }

public:
    typedef enum {
        CREATED,
        BOOTING,
        RUNNING,
        SHUTTING_DOWN,
        SHUTDOWN
    } GroupState;

    // Returns the group ID.
    virtual std::string getId() = 0;

    // Returns group type.
    virtual std::string getType() = 0;

    // Returns group description.
    virtual std::string getDescription() = 0;

    // Returns current group state.
    virtual GroupState getState() = 0;

    // Returns the list of hosts in a group.
    virtual std::list<Host *> getHosts() = 0;

    // Starts booting new group. As the group boots it will go through
    // GroupState.BOOTING state and end up in GroupState.RUNNING
    // state when the process is complete. Group boot is complete when all hosts
    // in a group are booted and in HostState.RUNNING state.
    virtual void boot() = 0;

    // Initiates the shut down of the host (instance). As the host is shutting
    // down it will go through HostState.SHUTTING_DOWN state and end up
    // in HostState.SHUTDOWN when the process is complete.
    //
    // Note that active hosts (in LB) cannot be shut down. They must be taken
    // out of the load balancer first.
    virtual void shutdown() = 0;
};

} // namespace twilio

#endif /* GROUP_H_ */
