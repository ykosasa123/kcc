CXX=g++
CPPFLAGS=-Wall -std=c++17 -I./
SRCS=$(wildcard *.cpp)
HEADER=$(wildcard *.hpp)
OBJS=$(SRCS:.cpp=.o)

kcc: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CPPFLAGS)

%.o: %.cpp $(HEADER)
	$(CXX) -c $(CPPFLAGS) $<

clean:
	rm -f *.o kcc

format: 
	clang-format -i *.cpp *.hpp

.PHONY: test clean format
