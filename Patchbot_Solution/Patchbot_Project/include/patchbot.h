#ifndef __PATCHBOT_H_DEFINED__
#define __PATCHBOT_H_DEFINED__

#include "robot.h"

class Colony;

class Patchbot : public Robot
{
public:
	// inherit constructor from robot
	using Robot::Robot;

	// override collision
	bool check_collision(Tile& p_target_tile) override;
};

#endif
