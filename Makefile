CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a4q4
OBJECTS = main.o Grid.o Cell.o Direction.o CellType.o Potion.o Race.o Game.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
