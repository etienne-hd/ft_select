#ifndef TERMINAL_H
# define TERMINAL_H
# include <strings.h>
# include <termios.h>

typedef struct s_terminal
{
	char			buffer[2048];
	struct termios	old;
	struct termios	new;
	char			initialized;
}					t_terminal;

t_terminal			init_terminal(void);
void				restore_terminal(t_terminal *terminal);

#endif