<?php
 
class Host {
	const INIT = 'init';
	const BOOTING = 'booting';
	const CONFIGURING = 'configuring';
	const RUNNING = 'running';
	const SHUTTING_DOWN = 'shutting-down';
	const SHUTDOWN = 'shutdown';

	protected $description;
	protected $size;

	public function __construct($description, $size) {
		// TODO: Implement
	}

	/**
	 * Starts booting new host (instance). As the host boots it will go
	 * through Host::BOOTING and Host::CONFIGURING states. When a host is up
	 * and running it will transition to Host::RUNNING
	 * @throws IllegalStateException if the current host state does not permit
	 * 								 this action
	 */
	public function boot() {
		// TODO: Implement
	}

	/**
	 * Activates the host (instance), which will put it into the load
	 * balancer.
	 * @throws IllegalStateException if the current host state does not permit
	 *  							 this action
	 */
	public function activate() {
		// TODO: Implement
	}

	/**
	 * De-activates the host (instance), which will take it out of the load
	 * balancer.
	 * @throws IllegalStateException if the current host state does not permit
	 *  							 this action
	 */
	public function deactivate() {
		// TODO: Implement
	}

	/**
	 * Initiates the shut down of the host (instance). As the host is
	 * shutting down it will go through Host::SHUTTING_DOWN state and end up
	 * in Host::SHUTDOWN when the process is complete.
	 *
	 * Note that active hosts (in LB) cannot be shut down. They must be taken
	 * out of the load balancer first.
	 * @throws IllegalStateException if the current host state does not permit
	 *  							 this action
	 */
	public function shutdown() {
		// TODO: Implement
	}


}
