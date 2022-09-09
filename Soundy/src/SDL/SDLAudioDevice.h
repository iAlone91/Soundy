#pragma once

#include "../IAudioDevice.h"

class SDLAudioDevice : public IAudioDevice 
{
public:
	
	virtual IAudioData* CreateAudioFromFile(const std::string& filePath) override;
	virtual void ReleaseAudio(IAudioData* audioData) override;

private:
};