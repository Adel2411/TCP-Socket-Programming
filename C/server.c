#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAXLINE 1024


int main(void)
{
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[MAXLINE] = {0};

  // Creating the socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Binding the socket to the IP and port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
  {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listening for incoming connections
  if (listen(server_fd, 3) < 0)
  {
    perror("listen failed");
    close(server_fd);
    exit(EXIT_FAILURE);
  }
  printf("Server is listening on port %d...\n", PORT);
  
  // Accept client connections
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
  {
    perror("accept");
    close(server_fd);
    exit(EXIT_FAILURE);
  }
  printf("Client connected\n");

// Communication loop
  while (1) {
    // Receive message from client
    memset(buffer, 0, MAXLINE);
    int bytes_read = read(new_socket, buffer, MAXLINE);
    if (bytes_read == 0) {
      printf("Client disconnected\n");
      break;
    }
    printf("Client: %s\n", buffer);

    // Check if the message is "end"
    if (strcmp(buffer, "end") == 0) {
      printf("Connection closed by the client\n");
      break;
    }

    // Send message to client
    printf("Server (Type your message) : ");
    fgets(buffer, MAXLINE, stdin);
    buffer[strlen(buffer) - 1] = '\0';  // Remove newline character
    send(new_socket, buffer, strlen(buffer), 0);

    // Check if the message is "end"
    if (strcmp(buffer, "end") == 0) {
      printf("Connection closed by the server\n");
      break;
    }
  }

  // Close sockets
  close(new_socket);
  close(server_fd);

  return EXIT_SUCCESS;
}
