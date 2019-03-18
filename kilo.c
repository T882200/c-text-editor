// unistd.h is the name of the header file that provides access to the POSIX operating system API.
#include <unistd.h>


// main entry to program
int main(){
    // init variable c
    char c;
    
    // asking read() to read 1 byte from the standard input into the variable c and to keep doing it until there are no more bytes to read
    // now the program runs and turn the terminal to RAW mode, in exchange to canonical (regular) mode.
    // until you press CTRL+c to signal the process to terminate immediately.
    // or until you press CTRL+d to tell read() that it’s reached the end of file.
    // or until you press 'q'+Enter to exit.('q' can be even in the middle of the text, then it exit the while loop)
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}