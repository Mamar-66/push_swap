NAME	= 		push_swap
NAME_BONUS	=	checker

CC 		= gcc

CFLAGS	=	-Wall -Werror -Wextra

SRC_PATH	=	srcs/
OBJ_PATH	=	objs/
SRC_BONUS_PATH = srcs_bonus/
OBJ_BONUS_PATH = objs_bonus/

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

SRC_BONUS = main.c \
			error.c \
			gest_stacks.c \
			ft_strcmp.c \
\
			gest_pile/add_pile.c \
			gest_pile/cmp.c \
\
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
\
			utile/ft_atoi.c \
			utile/ft_calloc.c \
			utile/ft_putstr.c \
			utile/ft_bzero.c \
			utile/len_lst.c \
\
			gest_pile/shots/sa_sb.c \
			gest_pile/shots/ss.c \
			gest_pile/shots/ra_rb.c \
			gest_pile/shots/rr.c \
			gest_pile/shots/pa_pb.c \
			gest_pile/shots/rra_rrb.c \
			gest_pile/shots/rrr.c

SRCS	=	$(addprefix $(SRC_PATH), $(SRC))

OBJ		=	$(SRC:.c=.o)

OBJS	=	$(addprefix $(OBJ_PATH), $(OBJ))

SRCS_BONUS	=	$(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

OBJS_BONUS	=	$(addprefix $(OBJ_BONUS_PATH), $(OBJ_BONUS))

INCS	=	-I	./includes/


all: $(OBJ_PATH) $(NAME)
 
$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
			mkdir $(OBJ_PATH)
			mkdir $(OBJ_PATH)/gest_pile
			mkdir $(OBJ_PATH)/gest_pile/shots
			mkdir $(OBJ_PATH)/utile

$(OBJ_BONUS_PATH)%.o:	$(SRC_BONUS_PATH)%.c
						$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_BONUS_PATH):
			mkdir $(OBJ_BONUS_PATH)
			mkdir $(OBJ_BONUS_PATH)/get_next_line
			mkdir $(OBJ_BONUS_PATH)/gest_pile
			mkdir $(OBJ_BONUS_PATH)/utile
			mkdir $(OBJ_BONUS_PATH)/gest_pile/shots

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS)
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

bonus:	$(OBJ_BONUS_PATH) $(NAME_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
		rm -rf $(OBJ_PATH)
		rm -rf $(OBJ_BONUS_PATH)

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(NAME_BONUS)

re:		fclean all

.PHONY:	all clean fclean re