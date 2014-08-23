#ifndef ACCEPTORS_GUARD
#define ACCEPTORS_GUARD

#include "wrappers/asio/server_socket.h"

#include <string>
#include <thread>
#include <memory>

// Not much more than a handle for a do_accpet thread
namespace events
{
    class Acceptor
    {
        public:
            Acceptor ( int port, std::string service );

            int get_port () const;

            virtual ~Acceptor () = default;

        private:
            void do_accept ();

            int port;
            std::string service;
            std::shared_ptr < sockets::Server_socket > socket;
            std::thread do_accept_thread;
    };
}

#endif //ACCEPTORS_GUARD
