/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:13:10 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 04:04:24 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H
# include "terminal.h"
# include <stdint.h>
# include <sys/types.h>

typedef enum e_state
{
	SELECTED = 1 << 0,
	DELETED = 1 << 1
}				t_state;

typedef struct s_grid
{
	uint		row;
	uint		col;
	uint8_t		is_displayable;
}				t_grid;

typedef struct s_ctx
{
	t_terminal	term;
	uint		choice_count;
	uint		alive_choice_count;
	char		**choices;
	char		*choice_state;
	uint		hover_choice;
	t_grid		grid;
}				t_ctx;

t_ctx			init_ctx(int argc, char **argv);
void			destroy_ctx(t_ctx *ctx);

#endif