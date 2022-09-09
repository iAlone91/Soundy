#pragma once

#include "../IAudioContext.h"
#include <vector>
#include <SDL.h>

class SDLAudioContext : public IAudioContext
{
public:
	SDLAudioContext();
	virtual ~SDLAudioContext();

	virtual void PlayAudio(AudioObject& ao) override;
	virtual void PauseAudio(AudioObject& ao) override;
	virtual void StopAudio(AudioObject& ao) override;

	void GenerateSamples(Uint8* stream, int streamLength);

private:
	SDL_AudioDeviceID m_Device;
	std::vector<float> m_Stream;
	std::vector<AudioObject*> m_PlayingAudio;

	bool RemoveAudio(AudioObject& ao);

};