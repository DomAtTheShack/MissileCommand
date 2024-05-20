#include "../AudioSystem.h"
#include <iostream>

AudioSystem::AudioSystem() : loaded(false), playing(false), currentSFX(nullptr), currentWavChunk(nullptr), currentMusic(nullptr) {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_Mixer could not initialize! SDL_Mixer Error: " << Mix_GetError() << std::endl;
    }
    if(Mix_Init(MIX_INIT_MP3))
        std::cerr << "INFO: SDL2 Mixer and Audio System initialed!" << std::endl;

}

AudioSystem::~AudioSystem() {
    CleanupCurrentWAV();
    CleanupCurrentMP3();
    Mix_CloseAudio();
    Mix_Quit();
}

void AudioSystem::LoadWAV(const char* audioPath, bool overlap) {
    if (!overlap) {
        // Stop all currently playing channels
        Mix_HaltChannel(-1);
    }
    currentWavChunk = Mix_LoadWAV(audioPath);
    if (currentWavChunk == nullptr) {
        std::cerr << "Failed to load WAV. SDL_Mixer error: " << Mix_GetError() << std::endl;
        return;
    }
    loaded = true;
    if (overlap) {
        PlayCurrentWAV();
    }
}


void AudioSystem::PlayCurrentWAV() {
    if (!loaded || currentWavChunk == nullptr) {
        std::cerr << "No WAV file loaded." << std::endl;
        return;
    }
    Mix_PlayChannel(-1, currentWavChunk, 0);
    playing = true;
}

void AudioSystem::CleanupCurrentWAV() {
    if (currentWavChunk != nullptr) {
        Mix_FreeChunk(currentWavChunk);
        currentWavChunk = nullptr;
    }
    loaded = false;
    playing = false;
}

void AudioSystem::LoadMP3(const char* audioPath) {
    currentMusic = Mix_LoadMUS(audioPath);
    if (currentMusic == nullptr) {
        std::cerr << "Failed to load MP3. SDL_Mixer error: " << Mix_GetError() << std::endl;
        return;
    }
    loaded = true;
}

void AudioSystem::PlayCurrentMP3() {
    if (!loaded || currentMusic == nullptr) {
        std::cerr << "No MP3 file loaded." << std::endl;
        return;
    }
    Mix_PlayMusic(currentMusic, -1);
    playing = true;
}

void AudioSystem::CleanupCurrentMP3() {
    if (currentMusic != nullptr) {
        Mix_FreeMusic(currentMusic);
        currentMusic = nullptr;
    }
    loaded = false;
    playing = false;
}


void AudioSystem::SetVolume(int volume) {
    // Adjust volume for sound effects
    Mix_Volume(-1, volume);
    // Adjust volume for music
    Mix_VolumeMusic(volume);
}

int AudioSystem::GetVolume() const {
    // Get volume for sound effects
    int soundVolume = Mix_Volume(-1, -1);
    // Get volume for music
    int musicVolume = Mix_VolumeMusic(-1);
    // Return the average of sound effects and music volumes
    return (soundVolume + musicVolume) / 2;
}

void AudioSystem::audioCallback(void* userdata, Uint8* stream, int len) {
    SDL_AudioSpec* spec = (SDL_AudioSpec*)userdata;
    if (len > 0) {
        Uint8* audioData = stream;
        int numSamples = len;
        const double frequency = 440.0;
        const double amplitude = 127.0;
        const double offset = 128.0;
        const double twoPi = 2.0 * M_PI;

        for (int i = 0; i < numSamples; ++i) {
            double time = static_cast<double>(i) / static_cast<double>(spec->freq);
            double value = sin(twoPi * frequency * time);
            audioData[i] = static_cast<Uint8>((value + 1.0) * amplitude);
        }
    }
}
