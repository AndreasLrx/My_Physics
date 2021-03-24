TARGET := libmy.a

OBJ_PATH := bin
INCLUDE_PATH := ../../include
HEADER_NAME = My
HEADER_CPY = $(addprefix $(INCLUDE_PATH)/, $(HEADER_NAME))
SRCS := my_strcmp.c \
		my_strlen.c \
		my_strdup.c \
		my_strset.c \
		my_strcpy.c \
		my_strdup_except.c \
		my_strcat.c \
		my_revstr.c \
		my_get_char_in.c \
		my_strchr.c \
		my_wstr_tostr.c \
		\
		my_memset.c \
		my_calloc.c \
		\
		\
		my_putstr.c \
		my_print.c \
		my_putchar.c \
		\
		my_vprint_fcts.c \
		my_vprintf.c \
		my_vprints.c \
		printf_show_value.c \
		prints_show_value.c \
		vprint_get_format.c \
		vprint_handle_format_fcts.c \
		vprint_tests.c \
		vprintf_handle_format.c \
		vprints_handle_format.c \
		\
		\
		my_char_is.c \
		my_wchar_is.c \
		my_str_is.c \
		\
		my_get_numbers.c \
		my_get_float.c \
		my_number_len.c \
		my_itostr.c \
		my_ascii_base.c \
		my_ftostr.c \
		my_tobase.c \
		\
		my_pow.c \
		\
		my_filesize.c \
		my_readfile.c \
		my_openfile.c

OBJS := $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))
CC := gcc
CFLAGS := -Wall -Werror -pedantic
CFLAGS_INCLUDE := -I./include/

all: $(OBJ_PATH) $(INCLUDE_PATH) $(TARGET) copy_header

$(TARGET): $(OBJS)
	ar -rc $@ $(OBJS)

copy_header:
	cp -r $(HEADER_NAME) $(INCLUDE_PATH)
	cp $(TARGET) ../$(TARGET)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(TARGET)
	rm -f ../$(TARGET)
	rm -rf $(HEADER_CPY)

re: fclean all

$(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_PATH)/%.o: ./Strings/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<
$(OBJ_PATH)/%.o: ./Memory/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<
$(OBJ_PATH)/%.o: ./Display/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<
$(OBJ_PATH)/%.o: ./Display/vprint/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<
$(OBJ_PATH)/%.o: ./File/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<
$(OBJ_PATH)/%.o: ./Convert/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<
$(OBJ_PATH)/%.o: ./Tests/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<
$(OBJ_PATH)/%.o: ./Maths/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<

$(OBJ_PATH):
	mkdir $@

$(INCLUDE_PATH):
	mkdir $@

.PHONY: fclean clean re all copy_header
