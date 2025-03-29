#include "push_swap.h"

int	check_max_min(char *str1)
{
	long	plnum;
	int		i1;
	int		sign;

	plnum = 0;
	i1 = 0;
	sign = 1;
	while ((str1[i1] >= 9 && str1[i1] <= 13) || str1[i1] == 32)
		i1++;
	if (str1[i1] == '+' || str1[i1] == '-')
	{
		if (str1[i1++] == '-')
			sign = -1 * sign;
	}
	while (str1[i1] >= '0' && str1[i1] <= '9')
		plnum = (str1[i1++] - '0') + (plnum * 10);
	if ((sign * plnum) > 2147483647 || (sign * plnum) < -2147483648)
		return (0);
	return (1);
}

int	check_number(char *str1)
{
	int	j1;

	j1 = 0;
	if ((str1[j1] == '+' || str1[j1] == '-') && (str1[j1 + 1] >= '0'
			&& str1[j1 + 1] <= '9'))
		j1++;
	while (str1[j1])
	{
		while (str1[j1] == '\t' || str1[j1] == ' ')
			j1++;
		if ((str1[j1] == '+' || str1[j1] == '-') && !(str1[j1 - 1]))
			j1++;
		if (str1[j1] < '0' || str1[j1] > '9')
			return (0);
		j1++;
	}
	return (1);
}

int	total_check_number(char **args)
{
	int	i1;
	int	i2;
	int	j2;

	if (!args)
	{
		ft_strfree(args);
		return (0);
	}
	i1 = -1;
	while (args[++i1])
		if (!check_number(args[i1]) || !check_max_min(args[i1]))
			return (0);
	i2 = -1;
	while (args[++i2])
	{
		j2 = i2;
		while (args[++j2])
			if (ft_atoi(args[i2]) == ft_atoi(args[j2]))
				return (0);
	}
	return (1);
}

int	total_check_sort(char **args)
{
	int	i2;
	int	j2;

	if (!args)
	{
		ft_strfree(args);
		return (0);
	}
	i2 = -1;
	while (args[++i2])
	{
		j2 = i2;
		while (args[++j2])
			if (ft_atoi(args[i2]) > ft_atoi(args[j2]))
				return (0);
	}
	return (1);
}

char	**is_valid(int argc, char **argv, int j)
{
	char	**sta1;
	char	*str0;
	char	*str1;
	char	*str2;

	str0 = "";
	while (j < argc)
	{
		str1 = str0;
		str0 = ft_strjoin(str1, argv[j++]);
		str2 = str0;
		str0 = ft_strjoin(str2, " ");
		free(str2);
		if (j > 2)
			free(str1);
	}
	sta1 = ft_split(str0, ' ');
	free(str0);
	if (*sta1 == NULL || !total_check_number(sta1))
	{
		ft_strfree(sta1);
		ft_putendl_fd("Error", STDERR_FILENO);
		return (NULL);
	}
	return (sta1);
}


t_list	*create_node(char *arg)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->value1 = ft_atoi(arg);
	node->next = NULL;
	return (node);
}

t_list	*add_input2list(char **arg, int i1)
{
	t_list	*list;
	t_list	*temp2;
	t_list	*temp3;

	list = NULL;
	while (arg[++i1])
	{
		temp2 = create_node(arg[i1]);
		if (temp2 == NULL)
			return (NULL);
		if (list == NULL)
			list = temp2;
		else
		{
			temp3 = list;
			while (temp3->next != NULL)
				temp3 = temp3->next;
			temp3->next = temp2;
		}
	}
	return (list);
}

int	*sorting_elem(t_list **sa, int num_num, int n)
{
	int		*array;
	t_list	*temp;
	int		step1;
	int		k1;
	int		i1;

	array = (int *)malloc(num_num * sizeof(int));
	if (!array)
		return (NULL);
	temp = *sa;
	while (temp != NULL)
	{
		array[n++] = temp->value1;
		temp = temp->next;
	}
	step1 = 0;
	while (++step1 < num_num)
	{
		k1 = array[step1];
		i1 = step1;
		while (--i1 >= 0 && k1 < array[i1])
			array[i1 + 1] = array[i1];
		array[i1 + 1] = k1;
	}
	return (array);
}

