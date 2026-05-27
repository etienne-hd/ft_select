/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:58:15 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 00:41:19 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "ctx.h"
# include <sys/types.h>

void	toggle_arg_state(t_ctx *ctx, uint arg_number, uint8_t state);

#endif