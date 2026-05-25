/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:11:31 by ehode             #+#    #+#             */
/*   Updated: 2026/05/25 23:17:35 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include <stdlib.h>

t_ctx	init_ctx(int argc, char **argv)
{
	t_ctx	ctx;

	ctx.arg_count = argc - 1;
	ctx.args = argv + 1;
	ctx.args_state = malloc(sizeof(char) * ctx.arg_count / 4 + (ctx.arg_count
				% 4 != 0));
	return (ctx);
}

void	destroy_ctx(t_ctx *ctx)
{
	free(ctx->args_state);
	ctx->args_state = NULL;
}
