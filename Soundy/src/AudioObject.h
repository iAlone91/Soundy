#pragma once

#include "IAudioData.h"
#include "SampleInfo.h"

class AudioObject
{
public:
	AudioObject(const SampleInfo& info, IAudioData* data);

	bool GenarateSamples(float* stream, size_t streamLength);
	void SetPos(double pos);
private:
	size_t m_AudioPos;
	size_t m_AudioLength;

	SampleInfo  m_SampleInfo;
	IAudioData* m_pAudioData;

	size_t PosToAbsolutePos(double pos);
};