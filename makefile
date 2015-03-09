CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJECT = configuration.o functions.o main.o

SOURCE = configuration.cpp functions.cpp main.cpp

HEADER = configuration.h functions.h

EXECUTABLE = main

all: ${EXECUTABLE}

${EXECUTABLE} : ${OBJECT} ${HEADER}
		${CXX} ${LDFLAGS} ${OBJECT} -o ${EXECUTABLE}

${OBJECT}: ${SOURCE}
		${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
		rm -rf *.o ${EXECUTABLE}
