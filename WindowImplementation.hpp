#include "Window.hpp"
#include "CImg.h" 
#include <string>

#include <unordered_map>

typedef unsigned int CImgKey;

class Window::Implementation
{
private:
    uint16_t windowWidth;
    uint16_t windowHeight;

    CImgKey closingKey;

    cimg_library::CImg<unsigned char> windowCanvas;
    cimg_library::CImgDisplay windowDisplay;

    CImgKey ConvertToCImgKey(Key toConvert);

    std::unordered_map<CImgKey, CallableFunction> functionMapping;
public:
    Implementation(uint16_t width = 600, uint16_t height = 600, Key closingKey = Key::KEY_ESC)
        : windowWidth(width), windowHeight(height),
        windowCanvas(width, height, 1, 3, "255", true),
        windowDisplay(windowCanvas, "Game Window")
        {
            BindClosingKey(closingKey);
        };
    ~Implementation(){windowDisplay.close();};

    bool IsOpen();

    void BindClosingKey(Key closingKey);

    void BindCallableFunctionToKey(Key activationKey, CallableFunction toBind);
    
    void Clear();
    void PaintBox(uint16_t xStart, uint16_t yStart, uint16_t size, uint8_t RGBValues[3], uint16_t valueToPrint, uint8_t RGBValuesPrint[3]);
    void CreateGrid(uint8_t size);
    void Display();
    void Close();
};

void Window::Implementation::BindClosingKey(Key closingKey)
{
    this->closingKey = ConvertToCImgKey(closingKey);
}

bool Window::Implementation::IsOpen()
{
    for(auto &activatableFunctions : functionMapping)
    {
        if(windowDisplay.is_key(activatableFunctions.first))
        {
            activatableFunctions.second();
            windowDisplay.set_key(activatableFunctions.first, false);
        }
    }
    return !windowDisplay.is_key(closingKey) && !windowDisplay.is_closed();
}

void Window::Implementation::BindCallableFunctionToKey(Key activationKey, CallableFunction toBind)
{
    functionMapping[ConvertToCImgKey(activationKey)] = toBind;
}

void Window::Implementation::Clear()
{
    windowCanvas.fill(255);
}

void Window::Implementation::PaintBox(uint16_t xStart, uint16_t yStart, uint16_t size, uint8_t RGBValues[3], uint16_t valueToPrint, uint8_t RGBValuesPrint[3])
{
    windowCanvas.draw_rectangle(static_cast<int>(xStart), static_cast<int>(yStart), 
    static_cast<int>(xStart + size), static_cast<int>(yStart + size), RGBValues);
    std::string textToPrint = std::to_string(valueToPrint);
    windowCanvas.draw_text(static_cast<int>(xStart + size/2 - std::ceil(3*textToPrint.size())), static_cast<int>(yStart + size/2 - 7), textToPrint.c_str(), RGBValuesPrint, RGBValues, 1.f, 13);
}

void Window::Implementation::CreateGrid(uint8_t size)
{
    cimg_library::CImg<unsigned int> coordinates(size, 1, 1, 1);
    uint8_t black[] = {0, 0, 0};

    for(int i = 0; i < coordinates.width(); ++i)
    {
        coordinates(i) = i*(windowCanvas.height()/coordinates.width());
    }

    windowCanvas.draw_grid(coordinates, coordinates, black);
}

void Window::Implementation::Display()
{
    windowDisplay.display(windowCanvas);
}

void Window::Implementation::Close()
{
    windowDisplay.close();
}


