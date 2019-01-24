#include "line_robot.h"
#include "colony.h"

void LineRobot::update(Colony& p_colony)
{
	std::cout << "line robot updated!" << std::endl;
}

void LineRobot::reset_robot()
{
	m_ai_state = LineRobotState::X_MOVEMENT;
}
