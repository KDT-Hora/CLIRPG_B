#pragma once

#include "conio.h"
#include "vector"
#include "singleton.h"

namespace System {

    class InputMG :public Singleton<InputMG>
    {

        friend Singleton<InputMG>;

        enum Key {
            NONE = 0,
            UP, DOWN, LEFT, RIGHT,
            ENTER, CANCEL,
            KEY_COUNT
        };

    private:
        Key currentKey = Key::NONE;

        void Update() {
            currentKey = NONE;
            if (_kbhit()) {
                int ch = _getch();
                if (ch == 0 || ch == 224) { // 矢印キーなどの特殊キー
                    ch = _getch();
                    switch (ch) {
                    case 72: currentKey = UP; break;
                    case 80: currentKey = DOWN; break;
                    case 75: currentKey = LEFT; break;
                    case 77: currentKey = RIGHT; break;
                    }
                }
                else {
                    switch (ch) {
                    case 13: currentKey = ENTER; break; // Enter
                    case 27: currentKey = CANCEL; break; // Esc
                    case 'z': currentKey = ENTER; break;
                    case 'x': currentKey = CANCEL; break;
                    }
                }
            }
        }

        Key GetKey() { return currentKey; }

    };

}