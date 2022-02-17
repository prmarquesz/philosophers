/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:40:41 by proberto          #+#    #+#             */
/*   Updated: 2022/02/17 19:28:09 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	error_msg(char *msg)
{
	printf("%sError: %s%s\n", RED, msg, RESET);
	return (FALSE);
}

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

int	input_validation(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
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
		if (ft_atoi(argv[i]) < 0)
			return (error_msg("invalid argument, try numbers between 1 and "
					"2147483647"));
		i++;
	}
	return (TRUE);
}
