NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rsc
RM			=	rm -f

BONSRCS		=	ft_lstnew.c	ft_lstadd_back.c ft_lstsize.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c

SRCS		=	ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_bzero.c \
				ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_calloc.c ft_memccpy.c ft_putnbr_fd.c \
				ft_strlcpy.c  ft_tolower.c ft_isalnum.c ft_memchr.c ft_putstr_fd.c	ft_strlen.c \
				ft_toupper.c ft_isalpha.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isascii.c ft_memcpy.c \
				ft_strchr.c ft_strncmp.c ft_isdigit.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isprint.c \
				ft_memset.c ft_striteri.c ft_strrchr.c ft_realloc.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				ft_printf/ft_conv.c ft_printf/ft_flags.c ft_printf/ft_printf.c  ft_printf/ft_subprint.c \
				ft_printf/ft_conversion.c  ft_printf/ft_itoa_s.c

OBJS		=	$(SRCS:.c=.o)
BONOBJS		=	$(BONSRCS:.c=.o)

.PHONY:		all clean fclean re bonus

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:	$(BONOBJS) $(OBJS)
	$(AR) $(NAME) $(BONOBJS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	$(RM) $(OBJS) $(BONOBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
