#ifndef _HEADER_TAP_DANCE
#define _HEADER_TAP_DANCE

#include QMK_KEYBOARD_H

// タップダンスで使うキーを定義
// 命名規則は
// * TD_A_Bなら1回でA、2回でBとする。
// * TD_A@B_C なら1回でA、1回目長押しでB、2回でCとする。
enum {
	TD_HOMEhMHEN = 0,
	TD_ENDhHENK,
	TD_ESChL1,
	TD_TABhL2,
	TD_INSERThL3,
	TD_ALThL4,
	TD_J_ESC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[ TD_HOMEhMHEN ] = ACTION_TAP_DANCE_DOUBLE( KC_HOME, KC_MHEN ),
	[ TD_ENDhHENK ]  = ACTION_TAP_DANCE_DOUBLE( KC_END, KC_HENK ),
	[ TD_ESChL1 ]    = ACTION_TAP_DANCE_DOUBLE( KC_ESC, L1 ),
	[ TD_TABhL2 ]    = ACTION_TAP_DANCE_DOUBLE( KC_TAB, L2 ),
	[ TD_INSERThL3 ] = ACTION_TAP_DANCE_DOUBLE( KC_INS, L3 ),
	[ TD_ALThL4 ]    = ACTION_TAP_DANCE_DOUBLE( KC_LALT, L4 ),
	[ TD_J_ESC ]     = ACTION_TAP_DANCE_DOUBLE( KC_J, KC_ESC ),
};

// タップダンスでキーが発動したときの処理？
void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->keycode) {
		case TD(TD_J_ESC):
			if (state->count == 1) {
				register_code (KC_J);
			} else if (state->count == 2) {
				register_code (KC_ESC);
			}
			break;
		//case TD(TD_SCLN_COLN):
		//	if (state->count == 1) {
		//		register_code (KC_SCLN);
		//	} else if (state->count == 2) {
		//		register_code (KC_LSFT);
		//		register_code (KC_SCLN);
		//	}
		//	break;
	}
}

// タップダンスでキーが解放されたときの処理？
void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->keycode) {
		case TD(TD_J_ESC):
			if (state->count == 1) {
				unregister_code (KC_J);
			} else if (state->count == 2) {
				unregister_code (KC_ESC);
			}
			break;
		//case TD(TD_SCLN_COLN):
		//	if (state->count == 1) {
		//		unregister_code (KC_SCLN);
		//	} else if (state->count == 2) {
		//		unregister_code (KC_LSFT);
		//		unregister_code (KC_SCLN);
		//	}
		//	break;
	}
}

#endif
