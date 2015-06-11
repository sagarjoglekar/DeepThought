from host import Host


class Group(object):
    INIT = 'init'
    BOOTING = 'booting'
    RUNNING = 'running'
    SHUTTING_DOWN = 'shutting down'
    SHUTDOWN = 'shutdown'

    def __init__(self, description, type):
        """
        :param description:
        :type description: str
        :param type:
        :type type: GroupType
        :return:
        """
        # TODO: Implement this function
        pass

    def boot(self):
        """Starts booting new group. As the group boots it will go through
        `Group.BOOTING` state and end up in `Group.RUNNING`
        state when the process is complete. Group boot is complete when all
        hosts in a group are booted and in `Host.RUNNING` state.

        boot() should raise and IllegalStateException if the current group state
        does not permit this operation
        """
        # TODO: Implement this function
        pass

    def shutdown(self):
        """Initiates the shut down of the group by shutting down all hosts. As
        the group is shutting down it will go through `Group.SHUTTING_DOWN`
        state and end up `Group.SHUTDOWN` state when the process is complete.

        shutdown() should raise IllegalStateException if the current group state
        does not permit this operation
        """
        # TODO: Implement this function
        pass


class GroupType(object):
    def __init__(self, size=Host.SMALL, count=1, activate_on_boot=False, dependencies=None):
        self.size = size
        self.count = count
        self.activate_on_boot = activate_on_boot
        self.dependencies = dependencies or []



