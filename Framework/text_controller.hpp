#ifndef TEXT_CONTROLLER_HPP
#define TEXT_CONTROLLER_HPP

#include <string>
#include <iostream>

class TextController {
public:

    static std::string handle(const std::string& request) {
        std::cout << "Handling request: " << request << std::endl;
        return "HTTP/1.1 200 OK\r\nContent-Length: 11\r\n\r\nHello World";
    }
};

#endif 
