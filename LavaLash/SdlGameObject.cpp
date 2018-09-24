//
//  SDLGameObject.cpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#include "SdlGameObject.h"
//namespace EngineGameObject{

SdlGameObject::SdlGameObject(const LoaderParams* pParams)
{

	x = pParams->getX();
	y = pParams->getY();
	width = pParams->getWidth();
	height = pParams->getHeight();
	textureID = pParams->getTextureID();
	currentRow = 1;
	currentFrame = 1;
	texturePath = pParams->getTexturePath();
}
void SdlGameObject::load() {

	std::cout << "SDL GAME OBJECT LOAD" << std::endl;
	if (TextureManager::Instance()->load(texturePath, textureID)) {
		std::cout << "error loading img" << SDL_GetError() << std::endl;
	}
}

void SdlGameObject::draw()
{
		
		TextureManager::Instance()->drawFrame(textureID, x, y,
		width, height, currentRow, currentFrame);
}

void SdlGameObject::update() {

}

void SdlGameObject::clean() {

}

//}






