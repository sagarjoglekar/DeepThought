from random import randint
from time import time
import uuid


class Aws(object):
    instances = {}

    def list_instances(self):
        return self.instances.values()

    def provision_instance(self, size):
        instance = Instance(size)
        self.instances[instance.id] = instance
        return instance

    def delete_instance(self, instance):
        if isinstance(instance, Instance):
            instance = instance.id

        if instance in self.instances:
            del(self.instances[instance])
            return True

        return False


class Instance(object):
    PROVISIONING = 'provisioning'
    CONFIGURING = 'configuring'
    RUNNING = 'running'

    def __init__(self, size):
        self.id = str(uuid.uuid4()).split('-').pop()
        self.size = size
        self._booted = time()
        self._configuring = self._booted + randint(10, 60)
        self._running = self._configuring + randint(10, 60)

    def state(self):
        now = time()
        if now > self._running:
            return Instance.RUNNING
        elif now > self._configuring:
            return Instance.CONFIGURING
        else:
            return Instance.PROVISIONING

    def __repr__(self):
        return "<Instance {}-{} ({})>".format(self.size, self.id, self.state())


