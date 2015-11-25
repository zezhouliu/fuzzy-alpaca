use std::net::{TcpListener, TcpStream};
use std::thread;

enum SStatus {
    Socket_Open = 1,
    Socket_Closed = 2,
    Socket_Invalid = 3
}

pub struct Socket {
    fd: TcpListener,
    stream: TcpStream,
    status: SStatus
}

impl Socket {
    fn getStatus(&self) -> SStatus {
        return self.status;
    }

    fn getFD(&self) -> TcpListener {
        return self.fd;
    }

    fn getStream(&self) -> TcpStream {
        return self.stream;
    }

    fn write(&self, buf) -> Result<usize> {
        return self.stream.write(buf);
    }

    fn read(&self, buf) -> Result<usize> {
        return self.stream.read(&mut buf);
    }
}




