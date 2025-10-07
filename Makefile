# Makefile for Real-Time IoT Device Connectivity Management Project

CC = gcc
CFLAGS = -Wall
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c -o $(SERVER)

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

run-server:
	./$(SERVER)

run-client:
	./$(CLIENT)

clean:
	rm -f $(SERVER) $(CLIENT)
