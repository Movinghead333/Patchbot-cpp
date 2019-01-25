#include "pathfinder_robot.h"
#include "colony.h"

void PathfinderRobot::update(Colony& p_colony)
{

	std::cout << "pathfinder robot updated!" << std::endl;
}

bool PathfinderRobot::check_collision(Tile & p_target_tile)
{
	return false;
}
