#include "server.h"
#include <string.h>

int main() {
    int server, client;
    socklen_t address_len;
    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
}
