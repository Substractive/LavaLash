//
//  TextureManager.cpp
//  LavaLash
//
//  Created by Dino Budic on 15/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#include "TextureManager.h"
//amespace GraphicCore {
	TextureManager* TextureManager::_instance = 0;
	TextureManager* TextureManager::Instance() {

		if (_instance == nullptr) {
			_instance = new TextureManager();
			return _instance;
		}
		return _instance;

	}

	bool TextureManager::load(std::string fileName, std::string id) {
		SDL_Surface *tempSurface = IMG_Load(fileName.c_str());
		if (tempSurface == nullptr)
			return false;

		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);

		if (texture != nullptr) {
			textureMap[id] = texture;
			return true;
		}

		return false;
	}

	void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip) {

		SDL_Rect srcRect;
		SDL_Rect destRect;

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;
		destRect.x = x;
		destRect.y = y;

		SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);

	}
	void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip) {
		SDL_Rect srcRect;
		SDL_Rect destRect;
		srcRect.x = width * currentFrame;
		srcRect.y = height * (currentRow - 1);
		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;
		destRect.x = x;
		destRect.y = y;

		SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
	}

	void TextureManager::setRenderer(SDL_Renderer* renderer) {
		this->renderer = renderer;
	}

//}
