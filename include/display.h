#ifndef DISPLAY_H
# define DISPLAY_H
# include "select.h"
# include "terminal.h"

void	set_style(t_terminal *term, t_text_style style);
void	print_str(t_terminal *term, const char *s, uint col, uint row);
void	clear_screen(t_terminal *term);

#endif