/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:46 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 18:40:22 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "select.h"
#include <signal.h>

t_ctx		*g_ctx;

static void	signal_handler(int signal)
{
	static void	(*func[])(t_ctx *) = {[SIGWINCH] = on_resize};

	if (func[signal])
		func[signal](g_ctx);
}

void	init_signal(t_ctx *ctx)
{
	g_ctx = ctx;
	signal(SIGWINCH, signal_handler);
}
