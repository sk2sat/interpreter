TARGET	= interpreter
OBJS	= main.o

CXX	= clang++
CXXFLAGS= -std=c++1z

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

default:
	make $(TARGET)

run: $(TARGET)
	./$<

clean:
	rm -f *.o $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)
