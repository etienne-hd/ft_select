/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:09:38 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 00:48:25 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <termcap.h>
#include <termios.h>

t_terminal	init_terminal(void)
{
	t_terminal	terminal;
	char		*term_type;

	bzero(&terminal, sizeof(t_terminal));
	terminal.fd = open("/dev/tty", O_RDWR);
	if (terminal.fd == -1)
		return (terminal);
	term_type = getenv("TERM");
	if (!term_type || tgetent(terminal.buffer, term_type) != 1)
		return (terminal);
	tcgetattr(terminal.fd, &terminal.old);
	terminal.new = terminal.old;
	terminal.new.c_lflag &= ~(ICANON | ECHO);
	terminal.new.c_cc[VTIME] = 0;
	terminal.new.c_cc[VMIN] = 1;
	terminal.initialized = 1;
	return (terminal);
}

void	enter_terminal(t_terminal *term)
{
	tcsetattr(term->fd, 0, &term->new);
	ft_putstr_fd(tgetstr("ti", NULL), term->fd);
	ft_putstr_fd(tgetstr("vi", NULL), term->fd);
}

void	restore_terminal(t_terminal *term)
{
	ft_putstr_fd(tgetstr("ve", NULL), term->fd);
	ft_putstr_fd(tgetstr("te", NULL), term->fd);
	tcsetattr(term->fd, 0, &term->old);
	if (term->fd != 0)
		close(term->fd);
}

void	refresh_terminal(t_terminal *term)
{
	struct winsize	win;

	ioctl(term->fd, TIOCGWINSZ, &win);
	term->win.col = win.ws_col;
	term->win.row = win.ws_row;
}
