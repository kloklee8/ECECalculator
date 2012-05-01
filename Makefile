CXX := g++
CXX_FLAGS := -Wall -g -std=c++0x -o
SRCS := main.cpp ExpressionParser.cpp SciCalcParser.cpp EquivComponentParser.cpp Help.cpp Divider.cpp PrefixConverter.cpp Menus.cpp
OBJS := $(SRCS:.cpp=.o)

all: ECECalculator

ECECalculator: ${OBJS}
	${CXX} ${CXX_FLAGS} $@ ${OBJS}

clean:
	-rm *.o *.d *~
