/*
 * A simple HTTP Router for handling request routing in a web server.
 *
 * The `Router` class allows you to register routes and their corresponding handler functions.
 * When a request is routed, the router identifies the correct handler based on the request path
 * and executes it to generate a response. If no route matches, a `404 Not Found` response is returned.
 */

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <string>
#include <unordered_map>
#include <functional>
#include <sstream>
#include <utility>
#include <tuple>

class Router {
public:
	// Function that corresponds to the path, should be templetized
	using Handler = std::function<std::string(const std::string&)>;

	void register_route(const std::string& path, Handler handler) {
		routes_[path] = handler;
	}

	std::string route_request(const std::string& request) const {
		// Parse the request to extract the path
		std::string path = parse_request(request);

		// Find the matching route, and pass the request to the correspoding handler
		if (routes_.find(path) != routes_.end()) {
			return routes_.at(path)(request);
		}

		// If no route matches, return 404 response
		return "HTTP/1.1 404 Not Found\r\nContent-Length: 13\r\n\r\n404 Not Found";
	}

private:

	std::unordered_map<std::string, Handler> routes_;
	std::string parse_request(const std::string& request) const {

		std::istringstream request_stream(request);
		std::string method, path, http_version;

		request_stream >> method >> path >> http_version;

		return path;
	}
};

#endif