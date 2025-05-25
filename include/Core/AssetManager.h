#pragma once
#include<string>
// Отвечает за управлением дополнительными ресурсами
class AssetManager {
public:
	void uploadTexture(std::string path);
	void uploadFont(std::string path);
	

};