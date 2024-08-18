#pragma once
#include <string>
#include"../Resources/Resources.h"
#include "../Math/Vector2.h"
struct SDL_Texture;

class Texture : public Resource
{
public:
	Texture() = default;
	Texture(SDL_Texture* texture) : m_texture{ texture } {}
	~Texture();

	bool Load(const std::string& filename, class Renderer& renderer);

	Vector2 GetSize();


	friend class Renderer;
	bool Create(std::string filename, ...) override;

private:
	struct SDL_Texture* m_texture{ nullptr };

	
};