#pragma once

#include <string>
#include "IAudioData.h"

class IAudioDevice
{
public:
	virtual ~IAudioDevice() {}
	virtual IAudioData* CreateAudioFromFile(const std::string& filePath) = 0;
	virtual void ReleaseAudio(IAudioData* audioData) = 0;

private:
};