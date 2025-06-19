#include "../include/Core/AssetManager.h"
#include <string>

void AssetManager::uploadFont(const std::string& name,std::string path)
{
    sf::Font font;
    if (font.openFromFile(path)) {
        fonts.insert({ name,font });
    }
}

sf::Font* AssetManager::getFont(const std::string& name)
{
     return &fonts.at(name);
}

void AssetManager::uploadTexture(const std::string& name, std::string path)
{
    sf::Texture texture;
    texture.setSmooth(true);
    if (texture.loadFromFile(path)) {
        textures.insert({ name,texture });
    }
}

sf::Texture* AssetManager::getTexture(const std::string& name)
{
    return &textures.at(name);
}



	



