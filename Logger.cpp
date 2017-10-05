#include "Logger.h"

Logger* Logger::_instance = nullptr;

Logger* Logger::instance() {
    if (_instance == nullptr)
        _instance = new Logger;
    return _instance;
}
