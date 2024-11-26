#include "Player.h"
#include "../framework/Win32/Framework.h"

// Déclaration globale de la source
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

// Pour continuer la lecture après pause
void Resume() {
    if (uiSource) {
        alSourcePlay(uiSource);
    }
}

// Nettoyage des ressources
void Cleanup() {
    if (uiSource) {
        alSourceStop(uiSource);
        alDeleteSources(1, &uiSource);
        uiSource = 0; // Réinitialiser la source
    }

    ALFWShutdownOpenAL();
    ALFWShutdown();
}