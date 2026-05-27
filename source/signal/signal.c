/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:46 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 02:52:16 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "select.h"
#include "sig.h"
#include <signal.h>
#include <stdint.h>
#include <sys/types.h>

t_ctx	*g_ctx;

void	signal_handler(int signal)
{
	static void	(*func[])(t_ctx *) = {[SIGCONT] = on_continue,
			[SIGTSTP] = on_stop, [SIGWINCH] = on_resize, [SIGINT] = on_quit,
			[SIGQUIT] = on_quit, [SIGILL] = on_quit, [SIGTRAP] = on_quit,
			[SIGABRT] = on_quit, [SIGFPE] = on_quit, [SIGKILL] = on_quit,
			[SIGBUS] = on_quit, [SIGSEGV] = on_quit, [SIGSYS] = on_quit,
			[SIGPIPE] = on_quit, [SIGALRM] = on_quit, [SIGTERM] = on_quit,
			[SIGUSR1] = on_quit, [SIGUSR2] = on_quit, [SIGPWR] = on_quit,
			[SIGPOLL] = on_quit, [SIGVTALRM] = on_quit, [SIGPROF] = on_quit,
			[SIGXCPU] = on_quit, [SIGXFSZ] = on_quit};

	if (func[signal])
		func[signal](g_ctx);
}

void	init_signal(t_ctx *ctx)
{
	const int	handled_signals[] = {SIGWINCH, SIGTSTP, SIGINT, SIGQUIT, SIGILL,
			SIGTRAP, SIGABRT, SIGFPE, SIGBUS, SIGSEGV, SIGSYS, SIGPIPE, SIGALRM,
			SIGTERM, SIGUSR1, SIGUSR2, SIGPWR, SIGPOLL, SIGVTALRM, SIGPROF,
			SIGXCPU, SIGXFSZ, -1};
	uint8_t		i;

	g_ctx = ctx;
	signal(SIGCONT, 0);
	i = 0;
	while (handled_signals[i] != -1)
		signal(handled_signals[i++], signal_handler);
}
