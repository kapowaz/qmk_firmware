/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT,
  KAP_DEAL_WITH_IT,
  KAP_THUMB_UP,
  KAP_THUMB_DOWN,
  KAP_FINGERS_CROSSED,
  KAP_THINKING,
  KAP_JOY,
  KAP_CRYING,
  KAP_WINKING,
  KAP_SWEAT_SMILE,
  KAP_HEART_EYES,
  KAP_MIND_BLOWN,
  KAP_APPROVES,
  KAP_DISAPPROVES,
  KAP_SURPRISED,
  KAP_SHUSH,
  KAP_SHRUGGING,
  KAP_PRAYING,
  KAP_RAISING_HAND,
  KAP_TIPPING_HAND,
  KAP_FACEPALM,
  KAP_FACEMASK,
  KAP_CELEBRATE,
  KAP_ROLLING_EYES,
  KAP_SANTA,
  NEDRY,
  GEORDI_NO,
  GEORDI_YES,
  BEN_APPROVES,
  NICE,
  THONK,
  NOTSUREIF,
  CHEFSKISS,
  CHOPPYBOI,
  THIS,
  SAME,
  YES,
  NOPE,
  PLS,
  BABY_YODA_HIDE,
  JAZZ_CLUB,
  DRIFTER_OOOH,
  ANDYDWYER,
  DISAPPEAR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_preonic_grid(
  KAP_DEAL_WITH_IT,     KAP_JOY,            KAP_MIND_BLOWN,     KAP_SHRUGGING,      KAP_FACEMASK,       KC_NO,   KC_NO,   KC_NO,   NEDRY,          NICE,       THIS,   BABY_YODA_HIDE,
  KAP_THUMB_UP,         KAP_CRYING,         KAP_APPROVES,       KAP_PRAYING,        KAP_CELEBRATE,      KC_NO,   KC_NO,   KC_NO,   GEORDI_NO,      THONK,      SAME,   JAZZ_CLUB,
  KAP_THUMB_DOWN,       KAP_WINKING,        KAP_DISAPPROVES,    KAP_RAISING_HAND,   KAP_ROLLING_EYES,   KC_NO,   KC_NO,   KC_NO,   GEORDI_YES,     NOTSUREIF,  YES,    DRIFTER_OOOH,
  KAP_FINGERS_CROSSED,  KAP_SWEAT_SMILE,    KAP_SURPRISED,      KAP_TIPPING_HAND,   KAP_SANTA,          KC_NO,   KC_NO,   KC_NO,   BEN_APPROVES,   CHEFSKISS,  NOPE,   ANDYDWYER,
  KAP_THINKING,         KAP_HEART_EYES,     KAP_SHUSH,          KAP_FACEPALM,       LOWER,              _______, _______, RAISE,   KC_NO,          CHOPPYBOI,  PLS,    DISAPPEAR
),

[_LOWER] = LAYOUT_preonic_grid(
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  _______,    KC_ENT, KC_ENT, _______,    KC_NO,  KC_NO,  KC_NO,  KC_NO
),

