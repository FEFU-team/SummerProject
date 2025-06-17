#pragma once
#include<string>
#include <SFML/Graphics.hpp>
#include <map>
// Отвечает за управлением дополнительными ресурсами
class AssetManager {
public:
	// Загрузка шрифта
	// name имя текста для map
	void uploadFont( const std::string& name,std::string path);
	// Получение шрифта по имени
	sf::Font* getFont(const std::string& name);
	// Загрузка текструры 
	// name имя текструра 
	void uploadTexture(const std::string& name,std::string path);
	// Получение текструры по имени
	sf::Texture getTexture(const std::string& name);

private:
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Texture> textures;
	

};