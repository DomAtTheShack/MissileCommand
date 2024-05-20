//
// Created by dominichann on 5/19/24.
//

#ifndef MISSILECOMMAND_AUDIOSYSTEM_H
#define MISSILECOMMAND_AUDIOSYSTEM_H

#include <SDL_audio.h>
#include <atomic>
#include <SDL_mixer.h>
#include <vector>

class AudioSystem {
public:
    AudioSystem();
    ~AudioSystem();

    void LoadWAV(const char* audioPath, bool overlap = true);
    void PlayCurrentWAV();
    void CleanupCurrentWAV();

    void LoadMP3(const char* audioPath);
    void PlayCurrentMP3();
    void CleanupCurrentMP3();

    void SetVolume(int volume);
    int GetVolume() const;
private:
    bool loaded;
    bool playing;
    char* currentSFX;
    Mix_Chunk* currentWavChunk;
    Mix_Music* currentMusic;

    std::vector<Mix_Chunk*> sounds;

    static void audioCallback(void* userdata, Uint8* stream, int len);
};


#endif //MISSILECOMMAND_AUDIOSYSTEM_H
