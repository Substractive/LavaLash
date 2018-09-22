//
//  LoaderParams.hpp
//  LavaLash
//
//  Created by Dino Budic on 16/09/2018.
//  Copyright © 2018 Dino Budic. All rights reserved.
//

#ifndef LoaderParams_h
#define LoaderParams_h

#include <stdio.h>
#include <iostream>
//namespace EngineGameObject {
	class LoaderParams {
	public:
		LoaderParams(int x, int y, int width, int height,std::string texturePath, std::string textureID) : x(x), y(y), width(width), height(height),texturePath(texturePath) , textureID(textureID) {}
		int getX() const { return x; }
		int getY() const { return y; }
		int getWidth() const { return width; }
		int getHeight() const { return height; }
		std::string getTexturePath() const { return texturePath;  }
		std::string getTextureID() const { return textureID; }
	private:
		int x;
		int y;
		int width;
		int height;
		std::string textureID;
		std::string texturePath;
	};
//}

#endif /* LoaderParams_hpp */


