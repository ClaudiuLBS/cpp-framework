#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <string>
#include <unordered_map>
#include <functional>
#include <sstream>

class Router {
public:
    using Handler = std::function<std::string(const std::string&)>;

    void register_route(const std::string& path, Handler handler);
    std::string route_request(const std::string& request) const;

private:
    std::unordered_map<std::string, Handler> routes_;
    std::string parse_request(const std::string& request) const;
};

#endif 
