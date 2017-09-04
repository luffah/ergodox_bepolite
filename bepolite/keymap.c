#include "ergodox.h"
#include "debug.h"
#include "keymap_bepo.h"
/*#include "keymap_french.h"*/

// 

enum layers {
  BASE,    //default layer
  FL,      // functions keys 
  NUM,      // functions keys 
  REVERT,   // invert left and right hands
};

#define KC_ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *                       __________________________________________________
 *                      |.------------------------------------------------.|
 *                      || Layout :  Bepo (lite)                          ||
 *                      || Model  :  Ergodox Ez 80 keys                   ||
 *                      || Status :  Under construction                   ||
 *                      || Layers :  Base(0) Functions(1)  Midi?  Mouse ? ||
 *                      || ============================================== ||
 *                      || Base      : The base keymaps with arrows and   ||
 *                      ||             navigation keys                    ||
 *                      ||                                                ||
 *                      || Functions : Contain all is needed with F1-12   ||
 *                      ||             keys                               ||
 *                      ||                                                ||
 *                      ||                                                ||
 *                      ||________________________________________________||
 *                      '--------------------------------------------------'
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *  ←   ↓    ↑   →  = arrows =  Left Down Up Right
 *
 * Sft Spce BSpc Ent = Shift Space BackSpace Enter
 *
 * ->| = tab     |<- = Shift-Tab
 * 
 * The keys can be associated to one character (typing) and one {modifier} (pressing).
 * This is the case for the keys :  Ç { Shift };  Up { Control }; LeftSpace {Shift}; RightSpace {AltGr}
 *
 * The scheme represent the ergodox 80keys,
 *    first line of a key is the base layout
 *    second line is the modifier when the key is holded
 *    third line (marked with dots '.' ) is the function layer FL
 *        FL is activated by -[.]
 *    fourth (marked with double dots ':' ) is the num layer   NUM
 *        NUM is activated by -[:]
 * ,------.----.----.----.----.----.-----.    Layout   ,----.----.----.----.----.----.------.  |
 * ¦   $  ¦ "  ¦  « ¦ »  ¦ (  ¦ )   ¦ Caps¦            ¦ %  ¦ @  ¦ +  ¦ -  ¦ /  ¦ *  ¦ =    ¦  |
 * ¦      ¦    ¦    ¦    ¦    ¦-[:]-¦  Alt¦            ¦ Alt¦    ¦    ¦    ¦    ¦    ¦      ¦  |
 * ..ESC....F1...F2...F3...F4...Calc.     |            |    :NumL:    |    |    |    |      |  |
 * \------\----\----\----\----\-----\-----¦            .----/----/----/----/----/----/------/  |
 * ¦ ->|  ¦ B  ¦ É  ¦ P  ¦ O  ¦ È   ¦ |<- ¦            ¦BSpc¦ ^  ¦ V  ¦ D  ¦ L  ¦ J  ¦ Z    ¦  |
 * |      |    |    |    |    |     |     |            ¦    |    |    |    |    |    |      ¦  |
 * .wwBack..F5...F6...F7...F8...Prev..Vol+.            |    ¦    .A.F1.A.F2.A.F3.A.F4.Alt.F5¦  |
 * ¦      ¦    ¦    ¦    ¦    ¦     ¦     ¦            ¦    : 6 :: 7 :: 8 :: 9 :: 0 ::: ( :::  |
 * \------\----\----\----\----\-----¦     ¦            ¦    ¦----/----/----/----/----/------/  |
 * ¦  W   ¦ A  ¦ U  ¦ I  ¦ E  ¦ ,   ¦-----'            '____¦ C  ¦ T  ¦ S  ¦ R  ¦ N  ¦ M    ¦  |
 * ¦      ¦    ¦    ¦    ¦    ¦     ¦                       ¦-[#]¦-[.]¦Ctrl¦ Alt¦ Gui¦   Sft¦  |
 * |      |    |    |    |    |     |                       |    |    |    |    |    |      |  |
 * .wwFwd...F9...F10..F11..F12..Play......              ____: 1 :: 2 :: 3 :: 4 :: 5 ::: ) :::  |
 * \------\----\----\----\----\-----¦     ¦            ¦    ¦----/----/----/----/----/------/  |
 * ¦Shift ¦ À  ¦ Y  ¦ X  ¦ .  ¦  K  ¦ ->| ¦            ¦Ent ¦ '  ¦ Q  ¦ G  ¦ H  ¦ F  ¦ Ç    ¦  |
 * ¦      ¦    ¦    ¦    ¦    ¦     ¦     ¦            ¦    ¦    ¦    ¦    ¦    ¦    ¦   Sft¦  |
 * ¦      ¦    ¦    ¦    ¦    ¦     ¦     ¦            ¦    : [ :: ] :: { :: } :: \ ::: . :::  |
 * ¦      ¦    ¦    ¦    ¦    ..Next..Vol-.            ¦    ¦    ¦    ¦    ¦    ¦    ¦      ¦  |
 * \------\----\----\----\----\-----\-----'            '----/----/----/----/----/----/------/  |
 *   ¦    ¦App |Home|End ¦Esc ¦                                  ¦ ←  ¦  ↓ ¦  ↑  | →  ¦Ins ¦   |
 *   ¦Ctrl¦-[:]¦Ctrl¦ Gui¦ Alt¦   ______.____.   .____._____.    ¦    ¦    ¦     |    ¦Ctrl¦   |
 *   \----\----\----\----\----\ /MSLft/MSRgt/\ /\ PgUp \ Del \   /----/----/----/----/----/    |
 *                    _________/_____/_____/     \_____\_____\__________ 
 *                  / Space   / Esc /     /\     /\ PgDn\ BSpc \Space   \
 *                 / Shift   /-[.]-/MsUP /         \     \ Ctrl\  AlGr   \
 *                /_________/_____/_____/           \_____\_____\_________\
 *                    /  ←  /  →  /     /\   /   \   /\ Ins \  ↑  \ ↓   \
 *                   /Shift/ Alt /MsDN /    /     \    \     \ Ctrl\ AlGr\
 *                  /_____/_____/_____/    /       \    \_____\_____\_____\
 *                  \     \     \     \   /         \   /     /     /     /
 *                                       /           \
 *                  --------------------'             '------------------------'
 *                     ----------------- \             / ---------------------/
 *   BACKSPACE   D __    L                      DOWN
 *   ENTER  T  __ |  |.--.  N             Left   __     UP
 *            |  ||  ||  |.-.              .--. \  \ .--.
 *            |  ||  ||  || |               \  \ \  \ \  \  .-. RIGHT
 *  SPACE   _ |  ||  ||  || |    BackSpace   \  \ |  | )  ) ) )       INS
 *   DOWN  | \|  ''  ''  '' |       SPACE _   \  \|  |/  / / /
 *   UP    |  |  ''  ''  '' |       DOWN | \   |            |
 *   INS   |  |             |       UP   |  \  |            |
 *         |                |             \  \ |            |
 *          \               |              \  ''            |
 *           \              |               \              /
 *            \            /                 \            /
 *        -- not using arrows --           -- using arrows  --
 *                 up
 * 
 * *
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_* 
[BASE] = KEYMAP_80(  // layer 0 : default
 // left hand
    BP_DOLLAR    , KC_1       , KC_2       , KC_3    , KC_4      , LT(NUM,KC_5)       , ALT_T(KC_CAPSLOCK)   ,
    KC_TAB    , BP_B       , BP_E_ACUTE , BP_P    , BP_O      , BP_E_GRAVE , LSFT(KC_TAB),
    BP_W     , BP_A       , BP_U     , BP_I    , BP_E      , BP_COMMA   ,
    OSM(MOD_LSFT) , BP_A_GRAVE , BP_Y       , BP_X    , BP_DOT    , BP_K       , KC_TAB,
    OSM(MOD_LCTL)  , LT(NUM,KC_APP), CTL_T(KC_HOME) , GUI_T(KC_END)   , ALT_T(KC_ESC) ,
    KC_MS_LEFT   , KC_MS_RIGHT,
   SFT_T(KC_SPC) ,KC_ESC, KC_MS_UP,
    SFT_T(KC_LEFT),ALT_T(KC_RIGHT)  , KC_MS_DOWN,
/*    KC_MS_LEFT   , KC_MS_RIGHT,*/
/*   SFT_T(KC_SPC) ,LT(FL,KC_ESC), KC_MS_UP,*/
/*    SFT_T(KC_SPC),SFT_T(KC_LEFT),ALT_T(KC_RIGHT)  , */
   // riht hand
  ALT_T(BP_PERCENT), KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS ,
    KC_BSPC     , KC_Y , BP_V , BP_D , BP_L , BP_J , BP_Z    ,
    LT(NUM,BP_C)         , LT(FL,BP_T)    , CTL_T(BP_S)   , ALT_T(BP_R)    , GUI_T(BP_N)    , SFT_T(BP_M) ,
    KC_ENTER      , BP_APOS       , BP_Q            , BP_G     , BP_H          , BP_F , SFT_T(BP_CCED) ,
    KC_LEFT       , KC_DOWN       , KC_UP ,KC_RIGHT           , CTL_T(KC_INS) ,
    KC_PGUP      , KC_DEL     ,
    KC_PGDN        , CTL_T(KC_BSPC) , RALT_T(KC_SPC)  ,
    KC_INS , CTL_T(KC_UP)  , RALT_T(KC_DOWN)
/*    KC_PGUP      , KC_DEL     ,*/
/*    KC_PGDN        , CTL_T(KC_INS) , RALT_T(KC_SPC)  ,*/
/*    KC_UP , CTL_T(KC_DOWN)  , RALT_T(KC_SPC)*/
    ),
