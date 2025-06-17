#pragma once
#include<string>
#include <SFML/Graphics.hpp>
#include <map>
// �������� �� ����������� ��������������� ���������
class AssetManager {
public:
	// �������� ������
	// name ��� ������ ��� map
	void uploadFont( const std::string& name,std::string path);
	// ��������� ������ �� �����
	sf::Font* getFont(const std::string& name);
	// �������� ��������� 
	// name ��� ��������� 
	void uploadTexture(const std::string& name,std::string path);
	// ��������� ��������� �� �����
	sf::Texture getTexture(const std::string& name);

private:
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Texture> textures;
	

};