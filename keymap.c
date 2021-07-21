#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum tap_dance_codes {
  DANCE_Q,
  DANCE_J,
  DANCE_V,
  DANCE_K,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
  _LAYER7,
  _LAYER8,
  _LAYER9,
  _LAYER10,
  _LAYER11,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define TD_Q TD(DANCE_Q)
#define TD_J TD(DANCE_J)
#define TD_V TD(DANCE_V)
#define TD_K TD(DANCE_K)

#define TRNS KC_TRANSPARENT
#define NONE KC_NO

#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LSFT_T(KC_T)

#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I LALT_T(KC_I)
#define HM_O RGUI_T(KC_O)

#define BS_X RALT_T(KC_X)
#define BS_M LT(10,KC_M)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    TD_Q, KC_W, KC_F, KC_P, KC_G, TRNS, TRNS, TD_J, KC_L, KC_U, KC_Y, KC_QUOTE,       
    HM_A, HM_R, HM_S, HM_T, KC_D, TRNS, TRNS, KC_H, HM_N, HM_E, HM_I, HM_O,   
    KC_Z, BS_X, KC_C, TD_V, KC_B, TRNS, TRNS, TD_K, BS_M,    KC_COMMA,       RALT_T(KC_DOT), KC_SLASH,       
    TRNS, TRNS, LT(9,KC_DELETE),LT(7,KC_BSPACE),LT(8,KC_ENTER), TRNS, NONE,          LT(5,KC_TAB),   LT(4,KC_SPACE), LT(6,KC_ESCAPE),TRNS, TRNS
  ),

  [_LOWER] = LAYOUT_planck_grid(
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, NONE,          TRNS, TRNS, TRNS, TRNS, TRNS
  ),

  [_RAISE] = LAYOUT_planck_grid(
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, NONE,          TRNS, TRNS, TRNS, TRNS, TRNS
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, NONE,          TRNS, TRNS, TRNS, TRNS, TRNS
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_INSERT,      TRNS, TRNS, NONE,          NONE,          NONE,          WEBUSB_PAIR,    RESET,          
    KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_CAPSLOCK,    TRNS, TRNS, NONE,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        
    KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    LCTL(KC_Y),     TRNS, TRNS, NONE,          NONE,          NONE,          KC_RALT,        NONE,          
    TRNS, TRNS, KC_DELETE,      KC_BSPACE,      KC_ENTER,       TRNS, NONE,          NONE,          TRNS, NONE,          TRNS, TRNS
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, NONE,          TRNS, TRNS, NONE,          NONE,          NONE,          WEBUSB_PAIR,    RESET,          
    KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    NONE,          TRNS, TRNS, NONE,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        
    KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    LCTL(KC_Y),     TRNS, TRNS, NONE,          NONE,          NONE,          KC_RALT,        NONE,          
    TRNS, TRNS, KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,     TRNS, NONE,          TRNS, NONE,          NONE,          TRNS, TRNS
  ),

  [_LAYER6] = LAYOUT_planck_grid(
    RGB_VAI,        RGB_SPD,        KC_AUDIO_VOL_UP,RGB_SPI,        NONE,          TRNS, TRNS, NONE,          NONE,          NONE,          WEBUSB_PAIR,    RESET,          
    RGB_VAD,        KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_MEDIA_NEXT_TRACK,NONE,          TRNS, TRNS, NONE,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        
    RGB_TOG,        RGB_MOD,        RGB_HUD,        RGB_HUI,        RGB_MOD,        TRNS, TRNS, NONE,          NONE,          NONE,          KC_RALT,        NONE,          
    TRNS, TRNS, KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  TRNS, NONE,          NONE,          NONE,          TRNS, TRNS, TRNS
  ),

  [_LAYER7] = LAYOUT_planck_grid(
    RESET,          WEBUSB_PAIR,    NONE,          NONE,          NONE,          TRNS, TRNS, KC_LBRACKET,    KC_7,           KC_8,           KC_9,           KC_RBRACKET,    
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      NONE,          TRNS, TRNS, KC_EQUAL,       KC_4,           KC_5,           KC_6,           KC_SCOLON,      
    NONE,          KC_RALT,        NONE,          NONE,          NONE,          TRNS, TRNS, KC_BSLASH,      KC_1,           KC_2,           KC_3,           KC_GRAVE,       
    TRNS, TRNS, NONE,          TRNS, NONE,          TRNS, NONE,          KC_MINUS,       KC_0,           KC_DOT,         TRNS, TRNS
  ),

  [_LAYER8] = LAYOUT_planck_grid(
    RESET,          WEBUSB_PAIR,    NONE,          NONE,          NONE,          TRNS, TRNS, KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      NONE,          TRNS, TRNS, KC_PLUS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_COLN,        
    NONE,          KC_RALT,        NONE,          NONE,          NONE,          TRNS, TRNS, KC_PIPE,        KC_EXLM,        KC_AT,          KC_HASH,        KC_TILD,        
    TRNS, TRNS, NONE,          NONE,          TRNS, TRNS, NONE,          KC_UNDS,        KC_LPRN,        KC_RPRN,        TRNS, TRNS
  ),

  [_LAYER9] = LAYOUT_planck_grid(
    RESET,          WEBUSB_PAIR,    NONE,          NONE,          NONE,          TRNS, TRNS, KC_PSCREEN,     KC_F7,          KC_F8,          KC_F9,          KC_F12,         
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      NONE,          TRNS, TRNS, KC_SCROLLLOCK,  KC_F4,          KC_F5,          KC_F6,          KC_F11,         
    NONE,          KC_RALT,        NONE,          NONE,          NONE,          TRNS, TRNS, KC_PAUSE,       KC_F1,          KC_F2,          KC_F3,          KC_F10,         
    TRNS, TRNS, TRNS, NONE,          NONE,          TRNS, NONE,          KC_TAB,         KC_SPACE,       KC_APPLICATION, TRNS, TRNS
  ),

  [_LAYER10] = LAYOUT_planck_grid(
    LALT(LSFT(KC_1)),LALT(LSFT(KC_2)),LALT(LSFT(KC_3)),LALT(LSFT(KC_4)),LALT(LSFT(KC_5)),TRNS, TRNS, NONE,          NONE,          NONE,          NONE,          NONE,          
    LALT(KC_1),     LALT(KC_2),     LALT(KC_3),     LALT(KC_4),     LALT(KC_5),     TRNS, TRNS, NONE,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        
    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TRNS, TRNS, NONE,          TRNS, NONE,          NONE,          NONE,          
    TRNS, TRNS, NONE,          KC_APPLICATION, NONE,          TRNS, NONE,          NONE,          NONE,          NONE,          TRNS, TRNS
  ),

  [_LAYER11] = LAYOUT_planck_grid(
    NONE,          NONE,          NONE,          NONE,          NONE,          TRNS, TRNS, LALT(LSFT(KC_6)),LALT(LSFT(KC_7)),LALT(LSFT(KC_8)),LALT(LSFT(KC_9)),LALT(LSFT(KC_0)),
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      NONE,          TRNS, TRNS, LALT(KC_6),     LALT(KC_7),     LALT(KC_8),     LALT(KC_9),     LALT(KC_0),     
    NONE,          NONE,          NONE,          TRNS, NONE,          TRNS, TRNS, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           
    TRNS, TRNS, NONE,          NONE,          NONE,          TRNS, NONE,          NONE,          KC_APPLICATION, NONE,          TRNS, TRNS
  ),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [4] = { {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252}, {130,117,252} },

    [5] = { {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255}, {40,218,255} },

    [6] = { {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255}, {205,119,255} },

    [7] = { {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233}, {162,178,233} },

    [8] = { {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232}, {63,189,232} },

    [9] = { {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230}, {8,191,230} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case RGB_SLD:
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;
  case HM_T:
        /*
        This piece of code nullifies the effect of Left Shift when
        tapping the LCTL_T(KC_T) key.
        This helps rolling over LSFT_T(KC_S) and LCTL_T(KC_T)
        to obtain the intended "st" instead of "T".
        Consequently, capital T can only be obtained by tapping LCTL_T(KC_T)
        and holding RSFT_T(KC_E) (which is the right Shift mod tap).
        */

        if (record->tap.count > 0) {
            if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                unregister_mods(MOD_BIT(KC_LSHIFT));
                tap_code(KC_S);
                tap_code(KC_T);
                add_mods(MOD_BIT(KC_LSHIFT));
                return false;
            }
        }
         /*else process LCTL_T(KC_T) as usual.*/
        return true;
  case HM_N:
    /*
      This piece of code nullifies the effect of Right Shift when tapping
      the RCTL_T(KC_N) key.
      This helps rolling over RSFT_T(KC_E) and RCTL_T(KC_N)
      to obtain the intended "en" instead of "N".
      Consequently, capital N can only be obtained by tapping RCTL_T(KC_N)
      and holding LSFT_T(KC_S) (which is the left Shift mod tap).
    */

    /*
      Detect the tap.
      We're only interested in overriding the tap behaviour
      in a certain cicumstance. The hold behaviour can stay the same.
    */
    if (record->tap.count > 0) {
      // Detect right Shift
      if (get_mods() & MOD_BIT(KC_RSHIFT)) {
	// temporarily disable right Shift
	// so that we can send KC_E and KC_N
	// without Shift on.
	unregister_mods(MOD_BIT(KC_RSHIFT));
	tap_code(KC_E);
	tap_code(KC_N);
	// restore the mod state
	add_mods(MOD_BIT(KC_RSHIFT));
	// to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
	return false;
      }
    }
    /*else process RCTL_T(KC_N) as usual.*/
    return true;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[4];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_q(qk_tap_dance_state_t *state, void *user_data);