/*experimental exchange left and right hands */
[REVERT] = KEYMAP_80(
   // left hand
    KC_KP_COMMA    , KC_6            , KC_7            , KC_8          , KC_9          , KC_0        , KC_MINS        ,
    KC_TAB        , KC_Y            , BP_V            , BP_D          , BP_L          , BP_J        , BP_Z           ,
    BP_C ,  BP_T   , BP_S     , BP_R   , BP_N   , BP_M ,
    KC_ENTER       , BP_APOS         , BP_Q            , BP_G          , BP_H          , BP_F        , SFT_T(BP_CCED) ,
    OSM(MOD_LCTL)  , BP_PERCENT      , KC_        , GUI_T(KC_ESC) , OSM(MOD_LALT) ,
    KC_        , KC_          ,
    KC_         , KC_   , KC_  ,
    KC_         , KC_   , KC_  ,
   // right hand
    BP_DOLLAR      , KC_1            , KC_2            , KC_3          , KC_4          , KC_5        , KC_CAPSLOCK    ,
    KC_BSPC         , BP_B            , BP_E_ACUTE      , BP_P          , BP_O          , BP_E_GRAVE  , TG(REVERT)  ,
     LT(NUM, BP_A)    , CTL_T(BP_U)     , ALT_T(BP_I)   , GUI_T(BP_E)   , BP_COMMA       ,BP_W           ,
    OSM(MOD_LSFT)  , BP_A_GRAVE      , BP_Y            , BP_X          , BP_DOT        , BP_K        , SFT_T(KC_TAB)  ,
    KC_LEFT        , KC_DOWN         , KC_UP           , KC_RIGHT      , CTL_T(KC_ESC) ,
    KC_        , KC_          ,
    KC_         , KC_   , KC_  ,
    KC_         , KC_   , KC_  
    ),

