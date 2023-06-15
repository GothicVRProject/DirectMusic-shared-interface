#pragma once
#include "Api.h"
#include "patternlist.h"

#ifdef __cplusplus

    #include "../../../vendor/dmusic/include/music.h"
    typedef Dx8::Music DMusic_Music;
#else
    typedef struct DMusicInteral_Music DMusic_Music;
#endif

DMSC_API DMusic_Music* DMusicInitMusic();
DMSC_API void DMusicFreeMusic(DMusic_Music *m);
DMSC_API void DMusicAddPattern(DMusic_Music *m, const DMusic_PatternList &list);