#![macro_use]

#[macro_export]
macro_rules! log_err {
    ($($arg:tt)*) => (
        use std::io::Write;
        match writeln!(&mut ::std::io::stderr(), $($arg)* ) {
            Ok(_) => {},
            Err(x) => panic!("Unable to write to stderr (file handle closed?): {}", x),
        }
    )
}

macro_rules! log_info {
    ($($arg:tt)*) => (
        use std::io::Write;
        match writeln!(&mut ::std::io::stdout(), $($arg)* ) {
            Ok(_) => {},
            Err(x) => panic!("Unable to write to stderr (file handle closed?): {}", x),
        }
    )
}

