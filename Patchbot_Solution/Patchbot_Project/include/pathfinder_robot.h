#ifndef __PATHFINDER_ROBOT_H_DEFINED__
#define __PATHFINDER_ROBOT_H_DEFINED__

#include "robot.h"

class PathfinderRobot : public Robot
{
	using Robot::Robot;
	void update() override;
};

#endif