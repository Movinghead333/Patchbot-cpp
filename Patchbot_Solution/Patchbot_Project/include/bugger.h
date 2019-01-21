#ifndef __BUGGER_H_DEFINED__
#define __BUGGER_H_DEFINED__

#include "robot.h"

class Bugger : public Robot
{
	using Robot::Robot;
	void update() override;
};

#endif