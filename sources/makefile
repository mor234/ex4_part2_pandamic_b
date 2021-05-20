#!make -f

CXX=clang++-9 
CXXVERSION=c++2a
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-*
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=Board.cpp Player.cpp OperationsExpert.cpp Dispatcher.cpp Scientist.cpp Researcher.cpp Medic.cpp Virologist.cpp GeneSplicer.cpp FieldDoctor.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))


run: main 
	./main

main: Main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main


tidy:
	clang-tidy $(SOURCES) $(TIDY_FLAGS) --

valgrind: main
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }


%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o main
