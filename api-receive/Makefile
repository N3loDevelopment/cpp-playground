CXX = g++
CXXFLAGS = -lstdc++ -lws2_32
TARGET = main.exe
SOURCES = main.cpp receiver.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) -o $(TARGET) $(SOURCES) $(CXXFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
