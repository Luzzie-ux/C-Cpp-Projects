#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum	e_action{
				COMPILE,
				DEBUG,
				REFACTOR,
}				t_action;

typedef enum	e_schedule{
				FIFO,
				LIFO,
				EDF,
}				t_schedule;

typedef unsigned int t_bool;

typedef struct	s_dongle{
	size_t		id;
	t_bool		is_taken;
	size_t		cooldown;
}				t_dongle;

typedef struct	s_coder{
	pthread_t	thread;
	size_t		id;
	t_action	action;
	t_dongle	*left;
	t_dongle	*right;
	time_t 		deadline;
	time_t 		last_compile;
	time_t		internal_clock;
}				t_coder;

typedef struct	s_table{
	t_schedule	schedule;
	t_coder		*coders;
	t_dongle	*dongles;
	size_t		elements;
	time_t		burnout;
	time_t		compile;
	time_t		debug;
	time_t		refactor;
	size_t 		nbr_compiles;
	time_t 		dongle_cooldown;
	time_t		total_time;
}				t_table;

	//		Parsing Methods		//
int		parser(t_table *table, char **argv);
int		error(int status);
int		usage(void);

	//		String Methods		//
size_t	ft_strlen(const char *s);
int 	ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int 	ft_atoi(const char *nptr);
long 	ft_atol(const char *nptr);

	//		Memory Methods		//
void 	*ft_memset(void *s, int c, size_t n);

	//		Coder Methods		//
	//		Dongle Methods		//
	//		Table Methods		//
	//		Time Methods		//

/*
◦ timestamp_in_ms X has taken a dongle
◦ timestamp_in_ms X is compiling
◦ timestamp_in_ms X is debugging
◦ timestamp_in_ms X is refactoring
◦ timestamp_in_ms X burned out
*/

/*EXTERNAL ALLOWED FUNCTIONS:
pthread_create, pthread_join, pthread_mutex_init,
pthread_mutex_lock,
pthread_mutex_unlock, pthread_mutex_destroy,
pthread_cond_init,
pthread_cond_wait, pthread_cond_timedwait,
pthread_cond_signal,
pthread_cond_broadcast, pthread_cond_destroy,
gettimeofday, clock_gettime,
usleep, write, malloc, free, printf, fprintf,
strcmp, strlen, atoi, memset
*/

#endif /*CODEXION_H*/
