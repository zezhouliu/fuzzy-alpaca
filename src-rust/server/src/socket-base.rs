use std::net::{TcpListener};
use std::thread;

enum SStatus {
    Socket_Open = 1,
    Socket_Closed = 2,
    Socket_Invalid = 3
}

pub struct Socket {
    fd: TcpListener,
    status: SStatus
}

impl Socket {
    fn getStatus(&self) -> SStatus {
        return self.status;
    }

    fn getFD(&self) -> TcpListener {
        return self.fd;
    }

}




