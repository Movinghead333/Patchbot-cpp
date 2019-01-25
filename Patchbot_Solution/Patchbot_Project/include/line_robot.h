#ifndef __LINE_ROBOT_H_DEFINED__
#define __LINE_ROBOT_H_DEFINED__

#include "robot.h"
#include "line_robot_state.h"

class Colony;

class LineRobot : public Robot
{
public:
	using Robot::Robot;
	void update(Colony& p_colony) override;

	void reset_robot() override;

	// returns true if the robot collides with a wall
	bool check_collision(Tile& p_target_tile) override;

private:
	LineRobotState m_ai_state = LineRobotState::X_MOVEMENT;

	void update_x_movement(Colony& p_colony);
	void update_y_movement(Colony& p_colony);
};

#endif
