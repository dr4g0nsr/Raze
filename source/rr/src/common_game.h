//
// Definitions of common game-only data structures/functions
// (and declarations of data appearing in both)
// for EDuke32 and Mapster32
//

#ifndef EDUKE32_COMMON_GAME_H_
#define EDUKE32_COMMON_GAME_H_

#include "collections.h"
#include "grpscan.h"
#include "gamecontrol.h"

BEGIN_RR_NS


#define DUKE                (g_gameType & GAMEFLAG_DUKE)
#define RR                  (g_gameType & GAMEFLAG_RR)
#define RRRA                (g_gameType & GAMEFLAG_RRRA)
#define NAM                 (g_gameType & GAMEFLAG_NAM)
#define NAPALM              (g_gameType & GAMEFLAG_NAPALM)
//#define WW2GI               (g_gameType & GAMEFLAG_WW2GI)
//#define NAM_WW2GI           (g_gameType & (GAMEFLAG_NAM|GAMEFLAG_WW2GI))
#define SHAREWARE           (g_gameType & GAMEFLAG_SHAREWARE)
//#define DUKEBETA            ((g_gameType & GAMEFLAG_DUKEBETA) == GAMEFLAG_DUKEBETA)
//#define IONMAIDEN           (g_gameType & GAMEFLAG_IONMAIDEN)

enum Games_t {
    GAME_DUKE = 0,
    GAME_RR,
    GAME_RRRA,
    GAME_NAM,
    GAME_NAPALM,
    //GAME_WW2GI,
    GAMECOUNT
};

typedef enum basepal_ {
    BASEPAL = 0,
    WATERPAL,
    SLIMEPAL,
    DREALMSPAL,
    TITLEPAL,
    ENDINGPAL,  // 5
    ANIMPAL,
    DRUGPAL,
    BASEPALCOUNT
} basepal_t;

#define OSDTEXT_DEFAULT   "^00"
#define OSDTEXT_DARKRED   "^10"
#define OSDTEXT_GREEN     "^11"
#define OSDTEXT_RED       "^21"
#define OSDTEXT_YELLOW    "^23"

#define OSDTEXT_BRIGHT    "^S0"

#define OSD_ERROR OSDTEXT_DARKRED OSDTEXT_BRIGHT

extern int loaddefinitions_game(const char *fn, int32_t preload);

//////////

extern void G_InitMultiPsky(int CLOUDYOCEAN__DYN, int MOONSKY1__DYN, int BIGORBIT1__DYN, int LA__DYN);
extern void G_SetupGlobalPsky(void);

//////////

extern void G_LoadLookups(void);

//////////

# define FORMAT_UPGRADE_ELIGIBLE
extern FileReader S_OpenAudio(const char *fn, char searchfirst, uint8_t ismusic);

END_RR_NS

#endif
