/**
* socket-systems.h
*
* @Brief: Wrappers for socket system calls so that we can specify @pre/@post 
*     for system calls.
*/

#ifndef __SOCKET_SYSTEMS_H__
#define __SOCKET_SYSTEMS_H__

#include "socket-base.h"

ssize_t io_recv(socket_t* socket, void* buffer, size_t length, int flags);
ssize_t io_send(socket_t* socket, const void* buffer, size_t length, int flags);
#endif /* __SOCKET_SYSTEMS_H__ */

