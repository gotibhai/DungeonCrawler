#ifndef __CELLTYPE_H__
#define __CELLTYPE_H__

enum CellType {
<<<<<<< HEAD
	Empty,
	BorderHorizontal,
	BorderVertical,
	Ground,
	BridgeEnter,
	Bridge,
	Gold,
	Human,
	Dwarf,
	Elf ,
	Orc,
	Hafling,
	Merchant,
	Dragon,
	Player,
	Drow,
	Vampire,
	Shade,
	Troll,
	Goblin,
	Stairs
=======
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
	Goblin = (int)'g'
>>>>>>> b19a240eb0a226690fe10142c1464ffa87df0bf2
};

#endif

