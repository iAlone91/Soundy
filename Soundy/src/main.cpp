#include <iostream>
#include <SDL.h>

#define FILE_PATH "../resources/Chrono Trigger - Intro.wav"

struct AudioData
{
	Uint8* pos;
	Uint32 lenght;
};

void MyAudioCallback(void* userdata, Uint8* stream, int streamLegnt)
{
	AudioData* audio = (AudioData*)userdata;

	if (audio->lenght == 0)
		return;

	Uint32 length = (Uint32)streamLegnt;
	length = length > audio->lenght ? audio->lenght : length;

	SDL_memcpy(stream, audio->pos, length);

	audio->pos += length;
	audio->lenght -= length;
}

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_AudioSpec wavSpec{};
	Uint8* wavStart;
	Uint32 wavLength;

	if (SDL_LoadWAV(FILE_PATH, &wavSpec, &wavStart, &wavLength) == NULL)
	{
		std::cerr << "Error: " << FILE_PATH << " could not be loaded!\n";
		return 0;
	}

	AudioData audio;
	audio.pos = wavStart;
	audio.lenght = wavLength;

	wavSpec.callback = MyAudioCallback;
	wavSpec.userdata = &audio;

	SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);

	if (device == 0)
	{
		std::cerr << "Error: " << SDL_GetError();
		return 0;
	}

	SDL_PauseAudioDevice(device, 0);

	while ( audio.lenght > 0)
	{
		SDL_Delay(100);
	}

	SDL_CloseAudioDevice(device);
	SDL_FreeWAV(wavStart);
	SDL_Quit();

	return 0;
}