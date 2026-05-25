/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:30:02 by ehode             #+#    #+#             */
/*   Updated: 2026/05/25 23:12:18 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include <termcap.h>
#include <termios.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc == 1)
		return (0);
	ctx = init_ctx(argc, argv);
	if (!ctx.args)
	{
		ft_putstr_fd("Unable to init ctx.", 2);
		return (1);
	}
	destroy_ctx(&ctx);
}
