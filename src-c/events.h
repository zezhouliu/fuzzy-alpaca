/**
 * events.h
 *
 * events functionality
 */

#ifndef __EVENTS_H__
#define __EVENTS_H__

#include <poll.h>
#include <sys/poll.h>
#include <poll.h>
#include "utils.h"
#include "vector.h"
#include "sockets.h"

typedef struct pollsocket_ {
    vector* sockets;
    struct pollfd* pfds;
    unsigned int size;
} pollsocket_t;

/**
 * pollsocket_create(sockets)
 *
 * @Brief: Creates pollsocket_t to handle socket polling
 *
 * @param  sockets, vector* containing socket_t*
 * @post:  all socket_t* contained contain valid ufds
 * @return pollsocket_t* wrapper for socket
 */
pollsocket_t* pollsocket_create(vector* sockets);
pollsocket_t* pollsocket_validate(pollsocket_t* ps);

/**
 * poll_sockets(ufds, nfds, timeout)
 *
 * @Brief: Wrapper for poll(struct pollfd *ufds,unsigned int nfds,int timeout)
 *      Instead, we apply verification before we allow for polling
 * @param[in]: ufds, pollsocket_t* containing wrapper
 * @param[in]: nfds, unsigned int count of fds
 * @param[in]: timeout, int
 */
int poll_sockets(pollsocket_t* ps, int timeout);
vector* poll_response(pollsocket_t* ps);
#endif /* __EVENTS_H__ */

