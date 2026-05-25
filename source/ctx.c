/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:11:31 by ehode             #+#    #+#             */
/*   Updated: 2026/05/25 23:42:12 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include "terminal.h"
#include <stdlib.h>

t_ctx	init_ctx(int argc, char **argv)
{
	t_ctx	ctx;

	ft_bzero(&ctx, sizeof(ctx));
	ctx.terminal = init_terminal();
	if (!ctx.terminal.initialized)
		return (ctx);
	ctx.arg_count = argc - 1;
	ctx.args = argv + 1;
	ctx.args_state = malloc(sizeof(char) * ctx.arg_count / 4 + (ctx.arg_count
				% 4 != 0));
	return (ctx);
}

void	destroy_ctx(t_ctx *ctx)
{
	restore_terminal(&ctx->terminal);
	free(ctx->args_state);
	ctx->args_state = NULL;
}
