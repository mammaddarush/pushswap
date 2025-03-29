#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

// my libft >>
void				*ft_calloc(size_t count, size_t size);
size_t				ft_total_words(char const *str, char c1);
int					search_str(char c, char const *s, char **array);
char				**ft_split(char const *s, char c);

size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_atoi(const char *str);
int					free_str2(char **str2, int k1);
int					ft_strfree(char **str1);

void				ft_putendl_fd(char *s, int fd);
typedef struct s_list
{
	int				value1;
	int				index1;
	struct s_list	*next;
}					t_list;

int					ft_lstsize(t_list *list);
void				ft_listdelone(t_list *list);
void				ft_listclear(t_list **list);
// <<

// -----------Validating------>>>>>
int					check_max_min(char *str1);
int					check_number(char *str1);
int					total_check_number(char **args);
int					total_check_sort(char **args);
char				**is_valid(int argc, char **args, int j);

//<<<<<<<<<
//>>stacks
t_list				*create_node(char *arg);
t_list				*add_input2list(char **arg, int i1);
int					*sorting_elem(t_list **sa, int num_num, int n);
void				insertion_2vector(t_list **sa);
int					free_stacka(t_list **sa);

// <<<<<<<<<<

// actions >>>>
void				swap_any_list(t_list **list);
void				swap_ab(t_list **list_a, int is_ab);
t_list				*delete_first(t_list *list);
void				push_b(t_list **list_a, t_list **list_b);
void				push_ab(t_list **list_a, t_list **list_b, int is_ab);

t_list				*get_last_elm(t_list *list);
void				rotate_list(t_list **list);
void				rotate_abr(t_list **list_a, int is_ab);
void				rev_rotate_list(t_list **list);
void				rev_rotate_abrr(t_list **list_a, int is_ab);
//<<<<<<<<

void				sort_3elem(t_list **list, int is_ab, int a2, int a3);
int					index_founder(t_list *list, int idx1);
void				sort_5elem(t_list **sa, t_list **sb, int num_num,
						int num_num2);
void				data_return2a(t_list **sa, t_list **sb, int num_num);
void				sort_more_than5(t_list **sa, t_list **sb, int num_num);
void				sort_push_swap(t_list *sa, t_list *sb);

#endif