void	insertion_2vector(t_list **sa)
{
	int		*array;
	int		num_num;
	int		i1;
	t_list	*temp1;

	num_num = ft_lstsize(*sa);
	array = sorting_elem(sa, num_num, 0);
	temp1 = *sa;
	while (temp1 != NULL)
	{
		i1 = -1;
		while (++i1 < num_num)
		{
			if (temp1->value1 == array[i1])
			{
				temp1->index1 = i1;
				break ;
			}
		}
		temp1 = temp1->next;
	}
	free(array);
}

int	free_stacka(t_list **sa)
{
	if (sa && *sa)
		ft_listclear(sa);
	return (0);
}

t_list	*get_last_elm(t_list *list)
{
	if (list == NULL)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	rotate_list(t_list **list)
{
	t_list	*second;
	t_list	*last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	second = *list;
	*list = (*list)->next;
	last = get_last_elm(*list);
	second->next = NULL;
	last->next = second;
}

void	rotate_abr(t_list **list_a, int is_ab)
{
	if (is_ab == 1)
		write(1, "ra\n", 3);
	else if (is_ab == 2)
		write(1, "rb\n", 3);
	rotate_list(list_a);
}

void	rev_rotate_list(t_list **list)
{
	t_list	*second_last;
	t_list	*last;

	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	second_last = *list;
	last = (*list)->next;
	while (last->next != NULL)
	{
		last = last->next;
		*list = (*list)->next;
	}
	last->next = second_last;
	(*list)->next = NULL;
	*list = last;
}

void	rev_rotate_abrr(t_list **list_a, int is_ab)
{
	if (is_ab == 1)
		write(1, "rra\n", 4);
	else if (is_ab == 2)
		write(1, "rrb\n", 4);
	rev_rotate_list(list_a);
}


void	swap_any_list(t_list **list)
{
	t_list	*second;
	t_list	*third;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	second = (*list)->next;
	third = second->next;
	(*list)->next = third;
	second->next = *list;
	*list = second;
}

void	swap_ab(t_list **list_a, int is_ab)
{
	if (is_ab == 1)
		write(1, "sa\n", 3);
	else if (is_ab == 2)
		write(1, "sb\n", 3);
	swap_any_list(list_a);
}

t_list	*delete_first(t_list *list)
{
	t_list	*temp;

	if (list == NULL)
		return (list);
	temp = list->next;
	list = temp;
	return (temp);
}

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (*list_a == NULL)
		return ;
	temp = *list_a;
	*list_a = delete_first(*list_a);
	temp->next = *list_b;
	*list_b = temp;
}

void	push_ab(t_list **list_a, t_list **list_b, int is_ab)
{
	if (is_ab == 1)
	{
		write(1, "pa\n", 3);
		push_b(list_b, list_a);
	}
	else if (is_ab == 2)
	{
		write(1, "pb\n", 3);
		push_b(list_a, list_b);
	}
}



void	sort_3elem(t_list **list, int is_ab, int a2, int a3)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *list;
	b = a->next;
	a2 = b->value1;
	c = b->next;
	a3 = c->value1;
	if ((a->value1 > a2) && (a2 > a3))
	{
		swap_ab(list, is_ab);
		rev_rotate_abrr(list, is_ab);
	}
	else if ((a2 > a3) && (a3 > a->value1))
	{
		rev_rotate_abrr(list, is_ab);
		swap_ab(list, is_ab);
	}
	else if ((a2 > a->value1) && (a->value1 > a3))
		rev_rotate_abrr(list, is_ab);
	else if ((a3 > a->value1) && (a->value1 > a2))
		swap_ab(list, is_ab);
	else if ((a->value1 > a3) && (a3 > a2))
		rotate_abr(list, is_ab);
}

