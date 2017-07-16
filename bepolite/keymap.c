#include "ergodox.h"
#include "debug.h"
#include "keymap_bepo.h"
/*#include "keymap_french.h"*/

// 
#define BASE 0 // default layer
#define FL 1 // symbols

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
 * lft dn up rght = arrows =  Left Down Up Right
 *
 * Sft Spce BSpc Ent = Shift Space BackSpace Enter
 *
 * tab |<- = BackTab (Shift-Tab)
 * 
 * Why CapsLock (CLock) ? for people who use it , as shift lock or as a modifier key...
 *
 * The keys can be associated to one character (typing) and one {modifier} (pressing).
 * This is the case for the keys :  Ç { Shift };  Down { Control };  Space { Functions layer }
 *
 * ------------------------------------------.  Base .--------------------------------------------.
 * ,------.----.----.----.----.----.----.      Layout     ,----.----.----.----.----.----.------.  |
 * ¦Esc   ¦ "  ¦  « ¦ »  ¦ (  ¦ )  ¦ $  ¦\       |       /¦ %  ¦ @  ¦ +  ¦ -  ¦ /  ¦ *  ¦ =    ¦  |
 * \------\----\----\----\----\----\----¦        |        ¦----/----/----/----/----/----/------/  |
 * ¦Tab   ¦ B  ¦ É  ¦ P  ¦ O  ¦ È  ¦tab ¦\       |       /¦BSpc¦ ^  ¦ V  ¦ D  ¦ L  ¦ J  ¦ Z    ¦  |
 * \------\----\----\----\----\----¦|<- ¦        |        ¦    ¦----/----/----/----/----/------/  |
 * ¦  W   ¦ A  ¦ U  ¦ I  ¦ E  ¦ ,  ¦----¦        |        ¦____¦ C  ¦ T  ¦ S  ¦ R  ¦ N  ¦ M    ¦  |
 * \------\----\----\----\----\----¦tab ¦\       |       /¦    ¦----/----/----/----/----/------/  |
 * ¦Shift ¦ À  ¦ Y  ¦ X  ¦ .  ¦ K  ¦ ->|¦        |        ¦Ent ¦ '  ¦ Q  ¦ G  ¦ H  ¦ F  ¦ Ç Sft¦  |
 * \------\----\----\----\----\----\----'\       |       /'----/----/----/----/----/----/#-----/  |
 *   ¦Ctrl¦Ctrl¦LGui¦LGui¦Alt ¦   ______.____.   |   .____._____.   ¦Spce¦Home¦ End¦PgUp¦PgDn¦    |
 *   \----\----\----\----\----\  /CLock/Print/\     /\ Esc \ up  \  /#Sft/----/----/----/----/    |
 *                        ______/_____/_____/         \_____\_____\______   ----------------------'
 *                       /Space/     /Menu /\         /\ lft \ dn  \ rght\  \--------------------/
 *                      / L1  / Shft/ Ctrl/             \     \     \     \  \
 *                     /#____/_____/#____/               \_____\_____\_____\  \
 *                    /Space/ Ins / Del /\   /       \   /\ BSpc\ lft \     \  \
 *                   /     / Alt / Gui /    /         \    \ Gui \ Ctrl\ AlGr\  \
 *                  /_____/#____/#____/    /           \    \#____\#____\_____\  \
 *                  \     \     \     \   /             \   /     /     /     /   \
 *                                       /               \                         \
 *                  --------------------'                 '------------------------'
 *                     ----------------- \                 / ---------------------/
 *               D __    L                    right                                  D __    L
 *          T  __ |  |.--.  N         up        __      space (Shift)           T  __ |  |.--.  N
 *            |  ||  ||  |.-.              .--. \  \ .--.                         |  ||  ||  |.-.
 *            |  ||  ||  || |         down  \  \ \  \ \  \  .-. home              |  ||  ||  || |
 *  space   _ |  ||  ||  || |                \  \ |  | )  ) ) )       left| altgr |  ||  ||  || |
 *         | \|  ''  ''  '' |       left  _   \  \|  |/  / / /               _    |  ''  ''  '' |
 *         |  |  ''  ''  '' |            | \   |            |               | \   |  ''  ''  '' |
 *         |  |             |            |  \  |            |               |  \  |             |
 *         |                |             \  \ |            |                \  \ |             |
 *          \               |              \  ''            |                 \  ''             |
 *           \              |               \              /                   \                |
 *            \            /                 \            /                     \              /
 *        -- not using arrows --           -- using arrows  --                 -- intermediate  --
 *                 up
 *                down
 *                 __    right
 *       left  __ |  |.--.  space
 *            |  ||  ||  |.-.
 *  backspace |  ||  ||  || |
 *          _ |  ||  ||  || |
 *         | \|  ''  ''  '' |
 *         |  |  ''  ''  '' |
 *         |  |             |
 *         |                |
 *          \               |
 *           \              |
 *            \            /
 *        -- only using arrows --
 *      ( you need to move the hand)
 *
 *
 *
 * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 * The second row filled with Alt- means it add the modifier Alt- to the keys upper.
 * -> Alt-Escape; Alt-F1; Alt-F2 ... Alt-F12
 *
 * ----------------------------------------- Functions -------------------------------------------.
 * ,------.----.----.----.----.----.----.      Layout     ,----.----.----.----.----.----.------.  |
 * ¦Esc   ¦ F1 ¦ F2 ¦ F3 ¦ F4 ¦ F5 ¦ F6 ¦\       |       /¦ F7 ¦ F8 ¦ F9 ¦ F10¦ F11¦ F12¦      ¦  |
 * \------\----\----\----\----\----\----¦        |        ¦----/----/----/----/----/----/------/  |
 * ¦Alt-  ¦Alt-¦Alt-¦Alt-¦Alt-¦Alt-¦Alt-¦\       |       /¦Alt-¦Alt-¦Alt-¦Alt-¦Alt-¦Alt-¦      ¦  |
 * \------\----\----\----\----\----¦    ¦        |        ¦    ¦----/----/----/----/----/------/  |
 * ¦      ¦    ¦    ¦    ¦    ¦    ¦----¦        |        ¦____¦    ¦    ¦    ¦    ¦    ¦      ¦  |
 * \------\----\----\----\----\----¦    ¦\       |       /¦    ¦----/----/----/----/----/------/  |
 * ¦      ¦    ¦         ¦    ¦    ¦    ¦        |        ¦    ¦    ¦    ¦    ¦    ¦    ¦      ¦  |
 * \------\----\----\----\----\----\----'\       |       /'----/----/----/----/----/----/------/  |
 *   ¦    ¦    ¦    ¦    ¦    ¦   ______.____.   |   .____._____.   ¦    ¦    ¦    ¦    ¦    ¦    |
 *   \----\----\----\----\----\  /     /     /\  |  /\     \ up  \  /----/----/----/----/----/    |
 *                        ______/_____/_____/    |    \_____\_____\______   ----------------------'
 *                       /#####/     /     /\    |    /\     \ lft \ rght\  \--------------------/
 *                      /#####/     /MIDI?/      |      \     \     \     \  \
 *                     /_____/_____/_____/       |       \_____\_____\_____\  \
 *                    /     /#####/     /\   /   |   \   /\     \ dn  \     \  \
 *                   /     /#####/     /    /    |    \    \     \ Ctrl\ AlGr\  \
 *                  /_____/_____/_____/    /     |     \    \_____\_____\_____\  \
 *                  \     \     \     \   /      |      \   /     /     /     /   \
 *                                       /       |       \                         \
 *                  --------------------'        |        '------------------------'
 *                     ----------------- \       |       / -----------------------/
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * *
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_* 
[BASE] = KEYMAP_80(  // layer 0 : default
 // left hand
 KC_ESC    , KC_1       , KC_2       , KC_3    , KC_4      , KC_5       , BP_DOLLAR    ,
 KC_TAB    , BP_B       , BP_E_ACUTE , BP_P    , BP_O      , BP_E_GRAVE , LSFT(KC_TAB) ,
 BP_W      , BP_A       , BP_U     , BP_I    , BP_E      , BP_COMMA   ,
 KC_LSHIFT , BP_A_GRAVE , BP_Y       , BP_X    , BP_DOT    , BP_K       , KC_TAB       ,
 KC_LCTL   , BP_PERCENT , BP_DOLLAR  ,KC_LEFT    , KC_RIGHT , 
          KC_UP    ,  KC_CAPSLOCK ,
          LT(FL,KC_ESC) , ALT_T(KC_DOWN), GUI_T(KC_MENU),
  CTL_T(KC_SPC)  , ALT_T(KC_INS), GUI_T(KC_DEL),
 // right hand
 BP_PERCENT             , KC_6    , KC_7   , KC_8    , KC_9    , KC_0 , KC_MINS        ,
 KC_BSPC                , KC_Y    , BP_V   , BP_D    , BP_L    , BP_J , BP_Z           ,
 BP_C                   , LT(FL,BP_T)    , CTL_T(BP_S)   , ALT_T(BP_R)    , GUI_T(BP_N)    , BP_M ,
 KC_ENT                 , BP_APOS , BP_Q   , BP_G    , BP_H    , BP_F , SFT_T(BP_CCED) ,
               SFT_T(KC_UP) , KC_DOWN , ALT_T(KC_SPC) , KC_ESC , KC_INS ,
KC_ESC        , KC_UP,
KC_LEFT         ,KC_DOWN  , KC_RIGHT,
GUI_T(KC_BSPC) , CTL_T(KC_ENT) , RALT_T(KC_SPC)
                ),
 
