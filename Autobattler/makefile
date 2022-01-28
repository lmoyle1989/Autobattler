#Lucas Moyle
#11/24/2019
#CS162 Fall 2019
#Makefile for Project 4 - Team Fantasy Combat Simulator

output: MainTour.o Menu.o ClassBattle.o StructCharCont.o ClassCharList.o ClassCharacter.o ClassBarb.o ClassVamp.o ClassMedusa.o ClassBlue.o ClassHarry.o
	g++ -std=c++0x MainTour.o Menu.o ClassBattle.o StructCharCont.o ClassCharList.o ClassCharacter.o ClassBarb.o ClassVamp.o ClassMedusa.o ClassBlue.o ClassHarry.o -o main

MainTour.o: MainTour.cpp
	g++ -c -std=c++0x MainTour.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c -std=c++0x Menu.cpp

ClassBattle.o: ClassBattle.cpp ClassBattle.hpp
	g++ -c -std=c++0x ClassBattle.cpp

StructCharCont.o: StructCharCont.cpp StructCharCont.hpp
	g++ -c -std=c++0x StructCharCont.cpp

ClassCharList.o: ClassCharList.cpp ClassCharList.hpp
	g++ -c -std=c++0x ClassCharList.cpp

ClassCharacter.o: ClassCharacter.cpp ClassCharacter.hpp
	g++ -c -std=c++0x ClassCharacter.cpp

ClassBarb.o: ClassBarb.cpp ClassBarb.hpp
	g++ -c -std=c++0x ClassBarb.cpp

ClassVamp.o: ClassVamp.cpp ClassVamp.hpp
	g++ -c -std=c++0x ClassVamp.cpp

ClassMedusa.o: ClassMedusa.cpp ClassMedusa.hpp
	g++ -c -std=c++0x ClassMedusa.cpp

ClassBlue.o: ClassBlue.cpp ClassBlue.hpp
	g++ -c -std=c++0x ClassBlue.cpp

ClassHarry.o: ClassHarry.cpp ClassHarry.hpp
	g++ -c -std=c++0x ClassHarry.cpp

clean:
	rm *.o main

