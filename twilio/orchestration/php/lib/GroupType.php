<?php
 
class GroupType {
	protected $size;
	protected $count;
	protected $activateOnBoot;
	protected $dependencies;

	public function __construct($size=Size::SMALL, $count=1, $activateOnBoot=false, $dependencies=[]) {
		$this->size = $size;
		$this->count = $count;
		$this->activateOnBoot = $activateOnBoot;
		$this->dependencies = $dependencies;
	}

	/**
	 * Get the ActivateOnBoot configuration setting for this GroupType
	 * @return bool Whether or not the hosts should activate once running
	 */
	public function getActivateOnBoot() {
		return $this->activateOnBoot;
	}

	/**
	 * Get the number of hosts in the GroupType
	 * @return int Number of hosts in the GroupType
	 */
	public function getCount() {
		return $this->count;
	}

	/**
	 * Get the array of GroupTypes the group depends on
	 * @return GroupType[] Dependencies array
	 */
	public function getDependencies() {
		return $this->dependencies;
	}

	/**
	 * Get the size of hosts in the GroupType
	 * @return string Size of Host to boot
	 */
	public function getSize() {
		return $this->size;
	}


}
