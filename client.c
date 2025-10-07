#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client";
    char buffer[1024] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }
    printf("✅ Socket created\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        printf("❌ Invalid address/ Address not supported\n");
        return -1;
    }

    printf("🔄 Trying to connect to server...\n");
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("❌ Connection Failed");
        return -1;
    }

    printf("✅ Connected to server!\n");
    send(sock, message, strlen(message), 0);
    printf("📤 Sent: %s\n", message);

    int valread = read(sock, buffer, 1024);
    printf("📩 Server says: %s\n", buffer);

    close(sock);
    return 0;
}
