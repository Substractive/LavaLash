//
//  TextureManager.hpp
//  LavaLash
//
//  Created by Dino Budic on 15/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#ifndef TextureManager_h
#define TextureManager_h
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <map>

/*
# Manages loading,drawing and holding list of textures
*/
//namespace GraphicCore {
	class TextureManager {
	public:
		static TextureManager* Instance();
		bool load(std::string fileName, std::string id);
		void draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void setRenderer(SDL_Renderer* renderer);
	private:
		static TextureManager* _instance;
		TextureManager() {}
		~TextureManager() {}
		std::map<std::string, SDL_Texture*> textureMap;
		SDL_Renderer* renderer;


	};
//}
#endif /* TextureManager_hpp */
