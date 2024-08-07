#pragma once
#include <SDL_ttf.h>
#include "../Resources/Resources.h"
#include <string>

 class Font : public Resource
{
public:
	Font() = default;
	~Font();

	bool Load(const std::string& name, int fontSize);
		 bool Create(std::string name, ...) override;

	friend class Text;

private:
		 _TTF_Font* m_ttfFont{ nullptr };

		 // Inherited via Resource
 };