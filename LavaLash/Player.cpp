//
//  Player.cpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright � 2018 Dino Budic. All rights reserved.
//

#include "Player.h"
//namespace Player {
	Player::Player(const LoaderParams* params) : SdlGameObject(params) {
		this->load();
	}

	void Player::load() {
		SdlGameObject::load();
	}

	void Player::draw() {
		SdlGameObject::draw(); // we now use SDLGameObject
	}
	void Player::update() {
	
		currentFrame = int((SDL_GetTicks() / 100) % 3);
		//_position.setX(_position.getX() - 1);
		_acceleration.setX(1);
		//_velocity.setX(1);
		SdlGameObject::update();
	}
	void Player::clean() {
		SdlGameObject::clean();
	}
//}
