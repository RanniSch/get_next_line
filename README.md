# get_next_line
This project is about a function that returns a line read from a file descriptor. It is also an introduction into static variables. <br> 
The function always returns the line that was read. If there is nothing else to read or if an error occurred, it returns NULL.<br><br>

The code needs to be compiled as follows (a buffer size of 42 is used as an example):
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
