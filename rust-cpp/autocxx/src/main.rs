use autocxx::prelude::*; // use all the main autocxx functions

include_cpp! {
    #include "math.hpp"
    safety!(unsafe) // see details of unsafety policies described in the 'safety' section of the book
    generate!("do_math") // add this line for each function or type you wish to generate
}

fn main() {
    let res = ffi::do_math(autocxx::c_int(2), autocxx::c_int(3)).0;
    println!("Adding up from C++ library = {}", res);
}
