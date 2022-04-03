/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:40:41 by proberto          #+#    #+#             */
/*   Updated: 2022/04/03 11:26:58 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	input_validation(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	if (argc > 6)
		return (error_msg("too many arguments"));
	else if (argc < 5)
		return (error_msg("too few arguments"));
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == FALSE)
				return (error_msg("invalid argument, try only "
						"(positive) numbers"));
			j++;
		}
		if (ft_atoi(argv[i]) < 1)
			return (error_msg("invalid argument, try numbers greater than 0"));
		i++;
	}
	return (TRUE);
}
