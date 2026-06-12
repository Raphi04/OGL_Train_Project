#define MINIAUDIO_IMPLEMENTATION
#include "audio.hpp"

#include <iostream>

ma_engine audioEngine {};
ma_sound klaxon {};

void initSound()
{
    if (ma_engine_init(NULL, &audioEngine) != MA_SUCCESS)
    {
        std::cout << "Erreur init engine audio\n";
        return;
    }

    ma_result result = ma_sound_init_from_file(
        &audioEngine,
        "../assets/audio/horn.wav",
        0,
        NULL,
        NULL,
        &klaxon
    );

    if (result != MA_SUCCESS)
    {
        std::cout << "Erreur chargement horn.wav\n";
    }
}

void playKlaxon() {
    ma_sound_stop(&klaxon);
    ma_sound_seek_to_pcm_frame(&klaxon, 0);
    ma_sound_start(&klaxon);
}