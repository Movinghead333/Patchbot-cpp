#ifndef __LINE_ROBOT_H_DEFINED__
#define __LINE_ROBOT_H_DEFINED__

#include "robot.h"

class LineRobot : public Robot
{
	using Robot::Robot;
	void update() override;
};

#endif
