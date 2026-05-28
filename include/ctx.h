/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:13:10 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 03:59:41 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H
# include "terminal.h"
# include <stdint.h>
# include <sys/types.h>

# define SEARCH_SIZE 255

# define SELECTED 1
# define DELETED 2
# define SEARCHED 4

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
	char		search[SEARCH_SIZE + 1];
	uint		search_cursor;
	t_grid		grid;
}				t_ctx;

void			init_ctx(t_ctx *ctx, int argc, char **argv);
void			destroy_ctx(t_ctx *ctx);

#endif