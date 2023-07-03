#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#undef TAPPING_TERM //un-define it
#define TAPPING_TERM 250
// #define PERMISSIVE_HOLD # this is really annoying if you type too fast
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
#define IGNORE_MOD_TAP_INTERRUPT
#define ENCODER_DIRECTION_FLIP
