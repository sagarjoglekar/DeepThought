<?php

// Including autoload.php will make everything in /lib available to the script
include 'autoload.php';

// Provision a LARGE AWS instance
echo "Provisioning an Instance" . PHP_EOL;
$instance = AWS::provisionInstance(Size::LARGE);

// Loop until the instance is running, output some status to the user
while ($instance->getState() != Instance::RUNNING) {
	Console::out("WAITING $instance");
	sleep(1);
}

// Success!
Console::out("RUNNING $instance");
