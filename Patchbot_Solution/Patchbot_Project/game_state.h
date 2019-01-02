#ifndef __GAME_STATE_H_DEFINED__
#define __GAME_STATE_H_DEFINED__

enum GameState
{
	GAME_NOT_STARTED = 0,
	IN_PROGRESS,
	PROGRAM_ENDED,
	FELL_INTO_ABYSS,
	FELL_INTO_WATER,
	SERVER_REACHED
};

#endif