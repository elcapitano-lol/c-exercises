CC = gcc

str_search: main.c
	$(CC) -o $@ $^

.PHONY: all
all: str_search
	$(info Done)

.PHONY: clean
clean:
	@rm -f ./str_search
	$(info Clean)
