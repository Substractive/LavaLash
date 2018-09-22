//
//  GameObject.hpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h

#include <stdio.h>
#include <iostream>
class TextureManager;
//namespace EngineGameObject {
	class GameObject {
	public:
		virtual void load() = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;

	protected:
		GameObject();
		virtual ~GameObject() {}
	};
//}
#endif /* GameObject_hpp */
