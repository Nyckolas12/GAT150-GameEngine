#pragma once
#include <fmod.hpp>
#include <map>
#include <string>
class Audio
{
public:
	Audio() = default;
	~Audio() = default;

	bool Initialize();
	void Shutdown();
	void Update();
	bool Addsound(const std::string& name);
	bool Playsound(const std::string& name);

	FMOD::System* m_audio{ nullptr };
protected:
	std::map<std::string, FMOD::Sound*> m_sounds;
};