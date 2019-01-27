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
	Bugger(Point2D p_position, RobotType p_robot_type);
	void update(Colony& p_colony) override;

	void reset_robot() override;

	// returns true if the targeted tile is free to move on
	bool check_collision(Tile& p_target_tile) override;

	Point2D get_target_position(BuggerDirections p_direction);

	// returns true if the bugger is on its current starting position
	bool check_for_starting_position(Point2D p_target_point);

	BuggerDirections get_next_direction(BuggerDirections p_direction);

	void check_find_another_wall(Colony& p_colony);
	void check_follow_wall(Colony& p_colony);
	void check_wait(Colony& p_colony);

	// getters and setters
	void set_m_current_wall(BuggerDirections p_current_wall);
	BuggerDirections get_m_current_wall() const;

	void set_m_ai_state(BuggerState p_state);
	BuggerState get_m_ai_state() const;

	void set_starting_position(Point2D p_position);

private:
	BuggerDirections m_current_wall = BuggerDirections::NORTH;
	BuggerState m_ai_state = BuggerState::FOLLOW_WALL;

	Point2D m_start_position;
};

#endif