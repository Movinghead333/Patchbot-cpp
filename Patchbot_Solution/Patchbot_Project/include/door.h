#ifndef __DOOR_H_DEFINED__
#define __DOOR_H_DEFINED__

struct Door
{
	int m_x;
	int m_y;
	int m_open_timer;

	Door(int p_x, int p_y) :
		m_x(p_x),
		m_y(p_y),
		m_open_timer(0)
	{
	};
};

#endif