/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:11:31 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 18:55:55 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include "terminal.h"
#include <stdlib.h>
#include <sys/types.h>

t_ctx	init_ctx(int argc, char **argv)
{
	t_ctx	ctx;
	uint	args_state_size;

	ft_bzero(&ctx, sizeof(ctx));
	ctx.term = init_terminal();
	if (!ctx.term.initialized)
		return (ctx);
	ctx.arg_count = argc - 1;
	ctx.args = argv + 1;
	args_state_size = ctx.arg_count / 4 + (ctx.arg_count % 4 != 0);
	ctx.args_state = malloc(sizeof(char) * args_state_size);
	ctx.hover_arg = 0;
	if (ctx.args_state)
		bzero(ctx.args_state, sizeof(char) * args_state_size);
	return (ctx);
}

void	destroy_ctx(t_ctx *ctx)
{
	restore_terminal(&ctx->term);
	free(ctx->args_state);
	ctx->args_state = NULL;
}
