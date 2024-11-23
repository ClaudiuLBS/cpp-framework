#include <boost/asio.hpp>
#include <iostream>
#include <array>
#include "include/router.hpp"
#include "include/middleware.hpp"

using boost::asio::ip::tcp;

class Server {
public:
	Server(boost::asio::io_context& io_context, unsigned short port)
		: acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {};

	void register_route(const std::string& path, const std::function<std::string(const std::string&)> handler) {
		router_.register_route(path, handler);
	}

	void add_middleware(const Middleware& middleware) {
		middleware_pipeline_.add_middleware(middleware);
	}

	void start() {
		std::cout << "Server is running...";
		accept_connections();
	}
		 
private:
	tcp::acceptor acceptor_;
	Router router_;
	MiddlewarePipeline middleware_pipeline_;

	void accept_connections() {
		while (true) {
			tcp::socket socket(acceptor_.get_executor());

			acceptor_.accept(socket);
			handle_request(std::move(socket));
		}
	}

	void handle_request(tcp::socket socket) {

		try {
			std::array<char, 1024> buffer;
			boost::system::error_code error;

			size_t bytes_read = socket.read_some(boost::asio::buffer(buffer), error);
			if (error && error != boost::asio::error::eof) {
				std::cerr << "Error while reading: " << error.message() << std::endl;
				return;
			}

			std::string request(buffer.data(), bytes_read);
			std::cout << "Received request:\n" << request << std::endl;

			std::string processed_request = middleware_pipeline_.execute(request);

			std::string response = router_.route_request(processed_request);
			boost::asio::write(socket, boost::asio::buffer(response));
		}
		catch (const std::exception& e) {
			std::cerr << "Exception in handling the request: " << e.what() << std::endl;
		}
	}
};