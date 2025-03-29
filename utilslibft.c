#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_s;
	void	*tmp1;
	char	*s;

	total_s = count * size;
	if (total_s < count && total_s < size)
		return (NULL);
	tmp1 = malloc(total_s);
	if (!tmp1)
		return (NULL);
	s = (char *)tmp1;
	if (tmp1 != 0)
	{
		while (total_s--)
		{
			*s = 0;
			s++;
		}
	}
	return (tmp1);
}

size_t	ft_total_words(char const *str, char c1)
{
	size_t	nw;

	nw = 0;
	if (*str == '\0' || !str)
		return (0);
	else if (c1 == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str != c1)
		{
			while (*str != c1 && *str != '\0')
				str++;
			nw++;
		}
		if (*str != '\0')
			str++;
	}
	return (nw);
}

static void	wword(char c, char *array, char const *s)
{
	size_t	i1;

	i1 = 0;
	while (s[i1] != '\0' && s[i1] != c)
	{
		array[i1] = s[i1];
		i1++;
	}
	array[i1] = '\0';
}

int	search_str(char c, char const *s, char **array)
{
	size_t	w_len;
	size_t	nw;
	size_t	i2;

	i2 = 0;
	nw = 0;
	while (s[i2])
	{
		if (s[i2] == c)
			i2++;
		else
		{
			w_len = 0;
			while (s[i2 + w_len] && s[i2 + w_len] != c)
				w_len++;
			array[nw] = (char *)ft_calloc((w_len + 1), sizeof(char));
			if (array[nw] == NULL)
				return (free_str2(array, nw));
			wword(c, array[nw], s + i2);
			i2 = i2 + w_len;
			nw++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	nw;
	char	**result1;

	if (!s)
		return (NULL);
	nw = ft_total_words(s, c);
	result1 = (char **)ft_calloc((nw + 1), sizeof(result1));
	if (result1 == NULL)
		return (NULL);
	if (search_str(c, s, result1) == 0)
		return (NULL);
	result1[nw] = NULL;
	return (result1);
}


size_t	ft_strlen(const char *str)
{
	size_t	i1;

	i1 = 0;
	while (str[i1] != '\0')
		i1++;
	return (i1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result1;
	int		total;
	int		sl1;
	int		sl2;
	char	*s3;

	sl1 = ft_strlen(s1);
	sl2 = ft_strlen(s2);
	total = sl1 + sl2 + 1;
	if (!s1 && !s2)
		return (NULL);
	s3 = (char *)malloc(total * sizeof(char));
	if (!s3)
		return (0);
	result1 = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (result1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12
		|| str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}

int	free_str2(char **str2, int k1)
{
	while (k1 >= 0)
		free(str2[k1--]);
	free(str2);
	return (0);
}

int	ft_strfree(char **str1)
{
	int	i1;

	i1 = 0;
	while (str1[i1])
		i1++;
	while (i1 >= 0)
	{
		free(str1[i1]);
		i1--;
	}
	free(str1);
	return (0);
}


void	ft_putendl_fd(char *s, int fd)
{
	int	i1;

	i1 = 0;
	while (s[i1] != '\0')
	{
		write(fd, &s[i1], sizeof(char));
		i1++;
	}
	write(fd, "\n", 1);
}

int	ft_lstsize(t_list *list)
{
	int		i1;

	i1 = 0;
	while (list != NULL)
	{
		i1++;
		list = list -> next;
	}
	return (i1);
}

void	ft_listdelone(t_list *list)
{
	if (!list)
		return ;
	free(list);
}

void	ft_listclear(t_list **list)
{
	t_list		*step1;

	while (!*list)
		return ;
	while (*list)
	{
		step1 = (*list)->next;
		ft_listdelone(*list);
		*list = step1;
	}
	*list = NULL;
}


