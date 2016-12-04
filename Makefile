CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = crawler
OBJECTS = main.o Grid.o Cell.o Direction.o PotionType.o CellType.o Potion.o Character.o Enemy.o Race.o Shade.o Drow.o Vampire.o Troll.o Goblin.o Game.o Gold.o Stairs.o ActionItem.o PotionCell.o CellFactory.o Elf.o Dwarf.o Dragon.o Merchant.o Human.o Halfling.o Orc.o Action.o Logger.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
