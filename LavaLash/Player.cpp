//
//  Player.cpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
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
	
		currentFrame = 1;//int((SDL_GetTicks() / 100) % 3);
		_velocity.setX(0);
		_velocity.setY(0);
		handleInput();
		
		SdlGameObject::update();
	}
	void Player::clean() {
		SdlGameObject::clean();
	}

	void Player::handleInput() {
		
		std::cout << "Player handle input" << std::endl;
		std::cout << TheInputHandler::Instance()->getMousePosition() << std::endl;

		// FOLLOW MOUSE
		//Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
		//_velocity = (*vec - _position) / 100;
		// END FOLLOW MOUSE

		// KEYBOARD MOVEMENT
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
			_velocity.setX(2);
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
			_velocity.setX(-2);
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
			_velocity.setY(-2);
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
			_velocity.setY(2);
		}
		// END KEYBOARD MOVEMENT


		/*if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			_velocity.setX(1);
		}*/
	}
//}
