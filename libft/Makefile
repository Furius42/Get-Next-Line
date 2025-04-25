SRCS	= ft_atoi.c \
	ft_putendl_fd.c \
	ft_strlcat.c \
	ft_substr.c \
	ft_bzero.c \
	ft_itoa.c \
	ft_putnbr_fd.c \
	ft_strlcpy.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_toupper.c \
	ft_isalnum.c \
	ft_memcmp.c \
	ft_split.c \
	ft_strmapi.c \
	ft_isalpha.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_isascii.c \
	ft_memmove.c \
	ft_strdup.c \
	ft_strnstr.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_striteri.c \
	ft_strrchr.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_putchar_fd.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_utoa.c \
	ft_bitoa.c \
	ft_strdncase.c \
	ft_strupcase.c 

OBJS	= ${SRCS:%c=%o}			# Object files: .o files corresponding to .c files

INCLUDES = libft.h

CFLAGS	= cc -Wall -Wextra -Werror -fPIC		# Flags

NAME = libft.a

${NAME}: ${OBJS}				# Rule to create the static library
	@ar rc ${NAME} ${OBJS}
	@echo "Library $(NAME) created."

%.o: %.c						# Rule to compile .c files into .o files
	@${CFLAGS} -c $< -o ${<:%c=%o}
	@echo "Compiled $@."

all: ${NAME}

clean:							# Rule to remove object files
	@rm -f ${OBJS}
	@echo "Object files removed."

fclean: clean					# Rule to remove the library and object files
	@rm -f ${NAME}
	@echo "Library $(NAME) and object files removed."

re: fclean all					# Rule to clean and rebuild everything

.PHONY: all clean fclean re		# Ensures these targets are not treated as files
