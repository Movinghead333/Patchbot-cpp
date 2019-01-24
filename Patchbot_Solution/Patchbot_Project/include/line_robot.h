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

private:
	LineRobotState m_ai_state = LineRobotState::X_MOVEMENT;
};

#endif
