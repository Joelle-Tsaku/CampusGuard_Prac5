CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

# Automatically pick up all .cpp files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = campus_guard

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensures cleanly rebuilding the project
clean:
	rm -f $(OBJS) $(TARGET)

# Useful for local testing before Dockerizing
run: all
	./$(TARGET)

# Run with Valgrind to check for memory leaks
valgrind: all
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# Run with GDB for debugging
gdb: all
	gdb ./$(TARGET)