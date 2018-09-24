//
//  Engine.cpp
//  LavaLash
//
//  Created by Dino Budic on 13/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#include "Engine.h"
//namespace Core {
	Engine* Engine::instance = nullptr;

	bool Engine::init(const char *title, int posx, int posy, int width, int height, bool fullscreen) {
		int flags = 0;
		if (fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
			IMG_Init(IMG_INIT_PNG);
			m_pWindow = SDL_CreateWindow(title, posx, posy, width, height, flags);
			if (m_pWindow != nullptr) {
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
				TextureManager::Instance()->setRenderer(m_pRenderer);

				if (m_pRenderer != nullptr) {
					SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}


		


		m_bRunning = true;
		return true;
	}

	void Engine::spawnObjects() {
	
		gameObjects.push_back(new Player(new LoaderParams(50, 60, 50, 60, "./assets/dark_soldier-hornless.png", "image")));
		gameObjects.push_back(new Enemy(new LoaderParams(100, 120, 50, 60, "./assets/dark_soldier-hornless.png", "image1")));
	}

	void Engine::render() {
		SDL_RenderClear(m_pRenderer); // Clear the draw color

		if(!gameObjects.empty())
			for (std::vector<SdlGameObject*>::size_type i = 0; i != gameObjects.size(); i++) {
				gameObjects[i]->draw();
			}

		SDL_RenderPresent(m_pRenderer); // Draw to the screen
	}

	void Engine::clean() {
		SDL_DestroyWindow(m_pWindow); // fixed this
		SDL_DestroyRenderer(m_pRenderer);
		IMG_Quit();
		SDL_Quit();
	}

	void Engine::handleEvents() {
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				m_bRunning = false;
				break;

			default:
				break;
			}
		}
	}

	void Engine::update() {
		if (!gameObjects.empty())
			for (std::vector<SdlGameObject*>::size_type i = 0; i != gameObjects.size(); i++) {
				gameObjects[i]->update();
			}
	}

	bool Engine::running() {
		return m_bRunning;
	}
//}

