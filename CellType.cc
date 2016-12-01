#ifndef __CELLTYPE_H__
#define __CELLTYPE_H__

enum CellType {
	Empty = (int)' ',
	BorderHorizontal = (int)'-',
	BorderVertical = (int)'|',
	Ground = (int)'.',
	BridgeEnter = (int)'+',
	Bridge = (int)'X',
	Gold = (int)'G',
	Human = (int)'H',
	Dwarf = (int)'W',
	Elf  = (int)'E',
	Orc = (int)'O',
	Hafling = (int)'L',
	Merchant = (int)'M',
	Dragon = (int)'D',
	Player = (int)'@',
	Potion = (int)'P',
	Drow = (int)'d',
	Vampire = (int)'v',
	Shade = (int)'s',
	Troll = (int)'t',
	Goblin = (int)'g',
	Stairs = (int)'/'
};

#endif

