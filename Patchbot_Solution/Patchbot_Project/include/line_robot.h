#ifndef __LINE_ROBOT_H_DEFINED__
#define __LINE_ROBOT_H_DEFINED__

#include "robot.h"
#include "line_robot_state.h"

class Colony;

class LineRobot : public Robot
{
public:
	using Robot::Robot;

	// overrides update from robot which gets called when ever an AI should
	// make a step
	void update(Colony& p_colony) override;

	// calls reset from robot and also resets AI specific variables
	void reset_robot() override;

	// return true if the target_tile's tiletype causes collision 
	// also takes care of opening doors and slow downs from certain tiletypes
	bool check_collision(Tile& p_target_tile) override;

private:
	//n stores the current AI state of the robot
	LineRobotState m_ai_state = LineRobotState::X_MOVEMENT;

	// updates the robot if he is currently moving in x direction
	void update_x_movement(Colony& p_colony);

	// updates the robot if he is currently moving in y direction
	void update_y_movement(Colony& p_colony);
};

#endif
