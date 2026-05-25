/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:09:38 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 00:09:47 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <stdlib.h>
#include <termcap.h>
#include <termios.h>

t_terminal	init_terminal(void)
{
	t_terminal	terminal;
	char		*term_type;

	bzero(&terminal, sizeof(t_terminal));
	term_type = getenv("TERM");
	if (!term_type || tgetent(terminal.buffer, term_type) != 1)
		return (terminal);
	tcgetattr(1, &terminal.old);
	terminal.new.c_lflag &= ~(ICANON | ECHO);
	terminal.new.c_cc[VTIME] = 1;
	terminal.new.c_cc[VMIN] = 0;
	tcsetattr(1, 0, &terminal.new);
	terminal.initialized = 1;
	return (terminal);
}

void	restore_terminal(t_terminal *terminal)
{
	tcsetattr(1, 0, &terminal->old);
}
