#include "Kaleidoscope.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-TapDance.h"

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At          LSHIFT(Key_2)
#define Key_Hash        LSHIFT(Key_3)
#define Key_Dollar      LSHIFT(Key_4)
#define Key_Percent     LSHIFT(Key_5)
#define Key_Caret       LSHIFT(Key_6)
#define Key_And         LSHIFT(Key_7)
#define Key_Star        LSHIFT(Key_8)
#define Key_Underscore  LSHIFT(Key_Minus)
#define Key_Plus        LSHIFT(Key_Equals)
#define Key_Tilde       LSHIFT(Key_Backtick)
#define Key_Bar         LSHIFT(Key_Backslash)
#define Key_DoubleQuote LSHIFT(Key_Quote)
#define Key_LessThan    Key_NonUsBackslashAndPipe
#define Key_GreaterThan LSHIFT(Key_NonUsBackslashAndPipe)

// Layers
enum {
  BASE,
  SYM,
  NN,
  FN
};

// Macros
enum {
  MACRO_BASE,
  MACRO_SYM,
  MACRO_NN
};

// Tap Dance
enum {
  TD_BASE
};

KEYMAPS(
  [BASE] = KEYMAP_STACKED
  (
    Key_Q,  Key_W,  Key_E,  Key_R,  Key_T,
    Key_A,  Key_S,  Key_D,  Key_F,  Key_G,
    Key_Z,  Key_X,  Key_C,  Key_V,  Key_B,      ___,
    ___,    ___,    ___,    ___,    Key_Space,  Key_LeftControl,

                    Key_Y,         Key_U,  Key_I,      Key_O,       Key_P,
                    Key_H,         Key_J,  Key_K,      Key_L,       Key_Semicolon,
    ___,            Key_N,         Key_M,  Key_Comma,  Key_Period,  Key_Slash,
    Key_LeftShift,  M(MACRO_SYM),  ___,    ___,        ___,         ___
  ),

  [SYM] = KEYMAP_STACKED
  (
    Key_Esc,               Key_LeftBracket,  Key_RightBracket,  Key_Dollar,             Key_Percent,
    Key_LeftCurlyBracket,  Key_LeftParen,    Key_RightParen,    Key_RightCurlyBracket,  Key_Equals,
    Key_Tilde,             Key_Backtick,     Key_Bar,           Key_Underscore,         Key_Slash,    ___,
    ___,                   ___,              ___,               ___,                    Key_LeftAlt,  Key_LeftControl,

                    Key_Caret,      Key_And,    Key_Star,      Key_Quote,        Key_Backspace,
                    Key_Plus,       Key_Minus,  Key_LessThan,  Key_GreaterThan,  Key_DoubleQuote,
    ___,            Key_Backslash,  Key_At,     Key_Hash,      Key_Exclamation,  M(MACRO_NN),
    Key_LeftShift,  TD(TD_BASE),     ___,        ___,           ___,              ___
  ),

  [NN] = KEYMAP_STACKED
  (
    Key_Esc,        Key_Home,         Key_UpArrow,    Key_End,         Key_PageUp,
    Key_LeftGui,    Key_LeftArrow,    Key_DownArrow,  Key_RightArrow,  Key_PageDown,
    LockLayer(FN),  LSHIFT(Key_Tab),  Key_Tab,        Key_Enter,       Key_Delete,    ___,
    ___,            ___,              ___,            ___,             Key_LeftAlt,   Key_LeftControl,

                    Key_Semicolon,  Key_7,  Key_8,  Key_9,  Key_Backspace,
                    Key_Period,     Key_4,  Key_5,  Key_6,  Key_0,
    ___,            Key_Insert,     Key_1,  Key_2,  Key_3,  M(MACRO_NN),
    Key_LeftShift,  TD(TD_BASE),    ___,    ___,    ___,    ___
  ),

  [FN] = KEYMAP_STACKED
  (
    Key_PrintScreen,  Consumer_DisplayBrightnessDecrement,  Consumer_VolumeIncrement,  Consumer_DisplayBrightnessIncrement,  XXX,
    XXX,              Consumer_ScanPreviousTrack,           Consumer_VolumeDecrement,  Consumer_ScanNextTrack,               XXX,
    XXX,              XXX,                                  Consumer_Mute,             Consumer_PlaySlashPause,              XXX,          ___,
    ___,              ___,                                  ___,                       ___,                                  Key_LeftAlt,  Key_LeftControl,

                    XXX,         Key_F7,  Key_F8,  Key_F9,  Key_F10,
                    XXX,         Key_F4,  Key_F5,  Key_F6,  Key_F11,
    ___,            XXX,         Key_F1,  Key_F2,  Key_F3,  Key_F12,
    Key_LeftShift,  TD(TD_BASE),  ___,     ___,     ___,     ___
  )
)

KALEIDOSCOPE_INIT_PLUGINS(OneShot, Macros, TapDance);

static uint16_t nn_time   = 0;
static bool     nn_locked = false;

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  switch (macro_id) {
  case MACRO_BASE:
    if (keyToggledOn(event.state)) {
      nn_locked = false;
      Layer.deactivate(FN);
      Layer.deactivate(NN);
      Layer.deactivate(SYM);
      OneShot.cancel(true);
    }
    break;

  case MACRO_SYM:
    if (keyToggledOn(event.state)) {
      OneShot.setPending(event.addr);
      Layer.activate(SYM);
    } else if (keyToggledOff(event.state)) {
      Layer.deactivate(SYM);
      if (!nn_locked) {
        Layer.deactivate(NN);
      }
    }
    break;

  case MACRO_NN:
    if (keyToggledOn(event.state) && !Layer.isActive(NN)) {
      if (OneShot.isTemporary(KeyAddr(3, 7))) {
        OneShot.setPending(event.addr);
      }
      Layer.activate(NN);
      nn_time = kaleidoscope::Runtime.millisAtCycleStart();
    } else if (keyToggledOn(event.state) && Layer.isActive(NN)) {
      if (!kaleidoscope::Runtime.hasTimeExpired(nn_time, 1000)) {
        nn_locked = true;
      } else {
        Layer.deactivate(NN);
      }
    } else if (keyToggledOff(event.state) && Layer.isActive(NN) && OneShot.isTemporary(KeyAddr(3, 7))) {
      Layer.deactivate(NN);
    }
    break;

  default:
    break;
  }

  return MACRO_NONE;
}

void tapDanceAction(uint8_t td_id, KeyAddr key_addr, uint8_t td_count, kaleidoscope::plugin::TapDance::ActionType td_action) {
  switch (td_id) {
  case TD_BASE:
    return tapDanceActionKeys(td_count, td_action, M(MACRO_BASE), M(MACRO_BASE));
  }
}

// completely disable sticky behavior whatever the key
bool kaleidoscope::plugin::OneShot::isStickable(Key key) const {
  return false;
}

void setup() {
  OneShot.enableAutoModifiers();
  OneShot.setHoldTimeout(150);
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
