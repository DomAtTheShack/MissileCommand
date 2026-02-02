#include "../Window.h"

#include <iostream>
#include <ostream>
#include <SDL_ttf.h>

SDL_Renderer *Window::renderer = nullptr;
SDL_Window *Window::window = nullptr;
int Window::mouseX = 0;
int Window::mouseY = 0;
bool Window::showBoarders = false;
TTF_Font* Window::defaultFont = nullptr;


Window::Window(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) 
    : title(title), xPos(xPos), yPos(yPos), width(width), height(height), fullscreen(fullscreen) {
    init();
    handler = new Handler();
}

Window::Window(const char* title, int xPos, int yPos, int width, int height, bool fullscreen, SDL_Renderer* renderer, SDL_Window* window, Handler* handler)
    : title(title), xPos(xPos), yPos(yPos), width(width), height(height), fullscreen(fullscreen) {
    this->handler = handler;
    this->renderer = renderer;
    this->window = window;
    running = true;
    setWindowTitle(title);
    setWindowSize(width, height);
}

Window::~Window() {
    if (!isTransferred) {
        delete handler;
        handler = nullptr;
        clean(); // Only destroy SDL resources if we aren't transferring them
    }
}

void Window::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        
        if (window) {
            SDL_SetWindowResizable(window, SDL_FALSE);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer) {
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                running = true;
            }
        }
        TTF_Init();
        defaultFont = TTF_OpenFont(fontFile, 24);
    }
}

void Window::setWindowTitle(const char* newTitle) {
    title = newTitle;
    if(window) SDL_SetWindowTitle(window, title);
}

void Window::setWindowSize(int w, int h) {
    width = w; height = h;
    if(window) SDL_SetWindowSize(window, width, height);
}

void Window::clean() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    // REMOVED SDL_Quit() from here
}

bool Window::isValid() {
    return window != nullptr && renderer != nullptr;
}

void Window::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        handleBasicEvents(event); // Call the internal basic logic

        if (handler != nullptr) {
            handler->handleEvents(&event);
        }
    }
}

void Window::handleBasicEvents(SDL_Event& event) {
    if (event.type == SDL_QUIT) running = false;

    // Always update mouse position on motion
    if (event.type == SDL_MOUSEMOTION) {
        mouseX = event.motion.x;
        mouseY = event.motion.y;
    }
    // Also update on clicks (sometimes motion doesn't fire if you just click)
    if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
        mouseX = event.button.x;
        mouseY = event.button.y;
    }

    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_RETURN && (event.key.keysym.mod & KMOD_ALT)) {
            fullscreen = !fullscreen;
            SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
        }
    }

    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);

    if (event.key.keysym.sym == SDLK_b) {
        // Only run if this is the initial press (repeat is 0)
        if (event.key.repeat == 0) {
            if (currentKeyStates[SDL_SCANCODE_F3]) {
                showBoarders = !showBoarders;
                std::cout << "F3 + B pressed. ShowBorders: " << (showBoarders ? "On" : "Off") << std::endl;
            }
        }
    }

}

bool Window::showingBoarders() {
    return showBoarders;
}

void Window::update() {
    handler->Update();
}

void Window::render() {
    SDL_RenderClear(renderer);
    handler->Render();
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderPresent(renderer);
}

Handler* Window::getHandler() {
    return handler;
}

bool Window::isRunning() const {
    return running;
}

Window* Window::transferWindow(Window* windowToTransfer) {
    return new Window("Transfered Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 180, false,
        windowToTransfer->getRenderer(), windowToTransfer->getWindow(), windowToTransfer->getHandler());
}

std::pair<int, int> Window::getMousePos() {
    return {mouseX, mouseY};
}