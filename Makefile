CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

# Add new .cpp files here as they are created
SRCS = main.cpp 
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