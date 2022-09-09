#include "SDLWavAudioData.h"

SDLWavAudioData::SDLWavAudioData(const std::string& fileName, bool streamFromFile)
{
	// TODO: streamFromFile

	SDL_AudioSpec wavSpec{};
	Uint8* wavStart;
	Uint32 wavLength;
	if (SDL_LoadWAV(fileName.c_str(), &wavSpec, &wavStart, &wavLength) == NULL)
	{
		throw fileName;
	}

	m_Pos = wavStart;
	m_Start = wavStart;
	m_Lenght = wavLength;

}

SDLWavAudioData::~SDLWavAudioData()
{
	SDL_FreeWAV(m_Start);
}

size_t SDLWavAudioData::GenerateSamples(float* stream, size_t streamLength, size_t pos, const SampleInfo& info)
{
	// TODO: Handle pos
	if (m_Lenght == 0)
		return -1;

	Uint32 length = (Uint32)streamLength;
	length = length > m_Lenght ? m_Lenght : length;

	Sint16* samples = (Sint16*)m_Pos;

	float factor = (float)info.volume / (float)SDL_MAX_SINT16;
	for (Uint32 i = 0; i < length; i++)
	{
		stream[i] = (*samples) * factor ;
		samples++;
	}

	m_Pos = (Uint8*)samples;
	m_Lenght -= length*2; // 2 bytes
}

size_t SDLWavAudioData::GetAudioLength()
{
	return m_Lenght;
}
