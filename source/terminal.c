/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:09:38 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 02:52:27 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>

t_terminal	init_terminal(void)
{
	t_terminal	terminal;
	char		*term_type;

	bzero(&terminal, sizeof(t_terminal));
	term_type = getenv("TERM");
	if (!term_type || tgetent(terminal.buffer, term_type) != 1)
		return (terminal);
	tcgetattr(1, &terminal.old);
	terminal.new = terminal.old;
	terminal.new.c_lflag &= ~(ICANON | ECHO);
	terminal.new.c_cc[VTIME] = 0;
	terminal.new.c_cc[VMIN] = 1;
	terminal.initialized = 1;
	return (terminal);
}

void	enter_terminal(t_terminal *term)
{
	tcsetattr(1, 0, &term->new);
	ft_putstr_fd(tgetstr("ti", NULL), 1);
	ft_putstr_fd(tgetstr("vi", NULL), 1);
}

void	restore_terminal(t_terminal *term)
{
	ft_putstr_fd(tgetstr("ve", NULL), 1);
	ft_putstr_fd(tgetstr("te", NULL), 1);
	tcsetattr(1, 0, &term->old);
}

void	refresh_terminal(t_terminal *term)
{
	struct winsize win;
	ioctl(1, TIOCGWINSZ, &win);

	term->win.col = win.ws_col;
	term->win.row = win.ws_row;
}