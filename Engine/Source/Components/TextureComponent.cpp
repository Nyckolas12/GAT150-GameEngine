#include "TextureComponent.h"
#include"Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Engine.h"
#include "Resources/ResourceManager.h"

FACTORY_REGISTER(TextureComponent)

void TextureComponent::Initialize()
{
	if (!textureName.empty())
	{
		texture = ResourceManager::Instance().Get<Texture>(textureName,owner->scene->engine->GetRenderer());
	}

	if (texture && source.width == 0 && source.height == 0)
	{
		source.x = 0;
		source.y = 0;
		source.width = (int)texture->GetSize().x;
		source.height = (int)texture->GetSize().y;
	}
}

void TextureComponent::Update(float dt)
{
}

void TextureComponent::Draw(Renderer& renderer)
{
	Transform transform = owner->transform;
	renderer.DrawTexture(texture,transform);
}

void TextureComponent::Read(const json_t& value)
{
	READ_DATA_REQUIRED(value, textureName);
	READ_DATA(value, source);
}

void TextureComponent::Write(json_t& value)
{
}