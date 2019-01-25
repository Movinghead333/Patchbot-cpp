#ifndef __PATHFINDER_ROBOT_H_DEFINED__
#define __PATHFINDER_ROBOT_H_DEFINED__

#include "robot.h"

class Colony;

class PathfinderRobot : public Robot
{
	using Robot::Robot;
	void update(Colony& p_colony) override;

	bool check_collision(Tile& p_target_tile) override;
};

#endif