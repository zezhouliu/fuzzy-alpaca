#include "socket-base.h"

sstatus_t socket_get_status(socket_t* s)
{
    if (s == NULL) {
    	return SOCKET_INVALID;
    }
    return s->status;
}

int socket_get_fd(socket_t* s)
{
    if (s != NULL && s->status == SOCKET_OPEN) {
        return s->fd;
    } 
    return -1;
}
