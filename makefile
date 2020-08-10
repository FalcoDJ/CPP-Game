# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall #-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

# the build target executable:
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).cpp Player.cpp SpriteAnimator.cpp TextureHolder.cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp Player.cpp SpriteAnimator.cpp TextureHolder.cpp

clean:
	$(RM) $(TARGET)
