/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:09:11 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 01:45:26 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include <strings.h>
# include <sys/types.h>
# include <termios.h>

typedef struct s_win
{
	uint			col;
	uint			row;
}					t_win;

typedef struct s_terminal
{
	char			buffer[2048];
	struct termios	old;
	struct termios	new;
	char			initialized;
	t_win			win;
	int				fd;
}					t_terminal;

t_terminal			init_terminal(void);
void				enter_terminal(t_terminal *term);
void				exit_terminal(t_terminal *term);
void				destroy_terminal(t_terminal *term);
void				refresh_terminal(t_terminal *term);

#endif