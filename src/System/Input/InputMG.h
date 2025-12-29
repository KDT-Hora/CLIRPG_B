#pragma once

#include "conio.h"
#include "vector"
#include "../../singleton.h"


//  入力管理クラス
class InputMG 
{

    InputMG()noexcept
        = default;
    ~InputMG()noexcept
        = default;

public:

    static InputMG& Instance()
    {
        static InputMG instance;
        return instance;
    }
    InputMG(const InputMG&) = delete;
    InputMG& operator=(const InputMG&) = delete;

    enum Key {
        NONE = 0,
        UP, DOWN, LEFT, RIGHT,
        ENTER, CANCEL,
        KEY_COUNT
    };

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
                // 移動
                case 'w': currentKey = UP; break;    // W
                case 's': currentKey = DOWN; break;  // S
                case 'a': currentKey = LEFT; break;  // A
                case 'd': currentKey = RIGHT; break; // D

                case 13: currentKey = ENTER; break; // Enter
                case 27: currentKey = CANCEL; break; // Esc
                case 'z': currentKey = ENTER; break;
                case 'x': currentKey = CANCEL; break;
                }
            }
        }
    }

    Key GetKey() { return currentKey; }
    bool ChechKey(Key key)
    {
        if (key == currentKey)
        {
            return true;
        }
        return false;
    }

private:

    Key currentKey = Key::NONE;


};
