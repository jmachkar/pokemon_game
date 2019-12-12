GCC = g++ -g -std=c++11

OBJS = point2d.o vector2d.o gameobject.o main.o building.o pokemoncenter.o pokemongym.o pokemon.o model.o gamecommand.o view.o battlearena.o rival.o

default:main

main: $(OBJS)
			$(GCC) -o main $(OBJS)

point2d.o: point2d.cpp point2d.h
		$(GCC) -c point2d.cpp -o point2d.o

vector2d.o: vector2d.cpp vector2d.h
		$(GCC) -c vector2d.cpp -o vector2d.o

gameobject.o: gameobject.cpp gameobject.h
		$(GCC) -c gameobject.cpp -o gameobject.o

building.o: building.cpp building.h
		$(GCC) -c building.cpp -o building.o

pokemoncenter.o: pokemoncenter.cpp pokemoncenter.h
		$(GCC) -c pokemoncenter.cpp -o pokemoncenter.o

pokemongym.o: pokemongym.cpp pokemongym.h
		$(GCC) -c pokemongym.cpp -o pokemongym.o

main.o: main.cpp point2d.h vector2d.h gameobject.h building.h pokemoncenter.h pokemongym.h pokemon.h model.h gamecommand.h view.h battlearena.h rival.h input_handling.h
		$(GCC) -c main.cpp -o main.o

pokemon.o: pokemon.cpp pokemon.h
		$(GCC) -c pokemon.cpp -o pokemon.o

model.o: model.cpp model.h
		$(GCC) -c model.cpp -o model.o

gamecommand.o: gamecommand.cpp gamecommand.h
		$(GCC) -c gamecommand.cpp -o gamecommand.o

view.o: view.cpp view.h
		$(GCC) -c view.cpp -o view.o

rival.o: rival.cpp rival.h
		$(GCC) -c rival.cpp -o rival.o

battlearena.o: battlearena.cpp battlearena.h
		$(GCC) -c battlearena.cpp -o battlearena.o
clean: 
		rm $(OBJS) main