int	index_founder(t_list *list, int idx1)
{
	t_list	*temp1;
	int		min1;

	temp1 = list;
	min1 = list->value1;
	while (temp1 != NULL)
	{
		if (min1 > temp1->value1)
			min1 = temp1->value1;
		temp1 = temp1->next;
	}
	temp1 = list;
	while (list->value1 != min1)
	{
		idx1++;
		list = list->next;
	}
	return (idx1);
}

void	sort_5elem(t_list **sa, t_list **sb, int num_num, int num_num2)
{
	int	idx1;
	int	i1;

	i1 = -1;
	while (++i1 <= num_num - 3)
	{
		idx1 = index_founder(*sa, 0);
		if (idx1 < num_num && idx1 > num_num / 2)
			while (idx1 > num_num / 2 && idx1++ < num_num)
				rev_rotate_abrr(sa, 1);
		else
			while (idx1-- > 0)
				rotate_abr(sa, 1);
		push_ab(sa, sb, 2);
		--num_num;
	}
	sort_3elem(sa, 1, 0, 0);
	while (num_num2 - 3)
	{
		push_ab(sa, sb, 1);
		num_num2--;
	}
}

void	data_return2a(t_list **sa, t_list **sb, int num_num)
{
	int		i1;
	t_list	*temp;

	while (num_num--)
	{
		i1 = 0;
		temp = *sb;
		while (temp->index1 != num_num && temp)
		{
			temp = temp->next;
			i1++;
		}
		if (2 * i1 > num_num)
			while ((*sb)->index1 != num_num)
				rev_rotate_abrr(sb, 2);
		else
			while ((*sb)->index1 != num_num)
				rotate_abr(sb, 2);
		push_ab(sa, sb, 1);
	}
}

void	sort_more_than5(t_list **sa, t_list **sb, int num_num)
{
	int	i2;
	int	i1;

	i1 = 0;
	i2 = 0;
	while (i1 * i1 < num_num)
		i1++;
	while (*sa)
	{
		if ((*sa)->index1 <= ((1.6 * (i1 - 1)) + i2))
		{
			push_ab(sa, sb, 2);
			if ((*sb)->index1 <= i2++)
				rotate_abr(sb, 2);
		}
		else
			rotate_abr(sa, 1);
	}
	data_return2a(sa, sb, num_num);
}


void	sort_push_swap(t_list *sa, t_list *sb)
{
	int	num_num;

	num_num = ft_lstsize(sa);
	if (num_num == 2)
		swap_ab(&sa, 1);
	else if (num_num == 3)
		sort_3elem(&sa, 1, 0, 0);
	else if (num_num <= 5)
		sort_5elem(&sa, &sb, num_num, num_num);
	else
		sort_more_than5(&sa, &sb, num_num);
	free_stacka(&sa);
	free_stacka(&sb);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i1;

	i1 = 0;
	while (i1 < n && (s1[i1] != '\0' || s2[i1]))
	{
		if ((unsigned char)s1[i1] == (unsigned char)s2[i1])
			i1++;
		else
			return ((unsigned char)s1[i1] - (unsigned char)s2[i1]);
	}
	return (0);
}

void	is_valid_arg(int argc, char **argv)
{
	int	j;

	j = 0;
	while (j < argc)
	{
		if (ft_strncmp(argv[j], "", 1) == 0)
		{
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*sa;
	t_list	*sb;
	char	**temp;

	sb = NULL;
	if (argc < 2)
		return (0);
	is_valid_arg(argc, argv);
	temp = is_valid(argc, argv, 1);
	if (!temp)
		return (1);
	if (total_check_sort(temp))
	{
		ft_strfree(temp);
		return (0);
	}
	sa = add_input2list(temp, -1);
	if (!sa)
		return (0);
	ft_strfree(temp);
	insertion_2vector(&sa);
	sort_push_swap(sa, sb);
	return (0);
}

// write the test cases for the above code
// ./push_swap 8 22 3 90 64 12 1 2 4 5

