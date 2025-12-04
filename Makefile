CC=gcc
CFLAGS=-Wall -Wextra -std=c11
BIN_DIR=bin

# Create bin dir if not exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Build for each step
bump: $(BIN_DIR)
	$(CC) 00_bump_allocator/main.c 00_bump_allocator/bump.c -o $(BIN_DIR)/bump.exe $(CFLAGS)

free_list: $(BIN_DIR)
	$(CC) 01_free_list_allocator/main.c 01_free_list_allocator/free_list.c -o $(BIN_DIR)/free_list.exe $(CFLAGS)

segregated: $(BIN_DIR)
	$(CC) 02_segregated_fit/main.c 02_segregated_fit/segregated.c -o $(BIN_DIR)/segregated.exe $(CFLAGS)

arena: $(BIN_DIR)
	$(CC) 03_thread_arenas/main.c 03_thread_arenas/arena.c -o $(BIN_DIR)/arena.exe $(CFLAGS)

tlsf: $(BIN_DIR)
	$(CC) 04_tlsf/main.c 04_tlsf/tlsf.c -o $(BIN_DIR)/tlsf.exe $(CFLAGS)

# Build all
all: bump free_list segregated arena tlsf

# Clean
clean:
	rm -rf $(BIN_DIR)
