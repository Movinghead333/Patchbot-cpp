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
	Robot(
		int p_x_coordinate,
		int p_y_coordinate,
		RobotType pRobotType
	);

	virtual void update();

	// getter methods for member-fields
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
	int m_back_up_x;
	int m_back_up_y;

	// A robot's type for later runtime-comparisons
	const RobotType m_robot_type;

	bool m_blocked = false;
};

#endif
