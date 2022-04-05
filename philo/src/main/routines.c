/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:40:16 by proberto          #+#    #+#             */
/*   Updated: 2022/04/04 23:02:01 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static t_state	all_satisfied(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (simulation->philos[i])
	{
		if (simulation->philos[i]->satisfied == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	*life_monitoring(void *simulate)
{
	t_simulation	*simulation;
	int				i;

	simulation = simulate;
	i = 0;
	while (TRUE)
	{
		if (simulation->philos[i] == NULL)
			i = 0;
		if (get_time() - simulation->philos[i]->last_meal
			>= simulation->time_to_die)
		{
			usleep(500);
			print_status(simulation->philos[i], "died");
			simulation->all_alive = FALSE;
			break ;
		}
		else if (all_satisfied(simulation) == TRUE)
		{
			simulation->all_satisfied = TRUE;
			break ;
		}
		i++;
	}
	return (NULL);
}

static t_state	eating(t_philos *philosopher)
{
	int	i;

	pthread_mutex_lock(philosopher->lfork);
	print_status(philosopher, "has taken a fork");
	pthread_mutex_lock(philosopher->rfork);
	print_status(philosopher, "has taken a fork");
	if (get_time() - philosopher->last_meal
		>= philosopher->simulation->time_to_die)
		return (DEAD);
	print_status(philosopher, "is eating");
	philosopher->last_meal = get_time();
	philosopher->n_meals++;
	if (philosopher->n_meals == philosopher->simulation->n_times_to_eat)
		philosopher->satisfied = TRUE;
	while (get_time() - philosopher->last_meal
		< philosopher->simulation->time_to_eat)
		;
	pthread_mutex_unlock(philosopher->lfork);
	pthread_mutex_unlock(philosopher->rfork);
	return (ALIVE);
}

static t_state	sleeping(t_philos *philosopher)
{
	long	time;
	int		i;

	if (get_time() - philosopher->last_meal
		>= philosopher->simulation->time_to_die)
		return (DEAD);
	else if (philosopher->simulation->all_satisfied == TRUE)
		return (ALL_SATISFIED);
	print_status(philosopher, "is sleeping");
	time = get_time();
	while (get_time() - time < philosopher->simulation->time_to_sleep)
		;
	return (ALIVE);
}

void	*routine(void *philosopher)
{
	t_philos	*philo;

	philo = philosopher;
	if (philo->simulation->n_philosophers == 1)
	{
		print_status(philosopher, "has taken a fork");
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->n_meals != philo->simulation->n_times_to_eat
		&& philo->simulation->all_alive)
	{
		if (eating(philo) != ALIVE)
			break ;
		if (sleeping(philo) != ALIVE)
			break ;
		if (philo->simulation->all_alive == TRUE
			&& philo->simulation->all_satisfied == FALSE)
			print_status(philosopher, "is thinking");
	}
	return (NULL);
}
