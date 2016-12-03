#ifndef __ACTION_H__
#define __ACTION_H__

enum Action {
	ATTACK = (int) 'a',
	USE_POTION = (int) 'u',
	MOVE = (int) 'm',
	RESTART = (int) 'r',
	FREEZE = (int) 'f',
	QUIT = (int)'q',
	NONE = -1
};

#endif
