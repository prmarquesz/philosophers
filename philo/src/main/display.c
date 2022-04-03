/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:11:49 by proberto          #+#    #+#             */
/*   Updated: 2022/04/01 22:24:45 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	error_msg(char *msg)
{
	printf("%sError: %s%s\n", RED, msg, RESET);
	return (FALSE);
}

void	print_status(t_philos *philosopher, char *status)
{
	char	*color;
	long	time;

	time = get_time() - philosopher->simulation->start_time;
	if (philosopher->id % 2 == 0)
		color = BLUE;
	else
		color = YELLOW;
	if (philosopher->simulation->all_alive)
		printf("%s%ld %d %s%s\n", color, time, philosopher->id, status, RESET);
}
