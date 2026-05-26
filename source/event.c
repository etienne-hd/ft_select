/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:35 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 18:37:34 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "select.h"
#include <sys/ioctl.h>

void	on_resize(t_ctx *ctx)
{
	refresh_terminal(&ctx->term);
	render(ctx);
}
