#include "FrameBuffer.hpp"

#include <iostream>

#include <stdio.h>
// Linux implementation
#ifdef __linux__
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif
// Windows implementation (TODO)
#ifdef _WIN32

#endif

size_t tpg::termW, tpg::termH;

char tpg::__impl::start_code() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    termW = w.ws_col;
    termH = w.ws_row;

    return 0;
};

char start_result = tpg::__impl::start_code();