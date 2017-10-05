#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

class Logger {
private:
    static const bool DEBUG = true;

    static Logger* _instance;
    Logger() = default;
public:
    static Logger* instance();

    void log(const std::string& data) {
        if (DEBUG)
            std::cout << "[DEBUG] " << data << std::endl;
    }

};


#endif
