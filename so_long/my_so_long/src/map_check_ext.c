
#include "../include/so_long.h"

int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	if (ext[0] != '.')
		exit_err("Invalid function parameter. ext[0] must be 'dot' charter\n");
	i = ft_strlen(str) - ft_strlen(ext);
	if (i <= 0 || str[i] != '.')
		exit_err("Wrong extension or file path.\n");
	j = 0;
	while (str[i + j] != '\0' && ext[j] != '\0')
	{
		if (str[i + j] == ext[j])
			j++;
		else
			break ;
	}
	if (!(str[i + j] == '\0' && ext[j] == '\0'))
		exit_err("Wrong extension or file path.\n");
	return (TRUE);
}
