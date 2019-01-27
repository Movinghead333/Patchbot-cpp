#ifndef __PATHFINDER_ROBOT_H_DEFINED__
#define __PATHFINDER_ROBOT_H_DEFINED__

#include "robot.h"
#include "pathfinder_state.h"
#include "point.h"

class Colony;

class PathfinderRobot : public Robot
{
	using Robot::Robot;
	void update(Colony& p_colony) override;

	void check_waiting(Colony& p_colony);
	void check_following(Colony& p_colony);
	void check_hunting(Colony& p_colony);

	bool check_collision(Tile& p_target_tile) override;

	bool check_reachable(Colony& p_colony);

	bool check_line_of_sight();

private:
	PathfinderState m_ai_state;

	Point2D m_patchbot_pos;
};

#endif