#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>
#include <memory>
#include <functional>

enum class Key : uint8_t
{
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_LEFT_CTRL,
    KEY_LEFT_SHIFT,
    KEY_ALT,
    KEY_RIGHT_CTRL,
    KEY_RIGHT_SHIFT,
    KEY_ALTGR,
    KEY_ESC,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_SPACE,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_0,
    KEY_NUMPAD_1,
    KEY_NUMPAD_2,
    KEY_NUMPAD_3,
    KEY_NUMPAD_4,
    KEY_NUMPAD_5,
    KEY_NUMPAD_6,
    KEY_NUMPAD_7,
    KEY_NUMPAD_8,
    KEY_NUMPAD_9,
    KEY_NUMPAD_0,
    KEY_NUMPAD_PLUS,
    KEY_NUMPAD_MINUS,
    KEY_NUMPAD_DIVISION,
    KEY_NUMPAD_MULTIPLICATION,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
    KEY_UP_ARROW,
    KEY_DOWN_ARROW
};

typedef std::function<void()> CallableFunction;

class Window
{
    class Implementation;
    std::unique_ptr<Implementation> pImplementation;

public:
    Window(uint16_t width = 900, uint16_t height = 900, Key closingKey = Key::KEY_ESC);
    ~Window();

    bool IsOpen();
    void BindClosingKey(Key closingKey);
    void BindCallableFunctionToKey(Key activationKey, CallableFunction toBind);

    void Clear();
    void PaintBox(uint16_t xStart, uint16_t yStart, uint16_t size, uint8_t RGBValues[3], uint16_t valueToPrint, uint8_t RGBValuesPrint[3]);
    void CreateGrid(uint8_t size);
    void Display();
    void Close();
};

#endif