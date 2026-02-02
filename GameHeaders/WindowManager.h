#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "Window.h"

class WindowManager {
public:
    static Window* updateWindow(Window* currentWindow) {
        // Check if the current window wants to retire
        if (currentWindow->needsTransfer() && currentWindow->getNextWindow() != nullptr) {
            
            // 1. Grab the new window
            Window* newWindow = currentWindow->getNextWindow();

            // 2. IMPORTANT: Tell the old window "Do not destroy SDL stuff"
            // If we don't do this, the destructor will kill the Renderer/Handler
            currentWindow->setTransferred(true);

            // 3. Delete the old C++ Wrapper
            delete currentWindow;

            // 4. Return the new pointer to main()
            return newWindow;
        }

        // If no transfer needed, just keep using the same window
        return currentWindow;
    }
};

#endif