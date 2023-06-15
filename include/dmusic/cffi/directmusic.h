#pragma once
#include "Api.h"
#include "patternlist.h"
#include "segment.h"

#ifdef __cplusplus
    #include "../../../vendor/dmusic/include/directmusic.h"
    typedef Dx8::DirectMusic DMusic_DirectMusic;
#else
    typedef struct DMusicInteral_DirectMusic DMusic_DirectMusic;
#endif

DMSC_API DMusic_DirectMusic *DMusicInitDirectMusic();
DMSC_API void DMusicFreeDirectMusic(DMusic_DirectMusic *dm);
DMSC_API DMusic_PatternList *DMusicLoadFile(DMusic_DirectMusic *dm, const char *filename, int size);
DMSC_API void DMusicAddPath(DMusic_DirectMusic *dm, const char *path);
