#include "../include/router.hpp"

void Router::register_route(const std::string& path, Handler handler) {
    routes_[path] = handler;
}

std::string Router::route_request(const std::string& request) const {
    std::string path = parse_request(request);

    if (routes_.find(path) != routes_.end()) {
        return routes_.at(path)(request);
    }

    return "HTTP/1.1 404 Not Found\r\nContent-Length: 13\r\n\r\n404 Not Found";
}

std::string Router::parse_request(const std::string& request) const {
    std::istringstream request_stream(request);
    std::string method, path, http_version;
    request_stream >> method >> path >> http_version;
    return path;
}
