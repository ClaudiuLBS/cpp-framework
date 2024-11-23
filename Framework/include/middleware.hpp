#ifndef MIDDLEWARE_HPP
#define MIDDLEWARE_HPP

#include <string>
#include <vector>
#include <functional>

using Middleware = std::function<std::string(const std::string&)>;

class MiddlewarePipeline {
public:

    void add_middleware(Middleware middleware);

    std::string execute(const std::string& request);

private:
    
    std::vector<Middleware> middlewares;
};

#endif 
