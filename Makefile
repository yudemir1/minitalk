NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

CSRC = client.c
SSRC = server.c
BSSRC = server_bonus.c
BCSRC = client_bonus.c

CLIENT = client
SERVER = server
BCLIENT = client_bonus
BSERVER = server_bonus

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CSRC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CSRC)

$(SERVER): $(SSRC)
	$(CC) $(CFLAGS) -o $(SERVER) $(SSRC)

bonus: $(BCLIENT) $(BSERVER)

$(BCLIENT): $(BCSRC)
	$(CC) $(CFLAGS) -o $(BCLIENT) $(BCSRC)

$(BSERVER): $(BSSRC)
	$(CC) $(CFLAGS) -o $(BSERVER) $(BSSRC)

clean:
	rm -f $(CLIENT) $(SERVER) $(BCLIENT) $(BSERVER)

fclean: clean

re: clean all

.PHONY: all clean re fclean bonus