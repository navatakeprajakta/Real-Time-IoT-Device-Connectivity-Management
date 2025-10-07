#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024] = {0};
    char *reply = "Hello from server 👋";

    // Step 1: Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("✅ Server socket created successfully\n");

    // Step 2: Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // accept all connections
    server_addr.sin_port = htons(PORT);

    // Step 3: Bind
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    printf("✅ Bind successful on port %d\n", PORT);

    // Step 4: Listen
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("🟢 Server listening...\n");

    // Step 5: Accept & communicate
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        int valread = read(new_socket, buffer, sizeof(buffer));
        if (valread > 0) {
            buffer[valread] = '\0';
            printf("📩 Received: %s\n", buffer);

            // send response to client
            send(new_socket, reply, strlen(reply), 0);
            printf("📤 Replied: %s\n", reply);
        }

        close(new_socket);
    }

    close(server_fd);
    return 0;
}
