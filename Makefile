CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a4q4
OBJECTS = main.o Grid.o Cell.o Direction.o PotionType.o CellType.o Potion.o Character.o Race.o Shade.o Drow.o Vampire.o Troll.o Goblin.o Game.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
