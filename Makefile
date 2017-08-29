CC = g++ -std=c++11
INCLUDE_PATH = -Iinclude
SRC_PATH = src/
OBJ_PATH = obj/
LINKER_OPTIONS = -lmingw32 -lSDL2main -lSDL2
OBJS = main.o obj/Agent.o obj/Fish.o obj/Game.o obj/Input.o obj/Shark.o obj/Time.o obj/Vector2D.o

all: main

main: $(OBJS)
	$(CC) -o  %@ $(OBJS) $(LINKER_OPTIONS)

main.o: main.cpp
	$(CC) $(INCLUDE_PATH) -c $< -o $(OBJ_PATH)$@

obj/Agent.o: Agent.cpp Agent.h
	$(CC) $(INCLUDE_PATH) -c $(SRC_PATH)$< -o $(OBJ_PATH)$@

obj/Fish.o: Fish.cpp Fish.h
	$(CC) $(INCLUDE_PATH) -c $(SRC_PATH)$< -o $(OBJ_PATH)$@

obj/Game.o: Game.cpp Game.h
	$(CC) $(INCLUDE_PATH) -c $(SRC_PATH)$< -o $(OBJ_PATH)$@

obj/Input.o: Input.cpp Input.h
	$(CC) $(INCLUDE_PATH) -c $(SRC_PATH)$< -o $(OBJ_PATH)$@

obj/Shark.o: Shark.cpp Shark.h
	$(CC) $(INCLUDE_PATH) -c $(SRC_PATH)$< -o $(OBJ_PATH)$@

obj/Time.o: Time.cpp Time.h
	$(CC) $(INCLUDE_PATH) -c $(SRC_PATH)$< -o $(OBJ_PATH)$@

obj/Vector2D.o: Vector2D.cpp Vector2D.h
	$(CC) $(INCLUDE_PATH) -c $(SRC_PATH)$< -o $(OBJ_PATH)$@