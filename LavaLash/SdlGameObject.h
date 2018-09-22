//

//  SDLGameObject.hpp

//  LavaLash

//

//  Created by Dino Budic on 16/09/2018.

//  Copyright © 2018 Dino Budic. All rights reserved.

//



#ifndef SdlGameObject_h

#define SdlGameObject_h



#include <stdio.h>

#include "GameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
//namespace EngineGameObject {
	
		

class GameObject;
class SdlGameObject : public GameObject {

	

public:
	SdlGameObject(const LoaderParams* pParams);
	//SdlGameObject(const EngineGameObject::LoaderParams* pParams): EngineGameObject::GameObject(pParams);

	virtual void load();

	virtual void draw();

	virtual void update();

	virtual void clean();





protected:

	int x;

	int y;

	int width;

	int height;

	int currentRow;

	int currentFrame;

	std::string textureID;
	
	std::string texturePath;
};
//}




#endif /* SDLGameObject_hpp */
