#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "Window.h"

class SettingsWindow : public Window {
public:
    // Constructor passes arguments up to the Parent (Window)
    SettingsWindow(const char* title, int x, int y, int w, int h, bool fs) 
        : Window(title, x, y, w, h, fs) {
        init();
    }

    // SettingsWindow specific logic here
    void applyGraphicsSettings();

    void init();

    void clean();

    void render();

    void handleEvents();
};

#endif