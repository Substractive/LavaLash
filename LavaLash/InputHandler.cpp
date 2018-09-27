#include "InputHandler.h"


InputHandler* InputHandler::_instance = nullptr;
InputHandler::InputHandler()
{
	std::cout << "Input handler constr" << std::endl;
	for (int i = 0; i < 3; i++) {
		_mouseButtonStates.push_back(false);
	}
	_mousePosition = new Vector2D(0, 0);
}
bool InputHandler::getMouseButtonState(int buttonNumber) {
	return _mouseButtonStates[buttonNumber];
}

void InputHandler::clean() {

}

Vector2D* InputHandler::getMousePosition() {
	return _mousePosition;
}

bool InputHandler::isKeyDown(SDL_Scancode key) {

	if (_keystate != 0) {
		if (_keystate[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
void InputHandler::onMouseButtonDown(SDL_Event& event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		std::cout << "CLICK" << std::endl;
		std::cout << _mouseButtonStates[0] << std::endl;
		/*	if (_mouseButtonStates.empty()) {
		std::cout << "PRAZAN" << std::endl;
		}*/
		//_mouseButtonStates[LEFT] = true;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE) {
		std::cout << "CLICK" << std::endl;
		_mouseButtonStates[MIDDLE] = true;
	}

	if (event.button.button == SDL_BUTTON_RIGHT) {
		std::cout << "CLICK" << std::endl;
		_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		_mouseButtonStates[LEFT] = false;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE) {
		_mouseButtonStates[MIDDLE] = false;
	}

	if (event.button.button == SDL_BUTTON_RIGHT) {
		_mouseButtonStates[RIGHT] = false;
	}
}

void InputHandler::onMouseMove(SDL_Event& event) {
	_mousePosition->setX(event.motion.x);
	_mousePosition->setY(event.motion.y);
}

void InputHandler::onKeyDown() {
	std::cout << "KEY DOWN" << std::endl;
	_keystate = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp() {
	//_keystate = SDL_GetKeyboardState();
}
void InputHandler::update(SDL_Event &event) {
	
	std::cout << "Input handler check event" << std::endl;

	switch (event.type) {
	case SDL_MOUSEMOTION:
		onMouseMove(event);
		break;
	case SDL_MOUSEBUTTONDOWN:
		onMouseButtonDown(event);
		break;
	case SDL_MOUSEBUTTONUP:
		onMouseButtonUp(event);
		break;
	case SDL_KEYDOWN:
		onKeyDown();
		break;
	/*case SDL_KEYUP:
		onKeyUp();
		break;*/
	default:
		break;
	}
}
