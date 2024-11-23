#include "../include/middleware.hpp"


void MiddlewarePipeline::add_middleware(Middleware middleware) {
    middlewares.push_back(middleware);
}

std::string MiddlewarePipeline::execute(const std::string& request) {
    std::string modified_request = request;

    for (auto& middleware : middlewares) {
        modified_request = middleware(modified_request);
    }

    return modified_request;
}
