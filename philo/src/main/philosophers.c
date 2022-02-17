/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:36:57 by proberto          #+#    #+#             */
/*   Updated: 2022/02/17 11:22:28 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char **argv)
{	
	t_philo	philo;

	if (input_validation(argc, argv) == FALSE)
		return (1);
	init_philo(&philo, argv);
	return (0);
}
