/**
 * socket-base.h
 *
 * @Brief: Base for socket wrapper
 */

#ifndef __SOCKET_BASE_H__
#define __SOCKET_BASE_H__

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <netdb.h>

#include "utils.h"

// sstatus_t = socket status type
typedef enum {
    SOCKET_OPEN = 1,
    SOCKET_CLOSED = 2,
    SOCKET_INVALID = 3
} sstatus_t;

// socket_t = our socket wrapper
typedef struct socket_ {
    int fd;
    sstatus_t status;
    struct sockaddr_in name;
    unsigned short port;
} socket_t;

/**
* socket_get_status(s)
*
* @Brief returns the status of s
* @param[in]: s, socket_t*
* @pre: s is a valid socket_t*
* return: sstatus_t representing status of s
**/
sstatus_t socket_get_status(socket_t* s);

/**
* socket_get_fd(s)
*
* @Brief returns the file descriptor associated with s
* @param[in]: s, socket_t*
* @pre: s is a valid socket_t*
* @pre: s.status = SOCKET_OPEN
* return: int fd if valid, else -1
**/
int socket_get_fd(socket_t* s);
#endif /* __SOCKET_BASE_H__ */

