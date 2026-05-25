/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:35 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 01:37:29 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "select.h"
#include <sys/ioctl.h>

void	on_resize(t_ctx *ctx)
{
	struct winsize win;
	ioctl(1, TIOCGWINSZ, &win);

	ctx->term.win.col = win.ws_col;
	ctx->term.win.row = win.ws_row;

	render(ctx);
}