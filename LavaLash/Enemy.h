//
//  Enemy.hpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#include <stdio.h>
#include <iostream>
#include "SdlGameObject.h"
#include "LoaderParams.h"
//namespace AIEnemy {
	class Enemy : public SdlGameObject {
	public:
		Enemy(const LoaderParams* params);
		//   void load(int x, int y, int width, int height, std::string textureID);
		void load();
		void draw();
		void update();
		void clean();
	};
//}

#endif /* Enemy_hpp */
