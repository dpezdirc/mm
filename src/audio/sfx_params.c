#include "global.h"

#define DEFINE_SFX(_0, _1, importance, distParam, randParam, flags2, flags1)       \
    { importance, flags2,                                                          \
      ((((distParam) << SFX_PARAM_DIST_RANGE_SHIFT) & SFX_PARAM_DIST_RANGE_MASK) | \
       (((randParam) << SFX_PARAM_RAND_FREQ_RAISE_SHIFT) & SFX_PARAM_RAND_FREQ_RAISE_MASK) | (flags1)) },

SfxParams sEnemyBankParams[] = {
#include "tables/sfx/enemybank_table.h"
};

SfxParams sPlayerBankParams[] = {
#include "tables/sfx/playerbank_table.h"
};

SfxParams sItemBankParams[] = {
#include "tables/sfx/itembank_table.h"
};

SfxParams sEnvBankParams[] = {
#include "tables/sfx/environmentbank_table.h"
};

SfxParams sSystemBankParams[] = {
#include "tables/sfx/systembank_table.h"
};

SfxParams sOcarinaBankParams[] = {
#include "tables/sfx/ocarinabank_table.h"
};

SfxParams sVoiceBankParams[] = {
#include "tables/sfx/voicebank_table.h"
};

#undef DEFINE_SFX

SfxParams* gSfxParams[7] = {
    sPlayerBankParams, sItemBankParams,    sEnvBankParams,   sEnemyBankParams,
    sSystemBankParams, sOcarinaBankParams, sVoiceBankParams,
};

//--------------------------------------
// dpezdirc
//--------------------------------------

const char* sEnemyBankStrings[] = {
#include "tables/sfx/strings/enemybank_strings.h"
};

const char* sPlayerBankStrings[] = {
#include "tables/sfx/strings/playerbank_strings.h"
};

const char* sItemBankStrings[] = {
#include "tables/sfx/strings/itembank_strings.h"
};

const char* sEnvBankStrings[] = {
#include "tables/sfx/strings/environmentbank_strings.h"
};

const char* sSystemBankStrings[] = {
#include "tables/sfx/strings/systembank_strings.h"
};

const char* sOcarinaBankStrings[] = {
#include "tables/sfx/strings/ocarinabank_strings.h"
};

const char* sVoiceBankStrings[] = {
#include "tables/sfx/strings/voicebank_strings.h"
};

const char** gSfxStrings[7] = {
    sPlayerBankStrings, sItemBankStrings,    sEnvBankStrings,   sEnemyBankStrings,
    sSystemBankStrings, sOcarinaBankStrings, sVoiceBankStrings,
};

OSTime sEnemyBankTimes[736] = {0};
OSTime sPlayerBankTimes[464] = {0};
OSTime sItemBankTimes[112] = {0};
OSTime sEnvBankTimes[464] = {0};
OSTime sSystemBankTimes[96] = {0};
OSTime sOcarinaBankTimes[16] = {0};
OSTime sVoiceBankTimes[400] = {0};

OSTime* gSfxTimes[7] = {
    sPlayerBankTimes, sItemBankTimes,    sEnvBankTimes,   sEnemyBankTimes,
    sSystemBankTimes, sOcarinaBankTimes, sVoiceBankTimes,
};
