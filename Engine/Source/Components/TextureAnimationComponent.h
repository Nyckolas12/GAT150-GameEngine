#pragma once
#include "TextureComponent.h"
#include "Renderer/Texture.h"


class TextureAnimationComponent : public TextureComponent
{
public:

	void Initialize() override;
	void Update(float dt) override;
	CLASS_DECLARATION(TextureAnimationComponent)
	CLASS_PROTOTYPE(TextureAnimationComponent)

public:
	float fps{ 0 };
	bool loop{ true };
	int numColumns{ 0 };
	int numRows{ 0 };
	int startFrame{ 0 };
	int endFrame{ 0 };
	int frame{ 0 };
	int frameTimer{ 0 };



	
};