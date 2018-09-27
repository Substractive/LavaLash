//
//  Enemy.cpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#include "Enemy.h"


	Enemy::Enemy(const LoaderParams* params) : SdlGameObject(params) {
		this->load();
	}
	void Enemy::load() {
		SdlGameObject::load();
	}

	void Enemy::draw() {
		SdlGameObject::draw(); // we now use SDLGameObject
	}
	void Enemy::clean() {
		SdlGameObject::clean();
	}
	void Enemy::update() {
		SdlGameObject::update();
		_position.setX(_position.getX() + 1);
		_position.setY(_position.getY() + 1);
		currentFrame = 1; //int((SDL_GetTicks() / 100) % 3);
	}

