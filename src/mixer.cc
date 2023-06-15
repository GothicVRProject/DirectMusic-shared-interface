#include "dmusic/cffi/mixer.h"
#include "../vendor/dmusic/include/mixer.h"

DMSC_API DMusic_Mixer *DMusicInitMixer()
{
    auto mixer = new DMusic_Mixer;
    return mixer;
}

DMSC_API void DMusicFreeMixer(DMusic_Mixer *m)
{
    delete m;
}

DMSC_API void DMusic_SetVolume(DMusic_Mixer *m, float v)
{
    m->setVolume(v);
}

DMSC_API void DMusicSetMusicVolume(DMusic_Mixer *m, float v)
{
    m->setMusicVolume(v);
}

DMSC_API void DMusicSetMusic(DMusic_Mixer *m, DMusic_Music *music, Dx8::DMUS_EMBELLISHT_TYPES embellishment = Dx8::DMUS_EMBELLISHT_NORMAL)
{
    DMusic_Music const *musicPtr = static_cast<DMusic_Music *>(music);
    m->setMusic(*musicPtr, embellishment);
}

DMSC_API void DMusicMix(DMusic_Mixer *m, int16_t *out, size_t samples)
{
    m->mix(out, samples);
}