#include "../include/controller.hpp"

std::string Controller::handle(const std::string& request) {
    std::cout << "Handling request: " << request << std::endl;
    return "HTTP/1.1 200 OK\r\nContent-Length: 11\r\n\r\nHello World";
}
