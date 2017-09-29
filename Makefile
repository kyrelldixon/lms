# Makefile for Library Management System
CXXFLAGS += --std=c++11

all: div main
rebuild: div clean main

debug: CXXFLAGS += -g
debug: rebuild

main: main.o controller.o view.o library.o publication.o patron.o
	$(CXX) $(CXXFLAGS) -o lms main.o controller.o view.o library.o publication.o patron.o
main.o: main.cpp controller.h library.h
	$(CXX) $(CXXFLAGS) -c main.cpp
controller.o: controller.cpp controller.h library.h view.h publication.h patron.h genre.h media.h age.h
	$(CXX) $(CXXFLAGS) -c controller.cpp
test_view: test_view.o controller.o view.o library.o publication.o patron.o
	$(CXX) $(CXXFLAGS) -o test_view test_view.o controller.o view.o library.o publication.o patron.o
test_view.o: test_view.cpp view.h patron.h publication.h library.h
	$(CXX) $(CXXFLAGS) -c test_view.cpp
test_library: test_library.o library.o patron.o publication.o view.o
	$(CXX) $(CXXFLAGS) -o test_library test_library.cpp library.o patron.o publication.o
test_library.o: test_library.cpp patron.h publication.h library.h
	$(CXX) $(CXXFLAGS) -c test_library.cpp
library.o: library.cpp library.h patron.h publication.h
	$(CXX) $(CXXFLAGS) -c library.cpp
test_publication: test_publication.o publication.o patron.o
	$(CXX) $(CXXFLAGS) -o test_publication test_publication.o publication.o patron.o
test_publication.o: test_publication.cpp publication.h patron.h media.h age.h genre.h 
	$(CXX) $(CXXFLAGS) -c -w test_publication.cpp
publication.o: publication.cpp publication.h patron.h media.h age.h genre.h 
	$(CXX) $(CXXFLAGS) -c publication.cpp
test_patron: test_patron.o patron.o patron.h
	$(CXX) $(CXXFLAGS) -o test_patron test_patron.o patron.o
test_patron.o: test_patron.cpp patron.h
	$(CXX) $(CXXFLAGS) -c -w test_patron.cpp
patron.o: patron.cpp patron.h 
	$(CXX) $(CXXFLAGS) -c -w patron.cpp
clean:
	-rm -f *.o lms test_age test_genre test_media test_publication test_patron test_library test_view test_view_actual.txt
div:
	@echo
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo
