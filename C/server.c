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
  char *hello = "Hello from server";

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

  // Read the message from client and copy it to buffer
  read(new_socket, buffer, MAXLINE);
  printf("Client: %s\n", buffer);

  // Send the message back to client
  send(new_socket, hello, strlen(hello), 0);
  printf("Hello message sent\n");

  // Close sockets
  close(new_socket);
  close(server_fd);

  return EXIT_SUCCESS;
}
