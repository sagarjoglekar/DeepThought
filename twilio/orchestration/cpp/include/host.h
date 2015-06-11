#ifndef HOST_H_
#define HOST_H_

#include <string>

namespace twilio {

class Host {
public:
    typedef enum {
        CREATED,
        BOOTING,
        CONFIGURING,
        RUNNING,
        SHUTTING_DOWN,
        SHUTDOWN
    } HostState;

    typedef enum {
        SMALL,
        MEDIUM,
        LARGE
    } HostSize;

public:
    virtual ~Host () { }

public:
    // Returns the host (instance) ID.
    virtual std::string getId() = 0;

    // Returns host (instance) type.
    virtual std::string getType() = 0;

    // Returns host (instance) description.
    virtual std::string getDescription() = 0;

    // Returns host (instance) size.
    virtual HostSize getSize() = 0;

    // Returns current host (instance) state.
    virtual HostState getState() = 0;

    // Returns current host (instance) load balancer state.
    virtual bool isActive() = 0;

    // Starts booting new host (instance). As the host boots it will go through
    // HostState.BOOTING and HostState.CONFIGURING states. When
    // a host is up and running it will transition to HostState.RUNNING.
    virtual void boot() = 0;

    // Activates the host (instance), which will put it into the load balancer.
    virtual void activate() = 0;

    // De-activates the host (instance), which will take it out of the load
    // balancer.
    virtual void deactivate() = 0;

    // Initiates the shut down of the host (instance). As the host is shutting
    // down it will go through HostState.SHUTTING_DOWN state and end up
    // HostState.SHUTDOWN when the process is complete.
    //
    // Note that active hosts (in LB) cannot be shut down. They must be taken
    // out of the load balancer first.
    virtual void shutdown() = 0;
};

} // namespace twilio

#endif /* HOST_H_ */
