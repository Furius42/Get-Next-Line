int	read_into_buf(t_buf_node *cur)
{
	int	i;
	int	len;
	int	b_read;

	while ((b_read = read(cur->fd, cur->buf + cur->buf_len,
			BUFFER_SIZE - cur->buf_len)) > 0)
	{
		cur->buf_len += b_read;
		i = linelen(cur->buf, '\n', cur->buf_len);
		if (i == 0)
		{
			len += cur->buf_len;
			if(cur->buf_len == BS)
				cur = node_ops(cur, cur->fd, 'a');
		}
		else
		{
			len += i;
			break;
		}
	}
	i = 0;
}
int	read_into_buf(t_buf_node *cur)
{
	int	i;
	int	len;
	int	b_read;

	len = 0;
	while ((b_read = read(cur->fd, cur->buf + cur->buf_len,
			BS - cur->buf_len)) > 0)
	{
		cur->buf_len += b_read;
		i = linelen(cur->buf, '\n', cur->buf_len);
		if (i == 0)
		{
			len += cur->buf_len;
			if (cur->buf_len == BS)
				cur = node_ops(cur, cur->fd, 'a');
		}
		else
		{
			len += i;
			break;
		}
	}
	if ((cur->buf_len == 0 && b_read == 0) || b_read < 0)
	{
		node_ops(cur, cur->fd, 'd');
		return (NULL);
	}
	return (len);
}

