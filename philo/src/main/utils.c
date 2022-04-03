/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:26:43 by proberto          #+#    #+#             */
/*   Updated: 2022/04/03 10:46:11 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	res = i;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\f' || *(str + i) == '\n'
		|| *(str + i) == '\r' || *(str + i) == '\t' || *(str + i) == '\v')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (ft_isdigit(str[i]))
		res = res * 10 + (*(str + i++) - '0');
	if (LONG_MIN / 10 >= res && sign == 1)
		return ((int)LONG_MAX);
	else if (LONG_MIN / 10 >= res && sign == -1)
		return ((int)LONG_MIN);
	return ((int)res * sign);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*free_philos(t_philos **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		free(philos[i]);
		i++;
	}
	if (philos)
		free(philos);
	return (NULL);
}

void	*free_forks(pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	while (forks[i])
	{
		free(forks[i]);
		i++;
	}
	if (forks)
		free(forks);
	return (NULL);
}
