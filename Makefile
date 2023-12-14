NAME	= push_swap

CC 		= gcc

CFLAGS	=	-Wall -Werror -Wextra

SRC_PATH	=	srcs/
OBJ_PATH	=	objs/

SRC		=	main.c \
			error.c \
\
			gest_pile/add_pile.c \
			gest_pile/cmp.c \
			gest_pile/one_three.c \
			gest_pile/three_plus.c \
			gest_pile/add_pose.c \
			gest_pile/at_very_top.c \
			gest_pile/rang_in_stach_a.c \
			gest_pile/rang_in_stach_b.c \
			gest_pile/a_to_b.c \
\
			gest_pile/shots/sa_sb.c \
			gest_pile/shots/ss.c \
			gest_pile/shots/ra_rb.c \
			gest_pile/shots/rr.c \
			gest_pile/shots/pa_pb.c \
			gest_pile/shots/rra_rrb.c \
			gest_pile/shots/rrr.c \
\
			utile/ft_atoi.c \
			utile/ft_calloc.c \
			utile/ft_putstr.c \
			utile/ft_bzero.c \
			utile/len_lst.c

SRCS	=	$(addprefix $(SRC_PATH), $(SRC))

OBJ		=	$(SRC:.c=.o)

OBJS	=	$(addprefix $(OBJ_PATH), $(OBJ))

INCS	=	-I	./includes/


all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
			mkdir $(OBJ_PATH)
			mkdir $(OBJ_PATH)/gest_pile
			mkdir $(OBJ_PATH)/gest_pile/shots
			mkdir $(OBJ_PATH)/utile


$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJ_PATH)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re