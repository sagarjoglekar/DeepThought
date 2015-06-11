<?php
 
class AWS {
	protected static $instances = [];

	/**
	 * Provides a mapping from instance id to instance object for
	 * all instances currently being tracked by AWS.
	 * @return Instance[] Instance Map
	 */
	public static function listInstances() {
		return self::$instances;
	}

	/**
	 * @param string $size
	 * @throws SizeException if the size is invalid
	 * @return Instance
	 */
	public static function provisionInstance($size) {
		Size::validate($size);

		$instance = new Instance($size);
		self::$instances[$instance->getId()] = $instance;
		return $instance;
	}

	public static function destroyInstance($instance) {
		if ($instance instanceof Instance) {
			$instance = $instance->getId();
		}

		if (!array_key_exists($instance, self::$instances)) {
			return false;
		}

		// Remove the instance from AWS
		unset(self::$instances[$instance]);
		return true;
	}

}
