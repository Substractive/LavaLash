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

void InputHandler::update(SDL_Event &event) {
	std::cout << "Input handler check event" << std::endl;
	if (event.type == SDL_MOUSEBUTTONDOWN) {
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

	if (event.type == SDL_MOUSEBUTTONUP) {
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

	if (event.type == SDL_MOUSEMOTION) {
		_mousePosition->setX(event.motion.x);
		_mousePosition->setY(event.motion.y);

	}
}
