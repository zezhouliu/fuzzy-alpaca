/**
 * sockets.h
 *
 * @Brief: Sockets wrapper
 */

#ifndef __SOCKETS_H__
#define __SOCKETS_H__

#include "utils.h"
#include "socket-base.h"
#include "socket-systems.h"

// Public interface
/**
 * socket_startup(port)
 *
 * @Brief: Starts up a socket at a [opt] port
 * @param[in]: port, unsigned short containing port to connect to
 * @pre: port is not already occupied by another socket
 * @post: port will be occupied by this socket
 * @return: socket_t* wrapper containing socket info
 **/
socket_t* socket_startup(unsigned short port);

/**
 * socket_connect(port, addr)
 *
 * @Brief: Starts up a socket at a [opt] port
 * @param[in]: port, unsigned short containing port to connect to
 * @param[in]: addr, char* representing address to bind to
 * @pre: port is not already occupied by another socket
 * @post: port will be occupied by this socket
 * @return: socket_t* wrapper containing socket info
 **/
socket_t* socket_connect(unsigned short port, char* addr);

/**
* socket_close()
*
* @Brief: Closes the socket associated with s
* @param[in]: s, socket_t* to be closed
* @post: s.status = SOCKET_CLOSED
* @post: s is invalidated
* @return: void
**/
void socket_close(socket_t* s);

/**
* socket_accept(s)
*
* @Brief: Accepts the first connection on the queue of pending connections from s
*   creates a new socket with the same socket type and protocol and address family
*   as the specified socket.
*   Allocates a new file descriptor for that socket.
* @param[in]: s, socket_t* to accept a connection from
* @pre: s.status = SOCKET_OPEN
* @post: new_socket.status = SOCKET_OPEN
* @post: new_socket.fd != s.fd
* @return: void
**/
socket_t* socket_accept(socket_t* s);

/**
 * socket_read_line(s, buf, size)
 *
 * @Brief: Read a line from a socket one character at a time.
 *  Terminates the string read with a null character.
 *  If any line terminators is read, the last character of the
 *  string will be a linefeed and the string will be terminated with a
 *  null character.
 *
 * @param[in]: s, socket_t* to read from
 * @param[in]: buf, char* to write into
 * @param[in]: size of buf
 * @return size read
 */
int socket_read_line(socket_t* s, char* buf, int size);

/**
 * socket_send(s, buf, size, flags)
 *
 * @Brief: Wrapper for send()
 *
 * @param[in]: s, socket_t* to send through
 * @param[in]: buf, char* to send across socket
 * @param[in]: size, int of buffer
 * @param[in]: flags, int of flags to send
 * @return n success, these calls return the number of characters sent.
 *  On error, -1 is returned, and errno is set appropriately.
 */
ssize_t socket_send(socket_t* s, char* buf, int size, int flags);

/**
 * socket_recv(s, buf, size, flags)
 *
 * @Brief: Wrapper for recv()
 *
 * @param[in]: s, socket_t* to recv from
 * @param[in]: buf, char* to receive from socket
 * @param[in]: size, int of buffer
 * @param[in]: flags, int of flags to send
 * @return n success, these calls return the number of characters received.
 *  On error, -1 is returned, and errno is set appropriately.
 */
ssize_t socket_recv(socket_t* s, char* buf, int size, int flags);

#endif /* __SOCKETS_H__ */
