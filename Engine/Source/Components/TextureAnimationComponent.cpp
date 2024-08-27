#include "TextureAnimationComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Resources/ResourceManager.h"
#include "Engine.h"
FACTORY_REGISTER(TextureAnimationComponent)
void TextureAnimationComponent::Initialize()
{
	TextureComponent::Initialize();
}

void TextureAnimationComponent::Update(float dt)
{
	// update timer
	frameTimer +=  dt;
		if (frameTimer <= 0)
		{
			frameTimer = 1.0f / fps;
			frame++;
				if (frame > endFrame && loop == true) frame = startFrame;
		}
	// calculate subimage size
		Vector2 size = texture->GetSize() / Vector2{ numColumns, numRows };
		int column = (frame - 1) % numColumns;
	int row = (frame - 1) / numColumns;
	// set source rect from current column/row and subimage size
	source.x = (int)(numColumns * size.x);
	source.y = (int)(numRows * size.y);
	source.width = (int)(size.x);
	source.height = (int)(size.y);
}

void TextureAnimationComponent::Read(const json_t& value)
{
	READ_DATA(value, fps);
	READ_DATA(value, loop);
	READ_DATA(value, numColumns);
	READ_DATA(value, numRows);
	READ_DATA(value, startFrame);
	READ_DATA(value, endFrame);
	READ_DATA(value, frame);
	READ_DATA(value, frameTimer);
}

void TextureAnimationComponent::Write(json_t& value)
{
}
