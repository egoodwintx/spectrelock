//---------------------------------------------------------
// file: main.cpp
// project: SpectreLock
// author: Ed Goodwin
// date: 08.10.2024
// description:
//  program entrypoint
//---------------------------------------------------------
#include <iostream>
#include "game.h"

int main() {
    // init game engine
    Game game = Game();

    while (game.running()) {
        //Update
        game.update();
        //Render
        game.render();        
        // draw your game
        game.display();
            
    }
    // end of game
    return 0;
}
