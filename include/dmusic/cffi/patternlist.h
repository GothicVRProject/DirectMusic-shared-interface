#pragma once
#include "Api.h"

#ifdef __cplusplus
    #include "../../../vendor/dmusic/include/patternlist.h"
    typedef Dx8::PatternList DMusic_PatternList;
#else
    typedef struct DMusicInteral_PatternList DMusic_PatternList;
#endif