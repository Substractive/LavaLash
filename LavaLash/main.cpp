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
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
int main(int argc,  char * argv[]) {
	// insert code here...
	Uint32 frameStart, frameTime;
	SDL_SetMainReady();
	 Engine::Instance()->init("LavaLash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, false);
	
	while (Engine::Instance()->running()) {
		frameStart = SDL_GetTicks();

		Engine::Instance()->handleEvents();
		Engine::Instance()->update();
		Engine::Instance()->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME - frameStart));
		}
	}
	Engine::Instance()->clean();
	return 0;



}
