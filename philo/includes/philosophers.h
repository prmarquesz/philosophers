/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:35:34 by proberto          #+#    #+#             */
/*   Updated: 2022/04/02 23:14:24 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h> 
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h> 

# define TRUE 1
# define FALSE 0

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LONG_MAX 2147483647
# define LONG_MIN -2147483648

# define YELLOW "\001\033[1;33m\002"
# define RED "\001\033[1;31m\002"
# define GREEN "\001\033[1;32m\002"
# define BLUE "\001\033[1;36m\002"
# define RESET "\001\033[0m\002"

typedef struct s_philos	t_philos;

typedef struct s_simulation {
	int				n_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_to_eat;
	int				all_alive;
	int				all_satisfied;
	long			start_time;
	t_philos		**philos;
	pthread_t		th_monitor;
	pthread_mutex_t	**forks;
	pthread_mutex_t	mutex;
}					t_simulation;

typedef struct s_philos {
	int				id;
	int				n_meals;
	int				satisfied;
	long			last_meal;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_t		th;
	t_simulation	*simulation;
}					t_philos;

typedef enum e_state {
	ALL_SATISFIED,
	ALIVE,
	DEAD
}	t_state;

/**
 * main flow
 */
int		input_validation(int argc, char **argv);

/**
 * setup
 */
int		simulation_setup(t_simulation *simulation, char **argv);
int		philosophers_setup(t_simulation *simulation);

/**
 * threads
 */
void	create_threads_simulation(t_simulation *simulation);
void	start_threads_simulation(t_simulation *simulation);

/**
 * routines
 */
void	*routine(void *philosopher);
void	*life_monitoring(void *simulate);

/**
 * display
 */
int		error_msg(char *msg);
void	print_status(t_philos *philosopher, char *status);

/**
 * utils
 */
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
long	get_time(void);
void	*free_philos(t_philos **philos);
void	*free_forks(pthread_mutex_t **forks);

#endif
