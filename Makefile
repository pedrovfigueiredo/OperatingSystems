SRC_DIR = Sources
OBJ_DIR = Objects
CPPFLAGS  = -Wall -std=c++11
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/algoritmo.cpp $(SRC_DIR)/processo.cpp $(SRC_DIR)/reader.cpp $(SRC_DIR)/fcfs.cpp $(SRC_DIR)/sjf.cpp $(SRC_DIR)/rr.cpp
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/algoritmo.o $(OBJ_DIR)/processo.o $(OBJ_DIR)/reader.o $(OBJ_DIR)/fcfs.o $(OBJ_DIR)/sjf.o $(OBJ_DIR)/rr.o

EXECUTABLE_NAME = escalonador


all: build exec

exec: $(OBJS)
	g++ $(CPPFLAGS) $(OBJS) -o $(EXECUTABLE_NAME)

build: $(OBJS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@


.PHONY: clean

clean:
	rm $(OBJS) $(EXECUTABLE_NAME)
