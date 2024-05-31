# get_next_line
This project is about a function that returns a line read from a file descriptor. It is also an introduction into static variables. <br> 
The function always returns the line that was read. If there is nothing else to read or if an error occurred, it returns NULL.

## How to run the code
* The code needs to be compiled as follows (a buffer size of 42 is used as an example): ```cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c```
* Then run the code with: ```./a.out```<br><br>

There is an example text file "test.txt" which is called by main.c <br>

![get_next_line-1](https://github.com/RanniSch/get_next_line/assets/104382315/13f45616-6d3e-4523-8ac7-4a3adb14da5c)
