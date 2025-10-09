# 🔧 Makefile for Real-Time IoT Device Connectivity Management (Multi-client version)

CC = gcc
CFLAGS = -Wall -pthread

# Targets
all: server client

server: server.c
	$(CC) $(CFLAGS) server.c -o server

client: client.c
	$(CC) $(CFLAGS) client.c -o client

run-server: server
	@echo "🚀 Starting server..."
	./server

run-client: client
	@echo "📱 Starting client..."
	./client

clean:
	rm -f server client
	@echo "🧹 Cleaned up build files."
