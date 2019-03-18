// The <termios.h> header contains the definitions used by the terminal I/O interfaces
#include <termios.h>
// unistd.h is the name of the header file that provides access to the POSIX operating system API
#include <unistd.h>


// turn off "echo" mode, (The ECHO feature causes each key you type to be printed to the terminal, so you can see what you’re typing, and by this function below it disabled)
void enableRawMode(){
  struct termios raw;
    
    tcgetattr(STDIN_FILENO, &raw);
    // The c_lflag field is for “local flags” | ECHO is a bitflag, defined as 00000000000000000000000000001000 in binary. We use the bitwise-NOT operator (~) on this value to get the opposite to disable the echo mode
    raw.c_lflag &= ~(ECHO);
    
    // The TCSAFLUSH argument specifies when to apply the change: in this case, it waits for all pending output to be written to the terminal, and also discards any input that hasn’t been read.
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}









// main entry to program
int main(){
    
    enableRawMode();
    
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