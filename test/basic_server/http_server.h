//
// Copyright (c) 2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: HTTP server, small
//
//------------------------------------------------------------------------------

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

namespace beast = boost::beast;    // from <boost/beast.hpp>
namespace http = beast::http;      // from <boost/beast/http.hpp>
namespace net = boost::asio;       // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;  // from <boost/asio/ip/tcp.hpp>

class http_connection : public std::enable_shared_from_this<http_connection> {
   public:
    http_connection(tcp::socket socket) : socket_(std::move(socket)) {}

    // Initiate the asynchronous operations associated with the connection.
    void start() {
        read_request();
        check_deadline();
    }

   private:
    // The socket for the currently connected client.
    tcp::socket socket_;

    // The buffer for performing reads.
    beast::flat_buffer buffer_{8192};

    // The request message.
    http::request<http::string_body> request_;

    // The response message.
    http::response<http::dynamic_body> response_;

    // The timer for putting a deadline on connection processing.
    net::steady_timer deadline_{socket_.get_executor(),
                                std::chrono::seconds(60)};

    // Asynchronously receive a complete request message.
    void read_request();

    // Determine what needs to be done with the request message.
    void process_request();

    // Construct a response message based on the program state.
    void create_response();

    // Asynchronously transmit the response message.
    void write_response();

    // Check whether we have spent enough time on this connection.
    void check_deadline();

    std::string getSubgraphName(std::string& target);
};

class GraphNodeTestServer {
   public:
    GraphNodeTestServer() : ioc_(1) {}
    void RunServer();
    void ShutDownServer();

   private:
    net::io_context ioc_;
};
