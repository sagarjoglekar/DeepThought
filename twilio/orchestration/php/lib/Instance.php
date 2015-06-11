<?php

/**
 * AWS Instance
 */
class Instance {
	const PROVISIONING = 'provisioning';
	const CONFIGURING = 'configuring';
	const RUNNING = 'running';

	protected $id;
	protected $size;
	protected $bootTime;
	protected $configuringTime;
	protected $runningTime;

	private static $ID_LENGTH = 7;

	/**
	 * Provision a new instance from AWS
	 * @param string $size
	 * @throws SizeException if the size is invalid
	 * @return Instance The newly provisioned instance
	 */
	public function __construct($size) {
		Size::validate($size);

		$this->id = $this->generateId(self::$ID_LENGTH);
		$this->size = $size;
		$this->bootTime = time();
		$this->configuringTime = $this->bootTime + rand(5, 10);
		$this->runningTime = $this->configuringTime + rand(5, 10);
	}

	/**
	 * Get the instance id
	 * @return string The instance id
	 */
	public function getId() {
		return $this->id;
	}

	/**
	 * Get the instance size
	 * @return string The size of the instance
	 */
	public function getSize() {
		return $this->size;
	}

	/**
	 * Check the instance's state
	 * This will be one of the state constants defined in this class
	 *
	 * @see Instance::PROVISIONING
	 * @see Instance::CONFIGURING
	 * @see Instance::RUNNING
	 *
	 * @return string The current state
	 */
	public function getState() {
		$now = time();
		if ($now > $this->runningTime) {
			return self::RUNNING;
		} else if ($now > $this->configuringTime) {
			return self::CONFIGURING;
		} else {
			return self::PROVISIONING;
		}
	}

	/**
	 * Human Friendly toString
	 * @return string Instance Representation
	 */
	function __toString() {
		return "<Instance {$this->size}-{$this->id} ({$this->getState()})>";
	}

	/**
	 * Generate a random string of a given length
	 * @param int $length The length of the string to generate
	 * @return string The random string
	 */
	protected function generateId($length) {
		return substr(md5(rand()), 0, $length);
	}
}
