#ifndef MISSILECOMMAND_WINDOW_H
#define MISSILECOMMAND_WINDOW_H

#include <SDL.h>
#include <SDL_ttf.h>

#include "Handler.h"

class Window {
public:
    Window(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    Window(const char *title, int xPos, int yPos, int width, int height, bool fullscreen, SDL_Renderer *renderer,
           SDL_Window *window, Handler* handler);

    virtual ~Window(); // Virtual destructor is vital for inheritance

    void init();
    void clean();
    bool isValid();
    bool isRunning() const;

    bool transfered();

    static Window *transferWindow(Window *windowToTransfer);


    virtual void handleEvents();

    void handleBasicEvents(SDL_Event &event);

    static bool showingBoarders();

    void setTransferred(bool state) { isTransferred = state; }
    bool needsTransfer() const { return transferRequested; }
    void requestTransfer() { transferRequested = true; }
    void update();
    virtual void render();

    // Setters for passing data to other classes
    void setWindowTitle(const char* newTitle);
    void setWindowSize(int w, int h);
    Handler* getHandler();

    // Getters so other classes can use the pointers
    SDL_Window* getWindow() const { return window; }
    SDL_Renderer *getRenderer() const { return renderer; }

    void setNextWindow(Window* win) { storedNextWindow = win; }
    Window* getNextWindow() { return storedNextWindow; }

    Handler *handler = nullptr;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static std::pair<int, int> getMousePos();
    static TTF_Font* defaultFont;



private:
    static int mouseX, mouseY;
    static bool showBoarders;
    const char* fontFile = "assets/Bungee-Regular.ttf";

protected:


    // Protected so other windows can access them directly
    const char* title;
    int xPos, yPos, width, height;
    bool fullscreen;
    bool running = false;
    bool isTransferred = false;
    bool transferRequested = false;
    bool mouseDown = false;
    SDL_Color White = {255,255, 255};
    SDL_Color Black = {0,0, 0};
    Window* storedNextWindow = nullptr;

};

#endif