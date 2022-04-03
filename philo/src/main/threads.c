/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:08:39 by proberto          #+#    #+#             */
/*   Updated: 2022/04/01 22:08:11 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	create_threads_simulation(t_simulation *simulation)
{
	int	i;

	i = 0;
	pthread_mutex_init(&simulation->mutex, NULL);
	pthread_create(&simulation->th_monitor, NULL, life_monitoring, simulation);
	while (simulation->philos[i])
	{
		pthread_mutex_init(simulation->forks[i], NULL);
		pthread_create(&simulation->philos[i]->th, NULL, routine,
			simulation->philos[i]);
		i++;
	}
}

void	start_threads_simulation(t_simulation *simulation)
{
	int	i;

	i = 0;
	pthread_join(simulation->th_monitor, NULL);
	while (simulation->philos[i])
	{
		pthread_join(simulation->philos[i]->th, NULL);
		pthread_mutex_destroy(simulation->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&simulation->mutex);
}
