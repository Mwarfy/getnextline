#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *rest;
	char buf[BUFF_SIZE + 1];
	char *str;
	int ret;
	
	ret = 0;
	if(!line)
		return (-1);
	ft_memdel((void**)line);
	str = ft_strnew(0);
	if(rest)
	{
		str = ft_strdup(rest);
		ft_memdel((void**)rest);
		if(ft_check(str, line) > 0)
		{
			rest = ft_strchr(str, '\n');
			ret++;
		}
	}
	if(ret == 0)
	{
		while((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = 0;
			str = ft_strjoin(str, ft_strdup(buf));
			if((rest = ft_strchr(ft_strdup(buf), '\n')))
				break;
		}
		ft_split_line(str, line);
	}
	if(ret == 0 && (ft_strlen(*line) > 0))
		return (1);
	return (ret);
}

void	ft_split_line(char *str, char **line)
{
	int i;
	int j;
	char *str2;

	str2 = ft_strnew(0);
	j = 0;
	i = -1;
	while(str[++i])
	{
		if(str[i] == '\n')
		{
			str2[i] = 0;
			j++;
			break;
		}
		str2[i] = str[i];
	}
	*line = str2;
}

int		ft_check(char *str, char **line)
{
	int i;
	int ret;
	char *str1;

	str1 = ft_strnew(0);
	ret = 0;
	i = -1;
	while(str[++i])
	{
		if(str[i] == '\n')
		{
			str1[i] = 0;
			ret = 1;
			break;
		}	
		str1[i] = str[i];
	}
	*line = str1;
	return(ret);
}

/*int 	main(void)
{
	char *line;
	int ret;
	int fd;
	int count;

	fd = open("test", O_RDONLY);
	if(fd > 2)
	{
		count = 0;
		line = NULL;
		while((ret = get_next_line(fd, &line)) > 0)
		{
			count++;
			printf("%s", line);
			if (count > 50)
				break;
		}
		close(fd);
		printf("\n%d\n", count);
	}
	return (0);
}*/
