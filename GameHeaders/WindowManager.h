class WindowManager {
public:
    static Window* updateWindow(Window* current) {
        if (current->needsTransfer()) {
            // Mark as transferred so the destructor doesn't touch SDL or the Handler
            current->setTransferred(true);

            Window* nextWindow = new Window("Game Scene",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            1200, 700, false,
                                            current->getRenderer(),
                                            current->getWindow(),
                                            current->getHandler());

            delete current; // Safe now because isTransferred = true
            return nextWindow;
        }
        return current;
    }
};