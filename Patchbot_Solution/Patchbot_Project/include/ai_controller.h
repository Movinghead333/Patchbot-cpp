#ifndef __AI_CONTROLLER_H_DEFINED__
#define __AI_CONTROLLER_H_DEFINED__

#include "colony.h"
#include "utility.h"

class AIController
{
public:
	AIController();
	void update_ai(std::shared_ptr<Robot>& p_robot);

	void set_colony_ptr(std::shared_ptr<Colony> p_colony);

	bool is_setup();

private:
	std::shared_ptr<Colony> m_colony;

	// bugger
	void update_bugger(std::shared_ptr<Robot>& p_robot);
	void check_find_another_wall(Bugger& p_bugger);
	void check_follow_wall(Bugger& p_bugger);
	void check_wait(Bugger& p_bugger);
};

#endif