void dance_q_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_q_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_q(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if(state->count > 3) {
        tap_code16(KC_Q);
    }
}

void dance_q_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_L)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
    }
}

void dance_q_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_L)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Q); break;
    }
    dance_state[0].step = 0;
}
void on_dance_j(qk_tap_dance_state_t *state, void *user_data);
void dance_j_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_j_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_j(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if(state->count > 3) {
        tap_code16(KC_J);
    }
}

void dance_j_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_J); break;
        case DOUBLE_TAP: register_code16(KC_LGUI); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
    }
}

void dance_j_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_J); break;
        case DOUBLE_TAP: unregister_code16(KC_LGUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_J); break;
    }
    dance_state[1].step = 0;
}
void on_dance_v(qk_tap_dance_state_t *state, void *user_data);
void dance_v_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_v_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_v(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_v_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: layer_on(11); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_v_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: layer_off(11); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[2].step = 0;
}
void on_dance_k(qk_tap_dance_state_t *state, void *user_data);
void dance_k_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_k_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_k(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count >= 3) {
      tap_code16(KC_APPLICATION);
      for (uint8_t i = 2; i < state->count; i++) {
        tap_code16(KC_K);
      }
    }
}

void dance_k_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void dance_k_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[3].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_q, dance_q_finished, dance_q_reset),
        [DANCE_J] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_j, dance_j_finished, dance_j_reset),
        [DANCE_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_v, dance_v_finished, dance_v_reset),
        [DANCE_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_k, dance_k_finished, dance_k_reset),
};

