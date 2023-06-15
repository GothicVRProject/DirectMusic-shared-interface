#include "dmusic/cffi/directmusic.h"
#include "../vendor/dmusic/include/directmusic.h"

DMusic_DirectMusic *DMusicInitDirectMusic()
{
    auto dm = new DMusic_DirectMusic();
    return dm;
}

void DMusicFreeDirectMusic(DMusic_DirectMusic *dm)
{
    delete dm;
}

DMusic_PatternList *DMusicLoadFile(DMusic_DirectMusic *dm, const char *filename, int size)
{
    DMusic_PatternList pattern = dm->load(filename);
    return new Dx8::PatternList(std::move(pattern));
}

void DMusicAddPath(DMusic_DirectMusic *dm, const char *path)
{
    dm->addPath(path);
}
