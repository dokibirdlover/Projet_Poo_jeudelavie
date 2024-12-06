CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp Game.cpp Grid.cpp GameFile.cpp Cell.cpp 
OBJS = $(SRCS:.cpp=.o)

all: main

main: $(OBJS)
	$(CXX) $(OBJS) -o main $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main
