/**
 *
 * This program demonstrates how to create a simple HTTP server using the
 * Boost.Asio library. The server listens for incoming TCP connections on port 8080,
 * receives HTTP requests, and responds with a fixed "Hello, World!" message.
 *
 * Features:
 * - Listens on port 8080 for incoming connections.
 * - Handles HTTP requests and prints the request to the console.
 * - Responds with a simple HTTP response containing "Hello, World!".
 *
 * Usage:
 * 1. Compile and run the program.
 * 2. Use a web browser or tools like `curl` or postman to send a request to the server:
 *      curl http://localhost:8080
 * 3. The server will respond with "Hello, World!".
 *
 * Dependencies:
 * - Boost.Asio library
 * - C++11 or later
 *
 */


#include <boost/asio.hpp>
#include <iostream>
#include <array>
#include "router.hpp"
#include "text_controller.hpp"

using boost::asio::ip::tcp;

/**
 *
 * The server initializes a Boost.Asio I/O context and a TCP acceptor to listen
 * for connections on port 8080. For each connection:
 * - It reads the HTTP request from the client.
 * - Prints the request to the console.
 * - Sends a fixed HTTP response with "Hello, World!" as the body.
 *
 * @return int Exit code of the program.
 */

int main() {
    try {

        boost::asio::io_context io_context;

        // Create a TCP acceptor to listen on port 8080
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));
        std::cout << "Server is running on port 8080..." << std::endl;

        Router router;
        router.register_route("/hello", TextController::handle);

        // Infinite loop keeping the server running
        while(true) {
            // Create a socket to handle client connections
            tcp::socket socket(io_context);

            // Wait for a client to connect
            acceptor.accept(socket);

            // Buffer to store incoming data
            std::array<char, 1024> buffer;
            boost::system::error_code error;

            // Read data from the client
            size_t bytes_read = socket.read_some(boost::asio::buffer(buffer), error);

            if (!error || error == boost::asio::error::eof) {
                // Convert the received data to a string and display it
                std::string request(buffer.data(), bytes_read);
                std::cout << "Received request:\n" << request << std::endl;

                // Route the request
                std::string response = router.route_request(request);
                boost::asio::write(socket, boost::asio::buffer(response));
            }
            else {
                // Print error message if reading fails
                std::cerr << "Error while reading: " << error.message() << std::endl;
            }
        }
    }
    catch (std::exception& e) {
        // Handle any exceptions thrown
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
