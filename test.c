#include "lemin.h"

int	ft_cmp(const char *s1, const char *s2)
{
	size_t l;

	l = 0;
	while (s1[l] && (unsigned char)s1[l] == (unsigned char)s2[l])
		l++;
	if ((unsigned char)s1[l] > (unsigned char)s2[l])
		return (-1);
	else if ((unsigned char)s1[l] < (unsigned char)s2[l])
		return (1);
	return (0);
}

typedef	struct	q_list
{
	struct	q_list	*next;
	char		*room;
	int		occupied;
	int		ant_count;
	char		**links;
}		r_list;

void ft_add_rooms(r_list **rooms, char *room)
{
	r_list *p;
	p = (r_list *)malloc(sizeof(r_list));
	p->room = room;
	p->occupied = 0;
	p->ant_count = 0;
	if(*rooms == NULL)
	{
		p -> next = NULL;
		*rooms = p;
	}
	else
	{
		p->next = *rooms;
		*rooms = p;
	}
}

static void	ft_creat_rooms_list(r_list **head, char **rooms)
{
	size_t i = 0;
	while(rooms[i] != NULL)
	{
		ft_add_rooms(head,rooms[i]);
		i++;
	}
}

int main()
{
	char **con = ft_strsplit("0-2;2-3;3-1;0-4;4-1",';');
//	char paths[100][100];
//	char start[100]= "0";
	r_list *head ;
	ft_creat_rooms_list(&head, ft_strsplit("0 1 2 3 4",' '));
	
	
	while(head != NULL)
	{
		printf("%s ",head->room);
		head = head->next;
	}
		printf("\n ");
	int i = 0;
	int j = 0;
	char **sp;
	int x;
	while(con[i] != NULL)
	{
		sp = ft_strsplit(con[i], '-');
		x = 0;
		while(sp[x] != NULL)
		{
			if(ft_strcmp(sp[x], "0") == 0)
			{
				int y = 0;
				r_list *temp = head;
				while(ft_strcmp(temp->room,"0") != 0)
					temp = temp->next;
				while(temp->links[y])
					y++;
				if(x == 0)
					temp->links[y] = sp[1];
				else
					temp->links[y] = sp[0];
				con[i] = "  ";			
			j++;
			printf("i == %d str == %s\n",i, sp[x]);
			}
					
			x++;
		}
		i++;
	}
	printf("conn == %d\n", i);
	printf("start == %d\n", j);
				r_list *temp = head;
				while(ft_strcmp(temp->room,"0") != 0)
					temp = temp->next;

	printf("links start == %s -%s \n", temp->links[0],temp->links[1]);
j = 0;
while(con[j])
	printf("%s, ", con[j++]);
	printf(" \n");
	return(0);
}
