#ifndef __BUGGER_H_DEFINED__
#define __BUGGER_H_DEFINED__

#include "robot.h"
#include "bugger_directions.h"
#include "bugger_state.h"
#include "point.h"
#include "tile.h"
#include "utility.h"

class Bugger : public Robot
{
public:
	Bugger(const Point2D& p_position, RobotType p_robot_type);

	// updates the Bugger for the current time step
	void update(Colony& p_colony) override;

	// calls reset from superclass and also reset AI specific variables
	void reset_robot() override;

	// returns true if the targeted tile is free to move on
	bool check_collision(Tile& p_target_tile) override;

	// returns the position where bugger is heading next
	Point2D get_target_position(BuggerDirections p_direction);

	// returns the next direction in clockwise manner
	BuggerDirections get_next_direction(BuggerDirections p_direction) const;

private: // member variables

	// stores the direction of the wall the bugger is currently following
	BuggerDirections m_current_wall = BuggerDirections::NORTH;

	// stores the AI state of the Bugger Robot
	BuggerState m_ai_state = BuggerState::FOLLOW_WALL;

	// stores the current starting position for Bugger AI
	Point2D m_start_position;

private: // member methods

	// functions taking care of updating the different AI states
	void check_find_another_wall(Colony& p_colony);
	void check_follow_wall(Colony& p_colony);
	void check_wait(Colony& p_colony);
};

#endif