#include "libft.h"

void	ft_exit_message(char *message)
{
	ft_dprintf(STDERR_FILENO, "%s\n", message);
	exit(EXIT_FAILURE);
}
