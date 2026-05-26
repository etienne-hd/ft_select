/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:30:02 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 00:36:56 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include "select.h"
#include "terminal.h"
#include <sys/types.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc == 1)
		return (0);
	ctx = init_ctx(argc, argv);
	if (!ctx.choice_state)
	{
		ft_putstr_fd("Unable to init ctx.\n", 2);
		return (1);
	}
	enter_terminal(&ctx.term);
	if (ft_select(&ctx) == 2)
		show_selected(&ctx);
	destroy_ctx(&ctx);
}
