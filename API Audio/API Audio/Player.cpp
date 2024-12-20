#include "Player.h"
#include "../framework/Win32/Framework.h"

// D�claration globale de la source
ALuint uiSource = 0;

int init() {
    // Initialize Framework
    ALFWInit();

    if (!ALFWInitOpenAL()) {
        ALFWShutdown();
        return 0;
    }

    return 1;
}


int Play(const char* fileName) {
    ALuint uiBuffer;
    ALint iState;

   

    Stop();

    // Generate an AL Buffer
    alGenBuffers(1, &uiBuffer);

    // Load Wave file into OpenAL Buffer
    if (!ALFWLoadWaveToBuffer((char*)fileName, uiBuffer)) {
        ALFWprintf("Failed to load %s\n", fileName);
        return -1;
    }



    // Generate a Source to playback the Buffer
    alGenSources(1, &uiSource);

    // Attach Source to Buffer
    alSourcei(uiSource, AL_BUFFER, uiBuffer);
    alSourcei(uiSource, AL_LOOPING, AL_TRUE); // Pour jouer en boucle

    // Play Source
    alSourcePlay(uiSource);
    
    return 0;
}

void Pause() {
    if (uiSource) {
        alSourcePause(uiSource);
    }
}

// Pour continuer la lecture apr�s pause
void Resume() {
    if (uiSource) {
        alSourcePlay(uiSource);
    }
}

void Stop()
{
    if (uiSource) 
    {
        alSourceStop(uiSource);
    }
}

// Nettoyage des ressources
void Cleanup() {
    if (uiSource) {
        alSourceStop(uiSource);
        alDeleteSources(1, &uiSource);
        uiSource = 0; // R�initialiser la source
    }

    ALFWShutdownOpenAL();
    ALFWShutdown();
}

void SetVolume(float volume) 
{
    volume /= 100;
    // Clamp le volume entre 0.0f et 1.0f
    if (volume < 0.0f) volume = 0.0f;
    if (volume > 1.0f) volume = 1.0f;

    if (uiSource) {
        alSourcef(uiSource, AL_GAIN, volume);
    }
}