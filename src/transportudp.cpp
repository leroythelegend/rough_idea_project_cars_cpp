#include "../inc/transportudp.h"

#include "../inc/exception.h"

#ifdef _WIN32

#define close closesocket

#pragma comment(lib, "Ws2_32.lib")
#include <Ws2tcpip.h>

#else

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <cstring>
#include <unistd.h>

#endif

#include <string>

using std::to_string;
using std::string;

namespace pcars {

TransportUDP::TransportUDP(const Port port) {

    struct addrinfo hints, *servinfo, *p;
    int rv = 0;

    string sport = to_string(port);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE; // use my IP

    if ((rv = getaddrinfo(NULL, sport.c_str(), &hints, &servinfo)) != 0) {
        string msg("getaddrinfo error ");
        msg.append(gai_strerror(rv));
        throw PCars_Exception(msg);
    }

    // loop through all the results and bind to the first we can



    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((socketfd_ = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            continue;
        }

        if (bind(socketfd_, p->ai_addr, p->ai_addrlen) == -1) {
            ::close(socketfd_);
            continue;
        }

        break;
    }

    if (p == NULL) {
        string msg("socket or bind ");
        msg.append(to_string(errno));
        throw PCars_Exception(msg);
    }

    freeaddrinfo(servinfo);
}

TransportUDP::~TransportUDP() {
	close(socketfd_);
}


PCars_Data TransportUDP::read(const Amount amount) {

    int numbytes;
    struct sockaddr_storage their_addr;
    socklen_t addr_len = sizeof their_addr;

    PCars_Data buffer(amount);

#ifdef _WIN32
    if ((numbytes = recvfrom(socketfd_, reinterpret_cast<char *>(buffer.data()), amount , 0,
        (struct sockaddr *)&their_addr, &addr_len)) == -1) {
    	throw PCars_Exception(__LINE__, __FILE__, errno, "recvfrom");
    }
#else
	if ((numbytes = recvfrom(socketfd_, buffer.data(), amount, 0,
		(struct sockaddr *)&their_addr, &addr_len)) == -1) {
		throw PCars_Exception("recvfrom");
	}
#endif

    buffer.resize(numbytes);

    return buffer;
}

void TransportUDP::write(const PCars_Data & ) {

}


}

