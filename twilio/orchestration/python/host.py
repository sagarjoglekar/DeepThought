class Host(object):
    # States
    INIT = 'init'
    BOOTING = 'booting'
    CONFIGURING = 'configuring'
    RUNNING = 'running'
    SHUTTING_DOWN = 'shutting_down'
    SHUTDOWN = 'shutdown'

    # Sizes
    SMALL = 'small'
    MEDIUM = 'medium'
    LARGE = 'large'

    def __init__(self, description, size):
        # TODO: Implement this function
        pass

    def boot(self):
        """Starts booting new host (instance). As the host boots it will go
        through `Host.BOOTING` and `Host.CONFIGURING` states. When a host is up
        and running it will transition to `Host.RUNNING`

        boot() should raise an IllegalStateException if the current host state
        does not permit this action
        """
        # TODO: Implement this function
        pass

    def activate(self):
        """Activates the host (instance), which will put it into the load
        balancer.

        activate() should raise an IllegalStateException if the current host
        state does not permit this action
        """
        # TODO: Implement this function
        pass

    def deactivate(self):
        """De-activates the host (instance), which will take it out of the load
        balancer.

        deactivate() should raise an IllegalStateException if the current host
        state does not permit this action
        """
        # TODO: Implement this function
        pass

    def shutdown(self):
        """Initiates the shut down of the host (instance). As the host is
        shutting down it will go through `Host.SHUTTING_DOWN` state and end up
        in `Host.SHUTDOWN` when the process is complete.

        Note that active hosts (in LB) cannot be shut down. They must be taken
        out of the load balancer first.

        shutdown() should raise an IllegalStateException if the current host
        state does not permit this action
        """
        # TODO: Implement this function
        pass
