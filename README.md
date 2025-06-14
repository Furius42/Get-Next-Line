# Get-Next-Line

Moved on quite a bunch here..
Switching between two FDs works fine, lines print with no problem.

Un/known issues:

got into infinite loop in read_into_buf in relayed test at last level / after H in end.txt
end of a file cleanup in case of multiple fds .. freeing of a head for a finished FD
behavior of fd0
restults of francinette tests for edge cases.. buffer sizes, huge files, etc..
norminette reformatting.. will do that once all bugs are caught and i need no more printf's and comments in functions

