#[macro_use]
extern crate bufstream;
extern crate http_muncher;

mod http_handler;
mod socket;
mod utils;

use std::io::prelude::*;
use std::net::{TcpListener, TcpStream};
use std::thread;

use bufstream::BufStream;
use http_muncher::{Parser, ParserHandler};

fn handle_client(mut stream: TcpStream) -> () {
   println!("Connected! {}", stream.peer_addr().unwrap());

   let line = &mut String::new();
   let mut buf_stream = BufStream::new(stream);

   let mut callback_handler = http_handler::HttpHandler;
   let mut parser = Parser::request(callback_handler);
   loop {
       buf_stream.read_line(line).unwrap();
       println!("Input: {}", &line);
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
            }
        }
    }
}
