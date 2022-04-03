/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:37:45 by proberto          #+#    #+#             */
/*   Updated: 2022/04/03 11:29:44 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	simulation_setup_sub(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->n_philosophers)
	{
		simulation->forks[i] = malloc(sizeof(pthread_mutex_t));
		if (simulation->forks[i] == NULL)
		{
			free_forks(simulation->forks);
			return (error_msg("malloc failed"));
		}
		i++;
	}
	simulation->forks[i] = NULL;
	return (TRUE);
}

int	simulation_setup(t_simulation *simulation, char **argv)
{
	simulation->n_philosophers = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		simulation->n_times_to_eat = ft_atoi(argv[5]);
	else
		simulation->n_times_to_eat = -1;
	simulation->philos = NULL;
	simulation->all_alive = TRUE;
	simulation->all_satisfied = FALSE;
	simulation->forks = (pthread_mutex_t **)
		malloc((simulation->n_philosophers + 1) * sizeof(pthread_mutex_t *));
	if (simulation->forks == NULL)
		return (error_msg("Error: malloc failed"));
	if (simulation_setup_sub(simulation) == FALSE)
		return (FALSE);
	return (TRUE);
}

static void	philosophers_setup_sub(t_simulation *simulation, int i)
{
	simulation->philos[i]->id = i + 1;
	simulation->philos[i]->n_meals = 0;
	simulation->philos[i]->satisfied = FALSE;
	simulation->philos[i]->simulation = simulation;
	simulation->philos[i]->last_meal = get_time();
	simulation->start_time = get_time();
	if (i == 0)
	{
		if (simulation->n_philosophers > 1)
			simulation->philos[i]->rfork
				= simulation->forks[simulation->n_philosophers - 1];
		simulation->philos[i]->lfork = simulation->forks[i];
	}
	else
	{
		simulation->philos[i]->rfork = simulation->forks[i - 1];
		simulation->philos[i]->lfork = simulation->forks[i];
	}
}

int	philosophers_setup(t_simulation *simulation)
{
	int	i;

	simulation->philos = (t_philos **)
		malloc((simulation->n_philosophers + 1) * sizeof(t_philos *));
	if (simulation->philos == NULL)
	{
		free_forks(simulation->forks);
		return (error_msg("malloc failed"));
	}
	i = 0;
	while (i < simulation->n_philosophers)
	{
		simulation->philos[i] = (t_philos *)malloc(sizeof(t_philos));
		if (simulation->philos[i] == NULL)
		{
			free_philos(simulation->philos);
			free_forks(simulation->forks);
			return (error_msg("malloc failed"));
		}
		philosophers_setup_sub(simulation, i);
		i++;
	}
	simulation->philos[i] = NULL;
	return (TRUE);
}
