/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:36:57 by proberto          #+#    #+#             */
/*   Updated: 2022/04/03 10:49:49 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{	
	t_simulation	simulation;

	if (input_validation(argc, argv) == FALSE)
		return (1);
	if (simulation_setup(&simulation, argv) == FALSE)
		return (1);
	philosophers_setup(&simulation);
	if (simulation.philos == NULL)
		return (1);
	create_threads_simulation(&simulation);
	start_threads_simulation(&simulation);
	free_philos(simulation.philos);
	free_forks(simulation.forks);
	return (0);
}
