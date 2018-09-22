//
//  Engine.hpp
//  LavaLash
//
//  Created by Dino Budic on 13/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#ifndef Engine_h
#define Engine_h

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "TextureManager.h"
//#include "GameObject.h"
//#include "SdlGameObject.h"
#include "Player.h"
#include "Enemy.h"

//namespace Core {
	
	
	

class SdlGameObject;

	
	class Engine {
	
	public:
		static Engine* Instance() {
			if (instance == nullptr) {
				instance = new Engine();
				return instance;
			}
			return instance;
		}
		bool init(const char* title, int posx, int posy, int width, int height, bool fullscreen);
		void render();
		void update();
		void handleEvents();
		void clean();
		bool running();
		SDL_Renderer* getRenderer() const { return m_pRenderer; }


	private:
		static Engine* instance;
		Engine() {}
		~Engine() {}
		bool m_bRunning;
		SDL_Window *m_pWindow;
		SDL_Renderer *m_pRenderer;
		TextureManager *textureManager;
		int currentFrame;
		SdlGameObject* gObj;
		 //Player::Player* player;
		 Player* player;
		std::vector<SdlGameObject*> gameObjects;
	};

//}

#endif /* Engine_h */
