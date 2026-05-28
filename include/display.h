/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:24:48 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 04:01:51 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "terminal.h"
# include <stdint.h>

# define NORMAL 1
# define INVERT 2
# define UNDERLINE 4

typedef enum e_color
{
	BLACK = 0,
	RED = 1,
	GREEN = 2,
	YELLOW = 3,
	BLUE = 4,
	PURPLE = 5,
	CYAN = 6,
	WHITE = 7
}		t_color;

void	set_style(t_terminal *term, uint8_t style, t_color color);
void	print_str(t_terminal *term, const char *s, uint col, uint row);
void	clear_screen(t_terminal *term);

#endif