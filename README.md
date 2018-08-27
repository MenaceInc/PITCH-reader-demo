## PITCH reader demo
A program that reads in PITCH data from either standard input or by filename passed in as an argument.  
Shows a table of the top ten stock symbols by executed volume at the end.  
Handles Add Order, Order Cancel, Order Executed and Trade messages as defined in the PITCH v1.15.0 specification.  
Can easily be extended to handle all message types and already has structs defined to handle them.  

### Build and run instructions
    mkdir cmake-build && cd cmake-build
    cmake ..
    make
    cat pitch_example_data | ./PITCH_reader_demo
    ./PITCH_reader_demo pitch_example_data

If using Windows and MSYS2/MinGW-w64, you'll need to change `cmake ..` for `cmake -DCMAKE_MAKE_PROGRAM=mingw32-make -G"MSYS Makefiles" ..` and change `make` for `mingw32-make`.
