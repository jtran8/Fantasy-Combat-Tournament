tournament: main.o menu.o inputCheck.o Game.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Lineup.o Losers.o
	g++ -std=c++11 main.o menu.o inputCheck.o Game.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Lineup.o Losers.o -o tournament

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp
	g++ -std=c++11 -c menu.cpp

inputCheck.o: inputCheck.cpp
	g++ -std=c++11 -c inputCheck.cpp

Game.o: Game.cpp
	g++ -std=c++11 -c Game.cpp

Character.o: Character.cpp
	g++ -std=c++11 -c Character.cpp

Vampire.o: Vampire.cpp
	g++ -std=c++11 -c Vampire.cpp

Barbarian.o: Barbarian.cpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp
	g++ -std=c++11 -c BlueMen.cpp

Medusa.o: Medusa.cpp
	g++ -std=c++11 -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -std=c++11 -c HarryPotter.cpp

Lineup.o: Lineup.cpp
	g++ -std=c++11 -c Lineup.cpp

Losers.o: Losers.cpp
	g++ -std=c++11 -c Losers.cpp

clean:
	rm *.o tournament