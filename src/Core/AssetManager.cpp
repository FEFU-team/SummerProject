#include "../include/Core/AssetManager.h"
#include <string>

void AssetManager::uploadFont(const std::string& name,std::string path)
{
    sf::Font font;
    if (font.openFromFile(path)) {
        fonts.insert({ name,font });
    }
}

sf::Font AssetManager::getFont(const std::string& name)
{
     return fonts.at(name);
}



	