[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|Clk togg|      |      |      |      |      |      |     |  Del|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |       |      |     |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|Ck_togg|      |      |      |     |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |       |     |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   CK_TOGG, _______, _______, _______, _______, _______,_______,  _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, QWERTY,  _______, _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

const char* get_emoji_from_keycode(int keycode) {
    switch (keycode) {
        case KAP_DEAL_WITH_IT:
            return ":kap_deal_with_it:";
        case KAP_THUMB_UP:
            return ":kap_thumb_up:";
        case KAP_THUMB_DOWN:
            return ":kap_thumb_down:";
        case KAP_FINGERS_CROSSED:
            return ":kap_fingers_crossed:";
        case KAP_THINKING:
            return ":kap_thinking:";
        case KAP_JOY:
            return ":kap_joy:";
        case KAP_CRYING:
            return ":kap_crying:";
        case KAP_WINKING:
            return ":kap_winking:";
        case KAP_SWEAT_SMILE:
            return ":kap_sweat_smile:";
        case KAP_HEART_EYES:
            return ":kap_heart_eyes:";
        case KAP_MIND_BLOWN:
            return ":kap_mind_blown:";
        case KAP_APPROVES:
            return ":kap_approves:";
        case KAP_DISAPPROVES:
            return ":kap_disapproves:";
        case KAP_SURPRISED:
            return ":kap_surprised:";
        case KAP_SHUSH:
            return ":kap_shush:";
        case KAP_SHRUGGING:
            return ":kap_shrugging:";
        case KAP_PRAYING:
            return ":kap_praying:";
        case KAP_RAISING_HAND:
            return ":kap_raising_hand:";
        case KAP_TIPPING_HAND:
            return ":kap_tipping_hand:";
        case KAP_FACEPALM:
            return ":kap_facepalm:";
        case KAP_FACEMASK:
            return ":kap_facemask:";
        case KAP_CELEBRATE:
            return ":kap_celebrate:";
        case KAP_ROLLING_EYES:
            return ":kap_rolling_eyes:";
        case KAP_SANTA:
            return ":kap_santa:";
        case NEDRY:
            return ":nedry:";
        case GEORDI_NO:
            return ":geordi_no:";
        case GEORDI_YES:
            return ":geordi_yes:";
        case BEN_APPROVES:
            return ":ben_approves:";
        case NICE:
            return ":noice:";
        case THONK:
            return ":thonk:";
        case NOTSUREIF:
            return ":notsureif:";
        case CHEFSKISS:
            return ":chefskiss:";
        case CHOPPYBOI:
            return ":choppyboi:";
        case THIS:
            return ":this:";
        case SAME:
            return ":same:";
        case YES:
            return ":yes:";
        case NOPE:
            return ":nope:";
        case PLS:
            return ":pls:";
        case BABY_YODA_HIDE:
            return ":baby_yoda_hide:";
        case JAZZ_CLUB:
            return ":jazz_club:";
        case DRIFTER_OOOH:
            return ":oooh:";
        case ANDYDWYER:
            return ":andydwyer:";
        case DISAPPEAR:
            return ":disappear:";
    }
    return "";
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        static uint16_t key_timer;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case KAP_DEAL_WITH_IT:
        case KAP_THUMB_UP:
        case KAP_THUMB_DOWN:
        case KAP_FINGERS_CROSSED:
        case KAP_THINKING:
        case KAP_JOY:
        case KAP_CRYING:
        case KAP_WINKING:
        case KAP_SWEAT_SMILE:
        case KAP_HEART_EYES:
        case KAP_MIND_BLOWN:
        case KAP_APPROVES:
        case KAP_DISAPPROVES:
        case KAP_SURPRISED:
        case KAP_SHUSH:
        case KAP_SHRUGGING:
        case KAP_PRAYING:
        case KAP_RAISING_HAND:
        case KAP_TIPPING_HAND:
        case KAP_FACEPALM:
        case KAP_FACEMASK:
        case KAP_CELEBRATE:
        case KAP_ROLLING_EYES:
        case KAP_SANTA:
        case NEDRY:
        case GEORDI_NO:
        case GEORDI_YES:
        case BEN_APPROVES:
        case NICE:
        case THONK:
        case NOTSUREIF:
        case CHEFSKISS:
        case CHOPPYBOI:
        case THIS:
        case SAME:
        case YES:
        case NOPE:
        case PLS:
        case BABY_YODA_HIDE:
        case JAZZ_CLUB:
        case DRIFTER_OOOH:
        case ANDYDWYER:
        case DISAPPEAR:
            if (record->event.pressed) {
                // when keycode is pressed start a timer
                key_timer = timer_read();
                SEND_STRING(get_emoji_from_keycode(keycode));
            } else if (timer_elapsed(key_timer) > 600) {
                // when keycode is released after being held for timer time append enter key
                tap_code(KC_ENT);
            }
            break;
    }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
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
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
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
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
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
