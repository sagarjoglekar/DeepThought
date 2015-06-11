<?php
 
class Group {
	const INIT = 'init';
	const BOOTING = 'booting';
	const RUNNING = 'running';
	const SHUTTING_DOWN = 'shutting-down';
	const SHUTDOWN = 'shutdown';

	protected $description;
	protected $type;

	/**
	 * Construct a new Group
	 * @param string $description The friendly description for the group
	 * @param GroupType $type The group type
	 */
	public function __construct($description, GroupType $type) {
		// TODO: Implement
	}

	public function boot() {

	}

	public function shutdown() {

	}
}
