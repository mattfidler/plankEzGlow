bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case RGB_SLD:
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;
#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LSFT_T(KC_T)

#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I RALT_T(KC_I)
#define HM_O RGUI_T(KC_O)
#define LYT_SPC LT(4,KC_SPACE)
#define LYT_L LT(14,KC_L)
#define LYT_U LT(2,KC_U)
#define LYT_M LT(12,KC_M)
#define LYT_F LT(1,KC_F)

    
// http://norvig.com/mayzner.html
// th = 3.56% (Alternating hand bigram)
// he = 3.07% (H is not home row)
// in = 2.43%
// er = 2.05% Alternating hand // ctrl 
// an = 1.99% Alternating hand // win n
// re = 1.85% Alternating hand // alt e
// on = 1.76%
// at = 1.49%
// en = 1.45%
// nd = 1.35% Alternating hand // D
// ti = 1.34% Alternating hand // I
// es = 1.34% Alternating hand // ctrl s
// or = 1.28% Alternating hand // run command redundant with simple windows key
// te = 1.20% Alternating hand // E
// of = 1.17% Alternating hand // win + f
// ed = 1.17% Alternating hand // ctrl d
// is = 1.13% Alternating hand // alt s
// it = 1.12% Alternating hand // alt t
// al = 1.09% Alternating hand // win l
// ar = 1.07%
// st = 1.05%
// to = 1.04% Alternating hand // O
// nt = 1.04% Alternating hand // T 
// ng = 0.95% Alternating hand // G
// se = 0.93% Alternating hand // ctrl e
// ha = 0.93% Alternating hand // non home row modifiers
// as = 0.87%
// ou = 0.87%
// io = 0.83%
// le = 0.83% no home row mods
// ve = 0.83% no home row mods
// co = 0.79% alternating hands 
// me = 0.79% no home row mods 
// de = 0.76% no howe row mods
// hi = 0.73% no home row mods
// ri = 0.73% Alternating hands alt i
// ro = 0.73% Alternating hands alt o
// ic = 0.70% Alternating hands alt c
// ne = 0.69%