// Funtions keys 
[FL] = KEYMAP_80(
    // left hand
    KC_ESC            , KC_F1          , KC_F2        , KC_F3        , KC_F4         , KC_CALCULATOR        , KC_MUTE        ,
    KC_WWW_BACK       , KC_F5          , KC_F6        , KC_F7        , KC_F8         , KC_MPRV  , KC_VOLU  ,
    KC_WWW_FORWARD    , KC_F9          , KC_F10       , KC_F11        , KC_F12      , KC_MPLY    ,
    KC_            , KC_         , KC_       , KC_       ,  KC_  ,    KC_MNXT  , KC_VOLD  ,
    KC_            , KC_        , KC_      , KC_          , KC_           ,  
    //left thumb
    KC_            , KC_            ,
    KC_            , KC_            , KC_POWER     ,
    KC_HOME        , KC_END         , KC_          ,
    // right hand
    KC_          , KC_         , KC_        , KC_       , KC_       , KC_       , KC_          ,
    KC_    , KC_          , LALT(KC_F1)    , LALT(KC_F2)  , LALT(KC_F3) , LALT(KC_F4)  , LALT(KC_F5 ) ,
    KC_       , KC_            , KC_          , KC_          ,  KC_          , TG(REVERT)    ,
KC_  ,KC_  ,KC_  ,KC_  ,KC_  ,KC_  ,KC_  ,
KC_  ,KC_  ,KC_  ,KC_  ,KC_  ,
    // right thumb
    KC_            , KC_            ,
    KC_            , KC_            , KC_CAPSLOCK  ,
    KC_            , KC_PGUP        , KC_PGDN
    )              ,
// ALT-funtions keys and numbers on right hand
[NUM] = KEYMAP_80(
    // left hand
    LALT(KC_ESC)            , LALT(KC_F1)           , LALT(KC_F2)         , LALT(KC_F3)         , LALT(KC_F4)          , KC_        , KC_        ,
    KC_            , LALT(KC_F5)           , LALT(KC_F6)         , LALT(KC_F7)         , LALT(KC_F8)          , KC_  , KC_  ,
    KC_            , LALT(KC_F9)           , LALT(KC_F10)        , LALT(KC_F11)         , LALT(KC_F12)       , KC_    ,
    KC_            , KC_          , KC_        , KC_        ,  KC_   ,    KC_  , KC_  ,
KC_  ,KC_  ,KC_  ,KC_  ,KC_  ,  
    //left thumb
    KC_            , KC_            ,
    KC_            , KC_            , KC_POWER     ,
    KC_HOME        , KC_END         , KC_          ,
    // right hand
    KC_          , KC_NUMLOCK         , KC_        , KC_       , KC_       , KC_       , KC_          ,
KC_  ,KC_KP_6  ,KC_KP_7  ,KC_KP_8  ,KC_KP_9  ,KC_KP_0  ,KC_4  ,
    KC_KP_1       , KC_KP_2            , KC_KP_3          , KC_KP_4          ,  KC_KP_5          , KC_5    ,
KC_  , RALT(KC_4)  ,RALT(KC_5)  , RALT(BP_Y)  , RALT(BP_X)  ,RALT(BP_A_GRAVE)  ,SFT_T(KC_KP_COMMA)  ,
KC_  ,KC_  ,KC_  ,KC_  ,KC_  ,
    // right thumb
    KC_            , KC_            ,
    KC_            , KC_            , KC_CAPSLOCK  ,
    KC_            , KC_PGUP        , KC_PGDN
    )              ,
};
