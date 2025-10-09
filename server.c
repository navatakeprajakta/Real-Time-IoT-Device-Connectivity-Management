#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

void *handle_client(void *socket_desc) {
    int new_socket = *(int *)socket_desc;
    char buffer[1024] = {0};
    int valread;

    while ((valread = read(new_socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[valread] = '\0';
        printf("📩 Received from client: %s\n", buffer);

        // Respond back to client
        char response[256];
        snprintf(response, sizeof(response), "Hello client, I received: %s", buffer);
        send(new_socket, response, strlen(response), 0);
        printf("📤 Replied: %s\n", response);
    }

    printf("❌ Client disconnected.\n");
    close(new_socket);
    free(socket_desc);
    pthread_exit(NULL);
}

int main() {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Reuse port/address
   setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));



    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    printf("✅ Bind successful on port %d\n", PORT);

    // Listen
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("🟢 Server listening for multiple clients...\n");

    // Accept multiple clients
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen))) {
        printf("🆕 New client connected!\n");

        pthread_t client_thread;
        new_sock = malloc(sizeof(int));
        *new_sock = new_socket;

        if (pthread_create(&client_thread, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Thread creation failed");
            free(new_sock);
        } else {
            pthread_detach(client_thread); // auto cleanup when thread ends
        }
    }

    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
