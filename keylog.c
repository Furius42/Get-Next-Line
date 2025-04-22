/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keylog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:33:35 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/22 23:26:07 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pty.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int master_fd;
	pid_t pid;
	char buffer[1024];
	FILE *log_file = fopen("session.log", "a");

	if (!log_file) {
		perror("fopen");
		return 1;
	}

	pid = forkpty(&master_fd, NULL, NULL, NULL);
	if (pid == -1) {
		perror("forkpty");
		return 1;
	}

	if (pid == 0) {
		// Child: run shell
		execl("/bin/zsh", "zsh", NULL);
		perror("execl");
		exit(1);
	}

	// Parent: forward input/output and log
	fd_set fds;
	while (1) {
		FD_ZERO(&fds);
		FD_SET(master_fd, &fds);
		FD_SET(STDIN_FILENO, &fds);
		int maxfd = master_fd > STDIN_FILENO ? master_fd : STDIN_FILENO;

		if (select(maxfd + 1, &fds, NULL, NULL, NULL) < 0) {
			perror("select");
			break;
		}

		if (FD_ISSET(STDIN_FILENO, &fds)) {
			ssize_t n = read(STDIN_FILENO, buffer, sizeof(buffer));
			if (n <= 0) break;
			write(master_fd, buffer, n);
		}

		if (FD_ISSET(master_fd, &fds)) {
			ssize_t n = read(master_fd, buffer, sizeof(buffer));
			if (n <= 0) break;
			write(STDOUT_FILENO, buffer, n);
			fwrite(buffer, 1, n, log_file);
			fflush(log_file);
		}
	}

	fclose(log_file);
	return 0;
}
