#ifndef MISSILECOMMAND_WINDOW_H
#define MISSILECOMMAND_WINDOW_H

#include <SDL.h>
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


protected:


    // Protected so other windows can access them directly
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    const char* title;
    int xPos, yPos, width, height;
    bool fullscreen;
    Handler *handler = nullptr;
    bool running = false;
    bool isTransferred = false;
    bool transferRequested = false;

};

#endif