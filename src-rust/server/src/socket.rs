use std::net::{TcpListener};

/*
pub enum SStatus {
    SocketOpen = 1,
    SocketClosed = 2,
    SocketInvalid = 3
}
*/

pub struct Socket {
    pub port: i32,
    pub addr: String,
    // pub status: SStatus,
    fd: TcpListener
    /*
    stream: TcpStream,
    */

}

impl Socket {
    // Constructor
    pub fn new() -> Socket {
        Socket {
            port: 8080,
            addr: "127.0.0.1".to_string(),
            fd: TcpListener::bind("127.0.0.1:8080").unwrap(),
            // status: SStatus::SocketClosed,
        }
    }

    pub fn get_listener(&self) -> TcpListener {
        /*
        match self.status {
            SStatus::SocketOpen => return self.fd.try_clone().unwrap(),
            _ => None
        }
        */
        return self.fd.try_clone().unwrap();
    }
}
