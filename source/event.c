/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:35 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 18:55:22 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "key_parser.h"
#include "select.h"
#include <sys/ioctl.h>
#include <unistd.h>

void	on_resize(t_ctx *ctx)
{
	refresh_terminal(&ctx->term);
	render(ctx);
}

void	on_key(t_ctx *ctx, t_key *key)
{
	if (key->code == KEY_ARROW_LEFT)
		ctx->hover_arg -= 1;
	else if (key->code == KEY_ARROW_RIGHT)
		ctx->hover_arg += 1;
}