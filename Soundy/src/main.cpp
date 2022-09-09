#include <iostream>
#include <SDL.h>

#include "IAudioDevice.h"
#include "IAudioContext.h"
#include "IAudioData.h"

#include "SDL/SDLAudioDevice.h"
#include "SDL/SDLAudioContext.h"

#define FILE_PATH "../resources/FFVII.wav"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	IAudioDevice* device = new SDLAudioDevice();
	IAudioContext* context = new SDLAudioContext();

	IAudioData* data = device->CreateAudioFromFile(FILE_PATH);

	SampleInfo info;
	info.volume = 1.0;

	AudioObject sound(info, data);

	char in = 0;
	while ( in != 'q')
	{
		std::cin >> in;
		switch (in)
		{
		case 'p':
			context->PlayAudio(sound);
			break;
		case 's':
			context->PauseAudio(sound);
			break;
		default:
			break;
		}
	}

	device->ReleaseAudio(data);
	delete context;
	delete device;

	SDL_Quit();

	return 0;
}