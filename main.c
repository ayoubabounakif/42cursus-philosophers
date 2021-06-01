#include "philo_one.h"

int	ft_strlen(const char *s)
{
	int	i;

	while(s[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	return (EXIT_SUCCESS);

}

int	ft_exit(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
// 	t_status	status;
	
	if (ac < 5 || ac > 6)
			return (ft_exit("Error: Bad arguments number!\nQuitting...\n"));

	return (EXIT_SUCCESS);
}
