//
//  Player.hpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <iostream>
#include <SDL.h>

#include "SdlGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"


;
//namespace Player {
	//
	class Player : public SdlGameObject { // Unknown class name
	public:
		Player(const LoaderParams* params);
		// void load(int x, int y, int width, int height, std::string textureID);
		void load();
		void draw();
		void update();
		void clean();
	private:
		void handleInput();
	};
//}


#endif /* Player_hpp */
