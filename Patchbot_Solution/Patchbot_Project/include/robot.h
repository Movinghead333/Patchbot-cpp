#ifndef __ROBOT_H_DEFINED__
#define __ROBOT_H_DEFINED__

#include <iostream> //DEBUG

#include "robot_type.h"
#include "point.h"

// A base-class for all robots holding the core functionalities
// like position and robot-type
class Robot
{
public:

	// constructor
	Robot(Point2D p_position, RobotType pRobotType);

	virtual void update();

	void update_visible_time();
	void setup_visible_time();

	// getter methods for member-fields
	bool get_visibility();

	void set_x_coordinate(int p_x);
	int get_x_coordinate() const;

	void set_y_coordinate(int p_y);
	int get_y_coordinate() const;

	void set_coordinates(Point2D p_position);

	RobotType get_robot_type() const;

	void update_position(int p_new_x, int p_new_y);

	virtual void reset_robot();

	void set_m_blocked(bool p_blocked);
	bool get_m_blocked() const;


protected:

	// A robot's coordinates starting from (0, 0)
	// representing the tile in top left corner
	int m_x_coordinate;
	int m_y_coordinate;

	// backup coordinates for reset
	Point2D m_position_backup;

	// A robot's type for later runtime-comparisons
	RobotType m_robot_type;

	RobotType m_back_up_robot_type;

	// indicates how long the robot gravestone remains on the map after a robot
	// crashed default value is -1 and means the robot is still alive
	int time_visible = -1;

	//TODO
	// blocked flag for patchbot might be outsourced into controller later
	bool m_blocked = false;
};

#endif
