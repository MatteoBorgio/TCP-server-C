#include "server.h"

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server, client;
    socklen_t address_len = sizeof(client);

    char buffer[512];
    char *data;

    memset(&server, 0, sizeof(server));
    memset(&client, 0, sizeof(client));
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Failed to create server socket.\n");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = 0;
    server.sin_port = htons(PORT);

    printf("Server socket initialized.\n");

    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("bind() failed.\n");
        close(server_socket);
        return -1;
    }

    if (listen(server_socket, 5) < 0) {
        printf("listen() failed.\n");
        close(server_socket);
        return -1;
    }

    printf("Listening on port %d.\n", PORT);

    client_socket =
        accept(server_socket, (struct sockaddr *)&client, &address_len);

    if (client_socket < 0) {
        printf("accept() failed.\n");
        close(server_socket);
        return -1;
    }

    printf("Client connected.\n");

    if (read(client_socket, buffer, NBYTES) < 0) {
        printf("read() failed.\n");
        close(server_socket);
        close(client_socket);
        return -1;
    }

    data = "httpd v1.0\n";

    if (write(client_socket, data, strlen(data)) < 0) {
        printf("write() failed.\n");
        close(server_socket);
        close(client_socket);
        return -1;
    }

    close(client_socket);
    close(server_socket);
    return 0;
}
