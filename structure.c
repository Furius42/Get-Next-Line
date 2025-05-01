structure 




Function receives FD
	->	Check if FD is valid
	look up if FD is in list 
		not in list	->	list_newline -> New FD * Start of fil = NEXTLINE_START // go to next line -v
		is in list	->	take last NEXTLINE_START

Call FILL BUFFER
	Take 



int	fill_buffer(int fd, char *line_start);
	while(node->next)
		read(fd, node_current->buffer, BUFFER_SIZE); // how to tell read from which character it should start reading???????? how to pass char *line_start??

char	*parse_buffer(char* line, int line_len)


line = malloc(sizeof(char) * fill_buffer(fd_list.fd, fd_list.start));

return(parse_buffer(line, last_line_len));