TARGET := my_physics

OBJ_PATH := bin
SRCS_BASE := 	main.c \
				debug_draw.c \
				\
				\
				pe_body_init.c \
				pe_body_destroy.c \
				pe_body_update.c \
				pe_body_compute_aabb.c \
				pe_body_compute_mass.c \
				\
				\
				pe_collide_aabb.c \
				pe_collide_circle.c \
				pe_collide_get_collide_aabb_id.c \
				pe_collide_bodies.c \
				pe_collide_body_from_parent.c \
				pe_positionnal_correction.c \
				pe_resolve_collision.c \
				\
				\
				pe_constants.c \
				\
				\
				pe_binary_tree_best_sibling.c \
				pe_binary_tree_cost.c \
				pe_binary_tree_init.c \
				pe_binary_tree_insert_body.c \
				pe_binary_tree_raycast.c \
				pe_binary_tree_reinsert.c \
				pe_binary_tree_remove.c \
				pe_binary_tree_debug.c \
				pe_binary_tree_update.c \
				\
				pe_tree_node_init.c \
				\
				\
				pe_filter_init.c \
				\
				\
				pe_fixture_destroy.c \
				pe_fixture_init.c \
				pe_fixture_mass.c \
				\
				\
				pe_raycast_aabb.c \
				pe_raycast_init.c \
				\
				\
				pe_aabb_area.c \
				pe_aabb_copy.c \
				pe_aabb_union.c \
				pe_aabb_from_shape.c \
				pe_aabb_init.c \
			 	pe_aabb_is_equal.c \
				\
				pe_init_specific_shapes.c \
				pe_shape_update_area.c \
				pe_shape_destroy.c \
				\
				\
				pe_vec2_dot_product.c \
				pe_vec2_operands.c \
				pe_vec2_operands_simple.c \
				pe_vec2f.c \
				pe_vec2i.c \
				pe_vec2u.c \
				\
				\
				pe_world_add.c \
				pe_world_destroy.c \
				pe_world_init.c \
				pe_world_update.c \
				pe_world_handle_collisions.c
				

OBJS := $(addprefix $(OBJ_PATH)/, $(SRCS_BASE:.c=.o))
CC := gcc
CFLAGS := -Wall -Werror -pedantic
CFLAGS_LIB :=  -lcsfml-graphics  -lcsfml-system -lcsfml-window -lcsfml-audio -L./lib/ -lcontainer -lm -lmy
CFLAGS_INCLUDE := -I./include/
MAKE_LIB := make -C lib/my/
MAKE_CONTAINERS := make -C lib/my_container/

all: make_libs $(OBJ_PATH) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(CFLAGS_LIB)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE_LIB) clean
	$(MAKE_CONTAINERS) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE_LIB) fclean
	$(MAKE_CONTAINERS) fclean

re: fclean all

make_libs:
	$(MAKE_LIB)
	$(MAKE_CONTAINERS)

$(OBJ_PATH)/%.o: ./srcs/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/Body/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Collides/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Constants/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/DynamicTree/BinaryTree/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/DynamicTree/TreeNode/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/Filter/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Fixture/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/RayCast/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/Shapes/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Shapes/AABB/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/Utils/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/World/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<


$(OBJ_PATH):
	mkdir $@

debug:
	echo $(OBJS)

.PHONY: clean fclean re all test make_libs tests_run create_datas