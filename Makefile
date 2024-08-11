all:
	g++ -o ./bin/spectrelock ./src/game.cpp ./src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

clean:
	rm -r ./bin/*

