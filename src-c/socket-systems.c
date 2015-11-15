#include "socket-systems.h"

/*
ssize_t
recv(int socket, void *buffer, size_t length, int flags);

ssize_t send(int sockfd, const void * buffer, size_t length, int flags);
*/

ssize_t io_recv(socket_t* socket, void* buffer, size_t length, int flags)
{
    if (socket->status != SOCKET_OPEN)
    {
        return 0;
    }

    if (socket->status == SOCKET_OPEN)
    {
        return recv (socket->fd, buffer, length, flags);
    }

    return 0;
}

ssize_t io_send(socket_t* socket, const void* buffer, size_t length, int flags)
{
    if (socket->status != SOCKET_OPEN)
    {
        return 0;
    }

    if (socket->status == SOCKET_OPEN)
    {
        return send (socket->fd, buffer, length, flags);
    }

    return 0;
}

