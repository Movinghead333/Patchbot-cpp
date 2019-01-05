#ifndef __PATCHBOT_MOVE_H_DEFINED__
#define __PATCHBOT_MOVE_H_DEFINED__

#include "move_type.h"

struct PatchbotMove
{
	int m_steps;
	MoveType m_move_type;

	PatchbotMove(int p_steps, MoveType p_move_type);

	PatchbotMove();
};

#endif