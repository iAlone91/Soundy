#include "SDLAudioDevice.h"
#include "SDLWavAudioData.h"

IAudioData* SDLAudioDevice::CreateAudioFromFile(const std::string& filePath)
{
	return new SDLWavAudioData( filePath, false );
}

void SDLAudioDevice::ReleaseAudio(IAudioData* audioData)
{
	if (audioData)
		delete audioData;
}
