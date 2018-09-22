//
//  main.cpp
//  LavaLash
//
//  Created by Dino Budic on 13/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//
#define SDL_MAIN_HANDLED
#pragma comment(lib, "SDL2main.lib")
#include <iostream>

#include "SDL.h"
#include "SDL_main.h"
#include "Engine.h"

Engine *engine = nullptr;

int main(int argc,  char * argv[]) {
	// insert code here...

	SDL_SetMainReady();
	 Engine::Instance()->init("LavaLash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, false);
	
	while (Engine::Instance()->running()) {
		Engine::Instance()->handleEvents();
		Engine::Instance()->update();
		Engine::Instance()->render();
		SDL_Delay(10);
	}
	Engine::Instance()->clean();
	return 0;



}