CImgKey Window::Implementation::ConvertToCImgKey(Key toConvert)
{
    switch(toConvert)
    {
        case Key::KEY_A:
        return cimg_library::cimg::keyA;
        case Key::KEY_B:
        return cimg_library::cimg::keyB;
        case Key::KEY_C:
        return cimg_library::cimg::keyC;
        case Key::KEY_D:
        return cimg_library::cimg::keyD;
        case Key::KEY_E:
        return cimg_library::cimg::keyE;
        case Key::KEY_F:
        return cimg_library::cimg::keyF;
        case Key::KEY_G:
        return cimg_library::cimg::keyG;
        case Key::KEY_H:
        return cimg_library::cimg::keyH;
        case Key::KEY_I:
        return cimg_library::cimg::keyI;
        case Key::KEY_J:
        return cimg_library::cimg::keyJ;
        case Key::KEY_K:
        return cimg_library::cimg::keyK;
        case Key::KEY_L:
        return cimg_library::cimg::keyL;
        case Key::KEY_M:
        return cimg_library::cimg::keyM;
        case Key::KEY_N:
        return cimg_library::cimg::keyN;
        case Key::KEY_O:
        return cimg_library::cimg::keyO;
        case Key::KEY_P:
        return cimg_library::cimg::keyP;
        case Key::KEY_Q:
        return cimg_library::cimg::keyQ;
        case Key::KEY_R:
        return cimg_library::cimg::keyR;
        case Key::KEY_S:
        return cimg_library::cimg::keyS;
        case Key::KEY_T:
        return cimg_library::cimg::keyT;
        case Key::KEY_U:
        return cimg_library::cimg::keyU;
        case Key::KEY_V:
        return cimg_library::cimg::keyV;
        case Key::KEY_X:
        return cimg_library::cimg::keyX;
        case Key::KEY_Y:
        return cimg_library::cimg::keyY;
        case Key::KEY_Z:
        return cimg_library::cimg::keyZ;
        case Key::KEY_LEFT_CTRL:
        return cimg_library::cimg::keyCTRLLEFT;
        case Key::KEY_LEFT_SHIFT:
        return cimg_library::cimg::keySHIFTLEFT;
        case Key::KEY_ALT:
        return cimg_library::cimg::keyALT;
        case Key::KEY_RIGHT_CTRL:
        return cimg_library::cimg::keyCTRLRIGHT;
        case Key::KEY_RIGHT_SHIFT:
        return cimg_library::cimg::keySHIFTRIGHT;
        case Key::KEY_ALTGR:
        return cimg_library::cimg::keyALTGR;
        case Key::KEY_ESC:
        return cimg_library::cimg::keyESC;
        case Key::KEY_ENTER:
        return cimg_library::cimg::keyENTER;
        case Key::KEY_BACKSPACE:
        return cimg_library::cimg::keyBACKSPACE;
        case Key::KEY_SPACE:
        return cimg_library::cimg::keySPACE;
        case Key::KEY_1:
        return cimg_library::cimg::key1;
        case Key::KEY_2:
        return cimg_library::cimg::key2;
        case Key::KEY_3:
        return cimg_library::cimg::key3;
        case Key::KEY_4:
        return cimg_library::cimg::key4;
        case Key::KEY_5:
        return cimg_library::cimg::key5;
        case Key::KEY_6:
        return cimg_library::cimg::key6;
        case Key::KEY_7:
        return cimg_library::cimg::key7;
        case Key::KEY_8:
        return cimg_library::cimg::key8;
        case Key::KEY_9:
        return cimg_library::cimg::key9;
        case Key::KEY_0:
        return cimg_library::cimg::key0;
        case Key::KEY_NUMPAD_1:
        return cimg_library::cimg::keyPAD1;
        case Key::KEY_NUMPAD_2:
        return cimg_library::cimg::keyPAD2;
        case Key::KEY_NUMPAD_3:
        return cimg_library::cimg::keyPAD3;
        case Key::KEY_NUMPAD_4:
        return cimg_library::cimg::keyPAD4;
        case Key::KEY_NUMPAD_5:
        return cimg_library::cimg::keyPAD5;
        case Key::KEY_NUMPAD_6:
        return cimg_library::cimg::keyPAD6;
        case Key::KEY_NUMPAD_7:
        return cimg_library::cimg::keyPAD7;
        case Key::KEY_NUMPAD_8:
        return cimg_library::cimg::keyPAD8;
        case Key::KEY_NUMPAD_9:
        return cimg_library::cimg::keyPAD9;
        case Key::KEY_NUMPAD_0:
        return cimg_library::cimg::keyPAD0;
        case Key::KEY_NUMPAD_PLUS:
        return cimg_library::cimg::keyPADADD;
        case Key::KEY_NUMPAD_MINUS:
        return cimg_library::cimg::keyPADSUB;
        case Key::KEY_NUMPAD_DIVISION:
        return cimg_library::cimg::keyPADDIV;
        case Key::KEY_NUMPAD_MULTIPLICATION:
        return cimg_library::cimg::keyPADMUL;
        case Key::KEY_LEFT_ARROW:
        return cimg_library::cimg::keyARROWLEFT;
        case Key::KEY_RIGHT_ARROW:
        return cimg_library::cimg::keyARROWRIGHT;
        case Key::KEY_UP_ARROW:
        return cimg_library::cimg::keyARROWUP;
        case Key::KEY_DOWN_ARROW:
        return cimg_library::cimg::keyARROWDOWN;        
    }
    return static_cast<unsigned int>(-1); //Error
}