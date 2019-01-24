#ifndef __ROBOT_H_DEFINED__
#define __ROBOT_H_DEFINED__

#include <iostream> //DEBUG

#include "robot_type.h"
#include "point.h"
#include "tile.h"

// A base-class for all robots holding the core functionalities
// like position and robot-type
class Robot
{
public:

	// constructor
	Robot(Point2D p_position, RobotType pRobotType);

	virtual void update();

	// TODO change to = 0 since robot should eventually be an interface
	virtual bool check_collision(Tile& p_target_tile);

	void update_visible_time();
	void setup_visible_time();

	// getter methods for member-fields
	bool get_visibility() const;

	void set_x_coordinate(int p_x);
	int get_x_coordinate() const;

	void set_y_coordinate(int p_y);
	int get_y_coordinate() const;

	RobotType get_robot_type() const;

	void update_position(Point2D p_new_position);
	Point2D get_position() const;

	virtual void reset_robot();

	void set_m_blocked(bool p_blocked);
	bool get_m_blocked() const;


protected:

	// A robot's coordinates starting from (0, 0)
	// representing the tile in top left corner
	Point2D m_position;

	// backup coordinates for reset
	const Point2D m_position_backup;

	// A robot's type for later runtime-comparisons
	RobotType m_robot_type;

	const RobotType m_back_up_robot_type;

	// indicates how long the robot gravestone remains on the map after a robot
	// crashed default value is -1 and means the robot is still alive
	int time_visible = -1;

	//TODO
	// blocked flag for patchbot might be outsourced into controller later
	bool m_blocked = false;
};

#endif
