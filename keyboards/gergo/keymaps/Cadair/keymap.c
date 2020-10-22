/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define GW2 3  // gw2

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// Blank template at the bottom
enum customKeycodes {
	URL  = 1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------.                         ,-------------------------------------------.
 * | L1/ESC   |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  BKSP  |
 * |----------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | LShift   |   A  |   S  |  D   |   F  |   G  | RMB  |           | i3-1 |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |----------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | Ctl/BKSP |   Z  |   X  |   C  |   V  |   B  | LMB  |           | BKSP |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .---------.                            .------.   .-----.
 *                    | ALT/Del  |   |Super/Ent|                            | Tab  |   |BKSP |
 *                    '----------'   '---------'                            `------.   '-----
 *                                        ,-------.                      ,-------.
 *                                        | MMB   |                      | PgDn  |
 *                                 ,------|-------|                      |-------|------.
 *                                 | SYMB | NUMB  |                      | SYMB  | NUMB |
 *                                 | Space| Escape|                      | Ent   |Space |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    LT(NUMB, KC_ESC),      KC_Q,  KC_W,   KC_E,  KC_R, KC_T,                                          KC_Y,  KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_RSFT,               KC_A,  KC_S,   KC_D,  KC_F, KC_G, KC_APP,             LM(NUMB, MOD_LGUI),  KC_H,  KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    MT(MOD_LCTL, KC_BSPC), KC_Z,  KC_X,   KC_C,  KC_V, KC_B, KC_BTN1,  KC_BTN3,  KC_PGDN, KC_BSPC,    KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,

    MT(MOD_LALT, KC_DEL),  MT(MOD_LGUI, KC_ENT), LT(SYMB, KC_SPC), LT(NUMB, KC_ESC),            LT(SYMB, KC_ENT), LT(NUMB, KC_SPC),  KC_TAB, KC_BSPC
    ),  

/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  "   |  £   |  $   |  %   |                         |   ^  |  &   |  *   |  (   |  )   |  ~ #   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |      |           |      |   +  |  -   |  /   |  [   |  ]   |  ' @   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  | \   |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   &  |  =   |  ,   |  {   |   }  | - _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   | DEL |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |   =   |                     |       |   ;  |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_EXLM, LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), KC_PERC,                                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,      KC_RPRN,       KC_NUHS,
    KC_TRNS, KC_NUHS, KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRV,       KC_TRNS,                          KC_TRNS, KC_PLUS, KC_MINS, KC_SLSH, KC_LBRC,      KC_RBRC,       KC_QUOT,
    KC_NUBS, KC_PERC, KC_CIRC,    KC_LBRC,    KC_RBRC,    LSFT(KC_BSLS), KC_TRNS, KC_TRNS,        KC_PGUP, KC_TRNS, KC_AMPR, KC_EQL,  KC_COMM, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_MINS,
                                           KC_TRNS,    KC_TRNS, KC_TRNS, KC_EQL,         KC_TRNS, KC_SCLN, KC_PGUP, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 *
* ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |  F12   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  |  F2  | F3   | F4   | F5   | F6   |           |      | LEFT | DOWN |  UP  | RIGHT|VolDn | VolUp  |
 * |--------+------+------+------+------+------+------|           |------|------+------+------+------+------+--------|
 * |        |  F7  |  F8  | F9   | F10  | F11  | F12  |           |      |      |      |      |      |Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_TRNS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MNXT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
    ),

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */

[GW2] = LAYOUT_gergo(
    KC_GRV,             KC_1,    KC_W,    KC_6,    KC_F5,   KC_F1,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    MT(MOD_LSFT, KC_0), KC_A,    KC_S,    KC_D,    KC_F,    KC_F2, KC_F4,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LCTL,            KC_SLSH, KC_TRNS, KC_C,    KC_R,    KC_F3, KC_I,      KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                   KC_LALT, KC_V, KC_SPC, LT(NUMB, KC_ESC),         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
