#include "dmusic/cffi/music.h"
#include "../vendor/dmusic/include/music.h"

DMSC_API DMusic_Music *DMusicInitMusic()
{
    auto music = new DMusic_Music;
    return music;
}

DMSC_API void DMusicFreeMusic(DMusic_Music *m)
{
    delete m;
}

DMSC_API void DMusicAddPattern(DMusic_Music *m, const DMusic_PatternList &list)
{
    m->addPattern(list);
}