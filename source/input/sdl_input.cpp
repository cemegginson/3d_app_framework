#include "input/sdl_input.h"

SDLInput::SDLInput() {}

SDLInput::~SDLInput() {}

void SDLInput::Initialize() {
    SDL_InitSubSystem(SDL_INIT_EVENTS);

    keyboard_map_[SDLK_a] = kKeyA;
    keyboard_map_[SDLK_b] = kKeyB;
    keyboard_map_[SDLK_c] = kKeyC;
    keyboard_map_[SDLK_d] = kKeyD;
    keyboard_map_[SDLK_e] = kKeyE;
    keyboard_map_[SDLK_f] = kKeyF;
    keyboard_map_[SDLK_g] = kKeyG;
    keyboard_map_[SDLK_h] = kKeyH;
    keyboard_map_[SDLK_i] = kKeyI;
    keyboard_map_[SDLK_j] = kKeyJ;
    keyboard_map_[SDLK_k] = kKeyK;
    keyboard_map_[SDLK_l] = kKeyL;
    keyboard_map_[SDLK_m] = kKeyM;
    keyboard_map_[SDLK_n] = kKeyN;
    keyboard_map_[SDLK_o] = kKeyO;
    keyboard_map_[SDLK_p] = kKeyP;
    keyboard_map_[SDLK_q] = kKeyQ;
    keyboard_map_[SDLK_r] = kKeyR;
    keyboard_map_[SDLK_s] = kKeyS;
    keyboard_map_[SDLK_t] = kKeyT;
    keyboard_map_[SDLK_u] = kKeyU;
    keyboard_map_[SDLK_v] = kKeyV;
    keyboard_map_[SDLK_w] = kKeyW;
    keyboard_map_[SDLK_x] = kKeyX;
    keyboard_map_[SDLK_y] = kKeyY;
    keyboard_map_[SDLK_z] = kKeyZ;
    keyboard_map_[SDLK_0] = kKey0;
    keyboard_map_[SDLK_1] = kKey1;
    keyboard_map_[SDLK_2] = kKey2;
    keyboard_map_[SDLK_3] = kKey3;
    keyboard_map_[SDLK_4] = kKey4;
    keyboard_map_[SDLK_5] = kKey5;
    keyboard_map_[SDLK_6] = kKey6;
    keyboard_map_[SDLK_7] = kKey7;
    keyboard_map_[SDLK_8] = kKey8;
    keyboard_map_[SDLK_9] = kKey9;
    keyboard_map_[SDLK_BACKSPACE] = kKeyBackspace;
    keyboard_map_[SDLK_LALT] = kKeyLeftAlt;
    keyboard_map_[SDLK_LSHIFT] = kKeyLeftShift;
    keyboard_map_[SDLK_RETURN] = kKeyReturn;
    keyboard_map_[SDLK_RALT] = kKeyRightAlt;
    keyboard_map_[SDLK_RSHIFT] = kKeyRightShift;
    keyboard_map_[SDLK_TAB] = kKeyTab;
    keyboard_map_[SDLK_AMPERSAND] = kKeyAmpersand;
    keyboard_map_[SDLK_ASTERISK] = kKeyAsterisk;
    keyboard_map_[SDLK_AT] = kKeyAt;
    keyboard_map_[SDLK_BACKSLASH] = kKeyBackslash;
    keyboard_map_[SDLK_BACKQUOTE] = kKeyBackQuote;
    keyboard_map_[SDLK_CARET] = kKeyCaret;
    keyboard_map_[SDLK_COLON] = kKeyColon;
    keyboard_map_[SDLK_COMMA] = kKeyComma;
    keyboard_map_[SDLK_DOLLAR] = kKeyDollar;
    keyboard_map_[SDLK_EQUALS] = kKeyEquals;
    keyboard_map_[SDLK_EXCLAIM] = kKeyExclaim;
    keyboard_map_[SDLK_GREATER] = kKeyGreater;
    keyboard_map_[SDLK_HASH] = kKeyHash;
    keyboard_map_[SDLK_LEFTBRACKET] = kKeyLeftBracket;
    keyboard_map_[SDLK_LEFTPAREN] = kKeyLeftParen;
    keyboard_map_[SDLK_LESS] = kKeyLess;
    keyboard_map_[SDLK_MINUS] = kKeyMinus;
    keyboard_map_[SDLK_PERCENT] = kKeyPercent;
    keyboard_map_[SDLK_PERIOD] = kKeyPeriod;
    keyboard_map_[SDLK_PLUS] = kKeyPlus;
    keyboard_map_[SDLK_QUESTION] = kKeyQuestion;
    keyboard_map_[SDLK_QUOTEDBL] = kKeyDoubleQuote;
    keyboard_map_[SDLK_RIGHTBRACKET] = kKeyRightBracket;
    keyboard_map_[SDLK_RIGHTPAREN] = kKeyRightParen;
    keyboard_map_[SDLK_SEMICOLON] = kKeySemicolon;
    keyboard_map_[SDLK_UNDERSCORE] = kKeyUnderscore;

    mouse_map_[SDL_BUTTON_LEFT] = kMouseLeft;
    mouse_map_[SDL_BUTTON_MIDDLE] = kMouseMiddle;
    mouse_map_[SDL_BUTTON_RIGHT] = kMouseRight;
    mouse_map_[SDL_BUTTON_X1] = kMouse4;
    mouse_map_[SDL_BUTTON_X2] = kMouse5;

    controller_map_[SDL_CONTROLLER_BUTTON_INVALID] = kButtonInvalid;
    controller_map_[SDL_CONTROLLER_BUTTON_A] = kButtonA;
    controller_map_[SDL_CONTROLLER_BUTTON_B] = kButtonB;
    controller_map_[SDL_CONTROLLER_BUTTON_X] = kButtonX;
    controller_map_[SDL_CONTROLLER_BUTTON_Y] = kButtonY;
    controller_map_[SDL_CONTROLLER_BUTTON_BACK] = kButtonBack;
    controller_map_[SDL_CONTROLLER_BUTTON_GUIDE] = kButtonGuide;
    controller_map_[SDL_CONTROLLER_BUTTON_START] = kButtonStart;
    controller_map_[SDL_CONTROLLER_BUTTON_LEFTSTICK] = kButtonLeftStick;
    controller_map_[SDL_CONTROLLER_BUTTON_RIGHTSTICK] = kButtonRightStick;
    controller_map_[SDL_CONTROLLER_BUTTON_LEFTSHOULDER] = kButtonLeftShoulder;
    controller_map_[SDL_CONTROLLER_BUTTON_RIGHTSHOULDER] = kButtonRightShoulder;
    controller_map_[SDL_CONTROLLER_BUTTON_DPAD_UP] = kButtonDpadUp;
    controller_map_[SDL_CONTROLLER_BUTTON_DPAD_DOWN] = kButtonDpadDown;
    controller_map_[SDL_CONTROLLER_BUTTON_DPAD_LEFT] = kButtonDpadLeft;
    controller_map_[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] = kButtonDpadRight;
    controller_map_[SDL_CONTROLLER_BUTTON_MAX] = kButtonMax;
}

void SDLInput::Update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // Update the various input device classes
    }
}
