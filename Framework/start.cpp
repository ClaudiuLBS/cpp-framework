#include <iostream>
#include <boost/asio.hpp>
#include "include/router.hpp"
#include "include/middleware.hpp"
#include "include/controller.hpp"
#include "include/db/models/user.hpp"
#include "server.cpp"

using boost::asio::ip::tcp;

int main() {
    try {

        boost::asio::io_context io_context;
        Server server(io_context, 8080);

        initialize_user_fields();
        std::string sql = User.generate_create_table_sql();
        std::cout << sql << std::endl;

        server.register_route("/hello", Controller::handle);

        server.add_middleware([](const std::string& request) {
            std::cout << "Middleware: Logging request\n" << request << std::endl;
            return request;
        });

        server.start();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
