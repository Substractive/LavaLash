#pragma once
#include "SDL.h"
#include <vector>
//#include "Engine.h"
#include <iostream>
#include "Vector2D.h"
enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};



class InputHandler
{
public:
	static InputHandler* Instance() {
		if (_instance == 0) {
			_instance = new InputHandler();
			
		}
		return _instance;
	}

	void update(SDL_Event &event);
	void clean();
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();
	bool isKeyDown(SDL_Scancode key);
private:
	static InputHandler* _instance;
	Vector2D * _mousePosition;
	InputHandler();
	~InputHandler() {}
	std::vector<bool> _mouseButtonStates;
	const Uint8* _keystate;
	// keyboard events
	void onKeyDown();
	void onKeyUp();
	// mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	
};

typedef InputHandler TheInputHandler;

