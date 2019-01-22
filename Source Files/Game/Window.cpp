#include "..\..\Header Files\Game\Window.hpp"
#include "..\..\Header Files\Game\WindowImplementation.hpp"

Window::Window(uint16_t width, uint16_t height, Key closingKey)
    : pImplementation(std::make_unique<Implementation>(width, height, closingKey))
{
}

Window::~Window()
{

}

bool Window::IsOpen()
{
    return pImplementation->IsOpen();
}

void Window::BindClosingKey(Key closingKey)
{
    pImplementation->BindClosingKey(closingKey);
}

void Window::BindCallableFunctionToKey(Key activationKey, CallableFunction toBind)
{
    pImplementation->BindCallableFunctionToKey(activationKey, toBind);
}

void Window::Clear()
{
    pImplementation->Clear();
}
void Window::PaintBox(uint16_t xStart, uint16_t yStart, uint16_t size, uint8_t RGBValues[3], uint16_t valueToPrint, uint8_t RGBValuesPrint[3])
{
    pImplementation->PaintBox(xStart, yStart, size, RGBValues, valueToPrint, RGBValuesPrint);
}

void Window::CreateGrid(uint8_t size)
{
    pImplementation->CreateGrid(size);
}

void Window::Display()
{
    pImplementation->Display();
}

void Window::Close()
{
    pImplementation->Close();
}