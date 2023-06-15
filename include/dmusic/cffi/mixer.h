#pragma once
#include "Api.h"
#include "patternlist.h"
#include "structs.h"
#include "music.h"

#ifdef __cplusplus
    #include "../../../vendor/dmusic/include/mixer.h"
    typedef Dx8::Mixer DMusic_Mixer;
#else
    typedef struct DMusicInteral_Mixer DMusic_Mixer;
#endif

DMSC_API DMusic_Mixer *DMusicInitMixer();
DMSC_API void DMusicFreeMixer(DMusic_Mixer *m);
DMSC_API void DMusic_SetVolume(DMusic_Mixer *m, float v);
DMSC_API void DMusicSetMusicVolume(DMusic_Mixer *m, float v);
DMSC_API void DMusicSetMusic(DMusic_Mixer *m, DMusic_Music *music, Dx8::DMUS_EMBELLISHT_TYPES embellishment);
DMSC_API void DMusicMix(DMusic_Mixer *m, int16_t *out, size_t samples);
