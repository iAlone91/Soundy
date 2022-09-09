#pragma once

#include "../IAudioData.h"
#include <SDL.h>
#include <string>

class SDLWavAudioData : public IAudioData
{
public:

	SDLWavAudioData( const std::string& fileName, bool streamFromFile);
	virtual ~SDLWavAudioData();
	virtual size_t GenerateSamples(float* stream, size_t streamLength, size_t pos, const SampleInfo& info) override;
	virtual size_t GetAudioLength() override;

private:

	Uint8* m_Pos;
	Uint8* m_Start;
	Uint32 m_Lenght;

	SDLWavAudioData(SDLWavAudioData& other) { (void)other; }
	void operator=(const SDLWavAudioData& other) { (void)other; }
};