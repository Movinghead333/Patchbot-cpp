#ifndef __PATHFINDER_ROBOT_H_DEFINED__
#define __PATHFINDER_ROBOT_H_DEFINED__

#include "robot.h"
#include "pathfinder_state.h"
#include "point.h"

class Colony;

class PathfinderRobot : public Robot
{
public:
	using Robot::Robot;

	// takes care of updating a pathfinding robot for one timestep
	void update(Colony& p_colony) override;

	// returns true if the tile would mean collision also takes care of 
	// slowing tiletypes and opening doors
	bool check_collision(Tile& p_target_tile) override;



private: // member variables
	PathfinderState m_ai_state = PathfinderState::WAITING;

	// default value should never be used and thus can be (-1, -1)
	Point2D m_patchbot_pos = Point2D(-1, -1);
	

private: // member methods

	// update methods for every AI state
	void check_waiting(Colony& p_colony);
	void check_following(Colony& p_colony);
	void check_hunting(Colony& p_colony);

	// returns true if the given tile could block line of sight
	bool is_line_of_sight_obstacle(const Tile& p_tile) const;

	// checks if a robot has line of sight towards patchbot
	bool check_line_of_sight(Colony& p_colony);

	// default move operation in order to move a robot on the bets path
	// towards patchbot
	void move_on_best_path(Colony& p_colony);

	// moves a HUNTER robot to location where he had last seen patchbot
	void move_to_last_known_location(Colony& p_colony);

	// checks wether a robot can reach patchbot
	bool check_reachable(Colony& p_colony);
};

#endif