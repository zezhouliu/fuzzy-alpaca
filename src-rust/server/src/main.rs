#[macro_use]
extern crate bufstream;
extern crate http_muncher;

mod http_handler;
mod socket;
mod utils;

use std::io::prelude::*;
use std::net::{TcpStream};
use std::thread;

use bufstream::BufStream;
use http_muncher::{Parser};

fn handle_client(stream: TcpStream) -> () {
    println!("Connected! {}", stream.peer_addr().unwrap());
    let cpy_stream = stream.try_clone().unwrap();

    let line = &mut String::new();
    let mut buf_stream = BufStream::new(stream);

    // Clone the stream for the HTTPHandler
    let callback_handler = http_handler::HttpHandler::new(cpy_stream);

    let mut parser = Parser::request(callback_handler);

    loop {
        buf_stream.read_line(line).unwrap();
        parser.parse(line.as_bytes());
    };
}

fn main() {
    let s = socket::Socket::new();

    for stream in s.get_listener().incoming() {
        match stream {
            Ok(stream) => {
                thread::spawn(move|| {
                    handle_client(stream)
                });
            }
            Err(e) => {
                // Connection failed
                panic!("Unable to connect stream: {}", e)
            }
        }
    }
}