// Bigrams that do not exist jq, qg, qy, qz, wq, and qz


    // common bigraphs that contain home row mods on same hand
    // ou, in, st, en
  case HM_R:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
	// or = 1.28% Alternating hand // run command redundant with simple windows key
	unregister_mods(MOD_BIT(KC_RGUI));
	tap_code(KC_O);
	tap_code(KC_R);
	add_mods(MOD_BIT(KC_RGUI));
	return false;
      } else if (get_mods() & MOD_BIT(KC_LGUI)) {
	// ar 1.07% 
	unregister_mods(MOD_BIT(KC_LGUI));
	tap_code(KC_A);
	tap_code(KC_R);
	add_mods(MOD_BIT(KC_LGUI));
	return false;
      }
    }
    return true;
  case LYT_F:
    //// of = 1.17% Alternating hand // win + f
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
	unregister_mods(MOD_BIT(KC_RGUI));
	tap_code(KC_O);
	tap_code(KC_F);
	add_mods(MOD_BIT(KC_RGUI));
	return false;
      }
    }
    return true;
  case LYT_L:
    //al = 1.09% Alternating hand
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
	unregister_mods(MOD_BIT(KC_LGUI));
	tap_code(KC_A);
	tap_code(KC_L);
	add_mods(MOD_BIT(KC_LGUI));
	return false;
      }
    }
    return true;
  case LYT_M:
    // om bigraph
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
	unregister_mods(MOD_BIT(KC_RGUI));
	tap_code(KC_O);
	tap_code(KC_M);
	add_mods(MOD_BIT(KC_RGUI));
	return false;
      } else if (get_mods() & MOD_BIT(KC_RCTL)) {
	// em bigraph
	unregister_mods(MOD_BIT(KC_RCTL));
	tap_code(KC_E);
	tap_code(KC_M);
	add_mods(MOD_BIT(KC_RCTL));
	return false;
      }
    }
    return true;
  case LYT_U:
    // handle ou case and send ou for gui right+u
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
	// ou = 0.87%
	unregister_mods(MOD_BIT(KC_RGUI));
	tap_code(KC_O);
	tap_code(KC_U);
	add_mods(MOD_BIT(KC_RGUI));
	return false;
      }
    }
    return true; 
  case HM_T:
    // handles st
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
	// handle at 1.49%
	unregister_mods(MOD_BIT(KC_LGUI));
	tap_code(KC_A);
	tap_code(KC_T);
	unregister_mods(MOD_BIT(KC_LGUI));
	return false;
      } else if (get_mods() & MOD_BIT(KC_LCTL)) {
	// handle st 1.05%
	unregister_mods(MOD_BIT(KC_LCTL));
	tap_code(KC_S);
	tap_code(KC_T);
	add_mods(MOD_BIT(KC_LCTL));
	return false;
      }
    }
    return true; 
  case HM_N:
    // handle en and in
    if (record->tap.count > 0) {
      uint8_t current_mods = get_mods();
      if (current_mods & MOD_BIT(KC_RALT)) {
	// in 2.43%
	unregister_mods(MOD_BIT(KC_RALT));
	tap_code(KC_I);
	tap_code(KC_N);
	add_mods(MOD_BIT(KC_RALT));
	return false;
      } else if (current_mods & MOD_BIT(KC_LGUI))  {
	//an = 1.99% Alternating hand
	unregister_mods(MOD_BIT(KC_LGUI));
	tap_code(KC_A);
	tap_code(KC_N);
	add_mods(MOD_BIT(KC_LGUI));
	return false;
      } else if (current_mods & MOD_BIT(KC_RGUI)) {
	// on 1.76%
	unregister_mods(MOD_BIT(KC_RGUI));
	tap_code(KC_O);
	tap_code(KC_N);
	add_mods(MOD_BIT(KC_RGUI));
	return false;
      } else if (current_mods & MOD_BIT(KC_RCTL)) {
	// en 1.45%
	unregister_mods(MOD_BIT(KC_RCTL));
	tap_code(KC_E);
	tap_code(KC_N);
	add_mods(MOD_BIT(KC_RCTL));
	return false;
      }
    }
    return true;
  case HM_S:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
	// as 0.87%
	unregister_mods(MOD_BIT(KC_LGUI));
	tap_code(KC_A);
	tap_code(KC_S);
	add_mods(MOD_BIT(KC_LGUI));
	return false;
      }
      return true;
    }
  case HM_O:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RALT)) {
	// handle io 0.83%
	unregister_mods(MOD_BIT(KC_RALT));
	tap_code(KC_I);
	tap_code(KC_O);
	add_mods(MOD_BIT(KC_RALT));
	return false;
      }
    }
    return true;
  case HM_E:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RSHIFT)) {
	// ne
	unregister_mods(MOD_BIT(KC_RSHIFT));
	tap_code(KC_N);
	tap_code(KC_E);
	add_mods(MOD_BIT(KC_RSHIFT));
	return false;
      }
    }
    return true;
  case HM_A:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RALT)) {
	// ra
	unregister_mods(MOD_BIT(KC_RALT));
	tap_code(KC_R);
	tap_code(KC_A);
	add_mods(MOD_BIT(KC_RALT));
	return false;
      }
    }
    return true;
  case LYT_SPC:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RSHIFT)) {
	// n 
	unregister_mods(MOD_BIT(KC_RSHIFT));
	tap_code(KC_N);
	tap_code(KC_SPC);
	add_mods(MOD_BIT(KC_RSHIFT));
	return false;
      } else if (get_mods() & MOD_BIT(KC_LSHIFT)) {
	// t 
	unregister_mods(MOD_BIT(KC_LSHIFT));
	tap_code(KC_T);
	tap_code(KC_SPC);
	add_mods(MOD_BIT(KC_LSHIFT));
	return false;
      }
    }
  }
  return true;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case HM_T:
  case HM_N:
    return TAPPING_TERM;
  default:
    return TAPPING_TERM + 30;
  }
}

#undef HM_A
#undef HM_R 
#undef HM_S 
#undef HM_T 
#undef HM_N
#undef HM_E 
#undef HM_I 
#undef HM_O 

