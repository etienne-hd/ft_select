/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:13:10 by ehode             #+#    #+#             */
/*   Updated: 2026/05/25 23:50:04 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H
# include "terminal.h"
# include <sys/types.h>

typedef enum e_state
{
	UNSELECTED,
	DELETED
}				t_state;

typedef struct s_ctx
{
	t_terminal	terminal;
	uint		arg_count;
	char		**args;
	char		*args_state;
}				t_ctx;

t_ctx			init_ctx(int argc, char **argv);
void			destroy_ctx(t_ctx *ctx);

#endif