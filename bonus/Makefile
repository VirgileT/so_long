###########################################################
#### NAME

NAME			= so_long_bonus

###########################################################
#### PATH TO SOURCES

PATH_SRCS 		+= srcs/

###########################################################
#### SOURCES

SRCS			+= so_long_bonus.c
SRCS			+= parsing.c
SRCS			+= parsing_utils.c
SRCS			+= parsing_utils_2.c
SRCS			+= pathfinding.c
SRCS 			+= print_map.c
SRCS			+= moves.c
SRCS			+= moves_bonus.c
SRCS			+= monster_bonus.c
SRCS			+= monster_bonus_utils.c
SRCS			+= shut_down.c

vpath %.c $(PATH_SRCS)

###########################################################
#### OBJS

PATH_OBJS		= objs/
OBJS			= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

###########################################################
#### LIBRARY

LIBFT_PATH 		= libft/
LIBFT 			= $(LIBFT_PATH)/libft.a

###########################################################
#### INCLUDES

INCLUDES 		= -I./includes -I./minilibx-linux -I./$(LIBFT_PATH)/includes
HEADER			= includes/so_long_bonus.h
HEADER			+= minilibx-linux/mlx.h
HEADER			+= minilibx-linux/mlx_int.h

###########################################################
#### COMPILATION

CC				= clang
CFLAGS			+= -Wall
CFLAGS			+= -Wextra
CFLAGS			+= -Werror

#ifeq ($(everything),true)
#	CFLAGS		+= -Weverything
#else
#	CFLAGS		+= -Werror
#endif

#CFLAGS			+= -Wextra
#CFLAGS			+= -fPIE
#CFLAGS			+= -g


###########################################################
#### RULES

all : bonus

bonus: $(LIBFT) $(OBJS)
	$(MAKE) -sC ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -o so_long_bonus -L ./minilibx-linux -lmlx -lXext -lX11 $(INCLUDES) -L $(LIBFT_PATH) -lft

$(LIBFT):
	$(MAKE) -sC $(LIBFT_PATH)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) 

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIBFT_PATH) clean

fclean: clean
	$(RM) so_long_bonus
	$(MAKE) -sC $(LIBFT_PATH) fclean

re: fclean
	$(MAKE)

del: fclean
	rm a.out

#test: 
#	@ $(CC) -o tests/a.out tests/main.c bonus && bash tests/runtests.sh

#full_test: fclean all test

#norm:
#	@norminette $(PATH_SRCS) $(INCLUDES)

#malloc_test: $(OBJS) $(LIBFT)
#	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ $(OBJS) -L ./minilibx-linux -lmlx -lXext -lX11 $(INCLUDES) -L $(LIBFT_PATH) -lft -L ft_mallocator -lmallocator

.PHONY: all clean fclean re del test full_test

#.SILENT: all bonus $(LIBFT) $(OBJS) clean fclean re del test full_test norm




###########################################################
#### HELP

#		CIBLE > DEPENDANCES > REGLES
# 		variables spéciales :
#
# $+ idem que $^ mais avec les doublons
# $| idem que $^ mais avec les doublons et triés
# $% nom de la cible d'une règle de substitution
# $! nom de la cible d'une règle de substitution
# $< nom de la première dépendance d'une règle de substitution
# $> nom de la dernière dépendance d'une règle de substitution
# $^ liste des dépendances d'une règle de substitution
# $@ nom de la cible d'une règle de substitution
# $? liste des dépendances plus récentes que la cible d'une règle de substitution
# $* nom du fichier sans son extension d'une règle de substitution