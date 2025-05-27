#pragma once
#include<string>
#include <SFML/Graphics.hpp>
#include <map>
// Отвечает за управлением дополнительными ресурсами
class AssetManager {
public:
	void uploadFont( const std::string& name,std::string path);
	sf::Font getFont(const std::string& name);
private:
	std::map<std::string, sf::Font> fonts;
	//std::map<std::string, sf::Texture> textures;
	

};