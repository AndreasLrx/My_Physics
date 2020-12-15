TARGET := libcontainer.a

OBJ_PATH := bin
SRCS_BASE := 	my_vector/my_vector_others.c \
				my_vector/my_vector_removes.c \
				my_vector/my_vector_resizes.c \
				my_vector/my_vector_size.c \
				\
				my_map/my_map_remove.c \
				my_map/my_map_get.c \
				my_map/my_map_set.c

OBJS := $(addprefix $(OBJ_PATH)/, $(SRCS_BASE:.c=.o))
CC := gcc
CFLAGS := -Wall -Werror -pedantic
INCLUDE_PATH := ../../include
INCLUDE_FOLDER := $(INCLUDE_PATH)/my_containers
CFLAGS_INCLUDE := -I./
HEADER_NAMES = *.h

all: $(OBJ_PATH) $(INCLUDE_PATH) $(INCLUDE_FOLDER) $(TARGET) copy_header

$(TARGET): $(OBJS)
	ar -rc $@ $(OBJS)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(TARGET)
	rm -rf $(INCLUDE_FOLDER)

re: fclean all

copy_header:
	cp $(HEADER_NAMES) $(INCLUDE_FOLDER)
	cp $(TARGET) ../$(TARGET)

$(OBJ_PATH)/my_vector/%.o: ./my_vector/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<
$(OBJ_PATH)/my_map/%.o: ./my_map/%.c
	$(CC) $(CFLAGS) $(CFLAGS_INCLUDE) -c -o $@ $<


$(OBJ_PATH):
	mkdir $@
	mkdir $(OBJ_PATH)/my_vector
	mkdir $(OBJ_PATH)/my_map

$(INCLUDE_PATH):
	mkdir $@

$(INCLUDE_FOLDER):
	mkdir $@

.PHONY: clean fclean re all copy_header
