extern crate http_muncher;

// use http_muncher;
use std::str;
pub struct HttpHandler;

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

        println!("url:\t {}", s);
        return true;
    }
}

