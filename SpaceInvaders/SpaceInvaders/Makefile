CC := g++
INC := -I./include
SDL := -lSDL2 -lSDL2_image
GL := -lGL -lGLU
LIBS := $(GL) $(SDL)
CFLAGS := -Wall -g -std=gnu++11 -Wold-style-cast -Wunused-parameter $(INC)
TARGET := space_invaders
# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJDIR := obj/
OBJS := $(patsubst %.cpp,$(OBJDIR)%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^  $(LIBS)
$(OBJDIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(TARGET) $(OBJDIR)

.PHONY: all cleantest
