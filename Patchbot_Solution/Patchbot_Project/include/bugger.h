#ifndef __BUGGER_H_DEFINED__
#define __BUGGER_H_DEFINED__

#include "robot.h"
#include "bugger_directions.h"
#include "bugger_states.h"
#include "point.h"
#include "tile.h"

class Bugger : public Robot
{
public:
	Bugger(Point2D p_position, RobotType p_robot_type);
	void update() override;

	void reset_robot() override;

	// returns true if the targeted tile is free to move on
	bool check_collision(const Tile& p_target_tile);

	Point2D get_target_position(BuggerDirections p_direction);

	// returns true if the bugger is on its current starting position
	bool check_for_starting_position(Point2D p_target_point);

	void set_m_current_wall(BuggerDirections p_current_wall);
	BuggerDirections get_m_current_wall() const;

	void set_m_ai_state(BuggerStates p_state);
	BuggerStates get_m_ai_state() const;

	void set_starting_position(Point2D p_position);

private:
	BuggerDirections m_current_wall = BuggerDirections::NORTH;
	BuggerStates m_ai_state = BuggerStates::FOLLOW_WALL;

	Point2D m_start_position;
};

#endif