// Funtions keys 
[FL] = KEYMAP_80(
       // left hand
       KC_TRNS , KC_F1  , KC_F2  , KC_F3  , KC_F4 , KC_F5 , KC_F6  ,
       LALT(KC_ESC),   LALT(KC_F1),   LALT(KC_F2),   LALT(KC_F3),    LALT(KC_F4),   LALT(KC_F5),   LALT(KC_F6),
       KC_TRNS , KC_TRNS   ,KC_TRNS , KC_TRNS, KC_TRNS, KC_TAB, 
       KC_TRNS , KC_F1  , KC_F2  , KC_F3  , KC_F4 , KC_F5 , KC_F6  ,
       KC_TRNS , KC_TRNS , KC_TRNS , KC_HOME , KC_END ,
	     		                 	KC_TRNS , KC_TRNS ,
								KC_TRNS         , KC_TRNS , KC_TRNS ,
								KC_TRNS         , KC_TRNS , KC_TRNS ,
       // right hand
       KC_F7      , KC_F8     , KC_F9 , KC_F10 , KC_F11  , KC_F12     , KC_TRNS    ,
       LALT(KC_F7), LALT(KC_F8), LALT(KC_F9),LALT(KC_F10),LALT(KC_F11), LALT(KC_F12), KC_TRNS,
                      KC_TAB    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS,
       KC_F7      , KC_F8     , KC_F9 , KC_F10 , KC_F11  , KC_F12     , KC_TRNS    ,
                             KC_PGUP, KC_PGDN   , KC_TRNS  , KC_TRNS , KC_TRNS ,
       KC_TRNS      , KC_TRNS  ,     
       KC_TRNS      , KC_TRNS       , KC_TRNS ,
       KC_TRNS      , KC_TRNS       , KC_TRNS
),
};
