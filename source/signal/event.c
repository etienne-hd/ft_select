/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:35 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 03:49:46 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "select.h"
#include "sig.h"
#include "terminal.h"
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

void	on_resize(t_ctx *ctx)
{
	refresh_terminal(&ctx->term);
	render(ctx);
}

void	on_quit(t_ctx *ctx)
{
	char	c;

	c = 27;
	ioctl(ctx->term.fd, TIOCSTI, &c);
	exit_terminal(&ctx->term);
}

void	on_stop(t_ctx *ctx)
{
	char	c;

	c = 26;
	signal(SIGTSTP, 0);
	signal(SIGCONT, signal_handler);
	ioctl(ctx->term.fd, TIOCSTI, &c);
	exit_terminal(&ctx->term);
}

void	on_continue(t_ctx *ctx)
{
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, 0);
	enter_terminal(&ctx->term);
	refresh_terminal(&ctx->term);
	render(ctx);
}
