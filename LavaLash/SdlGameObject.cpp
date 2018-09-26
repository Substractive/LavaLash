//
//  SDLGameObject.cpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#include "SdlGameObject.h"
//namespace EngineGameObject{

SdlGameObject::SdlGameObject(const LoaderParams* pParams) : _position(pParams->getX(),pParams->getY()),_velocity(0,0)
{
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
		
		TextureManager::Instance()->drawFrame(textureID, _position.getX(), _position.getY(),
		width, height, currentRow, currentFrame);
}

void SdlGameObject::update() {
	_position += _velocity;
}

void SdlGameObject::clean() {

}

//}






