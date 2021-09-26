# 42cursus-get_next_line

Summary: The aim of this project is to make you code a function that returns a line,
read from a file descriptor.

Calling the function get_next_line in a loop will then allow you to read the text
available on the file descriptor one line at a time until the end of it.

This function return the line that has just been read. If there is nothing
else to read or if an error has occurred it will return NULL.

# The program must be compiled in this way:
gcc  -D BUFFER_SIZE=< size > get_next_line.c get_next_line_utils.c
