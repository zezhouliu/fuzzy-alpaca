extern crate http_muncher;

// use http_muncher;
use std::error::Error;
use std::io::prelude::*;
use std::fs::File;
use std::net::{TcpStream};
use std::str;

pub struct HttpHandler {
    stream: TcpStream
}

impl HttpHandler {
    pub fn new (stream: TcpStream) -> HttpHandler {
        HttpHandler {
            stream: stream
        }
    }

    pub fn response_header (&self, length: usize) -> String {
        let mut header = "HTTP/1.1 200 OK\r\n".to_string();
        header.push_str("Content-Type: text/html\r\n");
        header.push_str("Connection: Keep-Alive\r\n");
        header.push_str("Content-Length: ");
        header.push_str(&(length.to_string()));
        header.push_str("\r\n\r\n");
        return header;
    }
}

impl http_muncher::ParserHandler for HttpHandler {

    fn on_header_field(&mut self, header: &[u8]) -> bool {
        let s = match str::from_utf8(header) {
            Ok(v) => v,
            Err(e) => panic!("Invalid UTF-8 sequence: {}", e),
        };

        println!("header:\t {}", s);
        return true;
    }

    fn on_header_value(&mut self, value: &[u8]) -> bool {
        let s = match str::from_utf8(value) {
            Ok(v) => v,
            Err(e) => panic!("Invalid UTF-8 sequence: {}", e),
        };

        println!("header_value:\t {}", s);
        return true;
    }

    fn on_url(&mut self, arg: &[u8]) -> bool {
        let s = match str::from_utf8(arg) {
            Ok(v) => v,
            Err(e) => panic!("Invalid UTF-8 sequence: {}", e),
        };

        // Create the full filepath to read back
        let mut filepath = "static".to_string();

        // Check if it was the empty path (home)
        match s.as_ref() {
            "/" => filepath.push_str("/index.html"),
            _ => filepath.push_str(s),
        }

        // Open the file path
        let mut f = match File::open(&filepath) {
            Err(e) => panic!("Couldnt open file {}: {}", &filepath, Error::description(&e)),
            Ok(file) => file,
        };

        // Read the file contents
        let mut contents = String::new();
        match f.read_to_string(&mut contents) {
            Err(e) => panic!("Couldn't read {}: {}", &filepath, Error::description(&e)),
            // Ok(_) => println!("Content: {}", contents),
            Ok(_) => (),
        }

        // Prepare the response header
        let len = contents.len();
        let header = self.response_header(len);
        let _ = match self.stream.write(header.as_bytes()) {
            Err(e) => panic!("Unable to write header: {}", Error::description(&e)),
            Ok(_) => {},
        };


        // Write back to the stream
        let _ = match self.stream.write(contents.as_bytes()) {
            Err(e) => panic!("Unable to write content: {}", Error::description(&e)),
            Ok(_) => {},
        };

        return true;
    }

    fn on_status(&mut self, status: &[u8]) -> bool {
        let s = match str::from_utf8(status) {
            Ok(v) => v,
            Err(e) => panic!("Invalid UTF-8 sequence: {}", e),
        };

        println!("status:\t {}", s);
        return true;
    }
}

