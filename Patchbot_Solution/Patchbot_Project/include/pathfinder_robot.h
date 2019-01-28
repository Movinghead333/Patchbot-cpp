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

	bool check_line_of_sight(Colony& p_colony);

private: // member variables
	PathfinderState m_ai_state = PathfinderState::WAITING;

	// default value should never be used and thus can be (-1, -1)
	Point2D m_patchbot_pos = Point2D(-1, -1);

private: // member methods

	void move_on_best_path(Colony& p_colony);

	void move_to_last_known_location(Colony& p_colony);

	// returns true if the given tile could block line of sight
	bool is_line_of_sight_obstacle(const Tile& p_tile) const;
};

#endif