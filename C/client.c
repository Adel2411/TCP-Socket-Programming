#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define LOCALHOST "127.0.0.1"


int main(void)
{
  int sock = 0;
  struct sockaddr_in serv_addr;
  char *message = "Hello from client";
  char buffer[BUFFER_SIZE] = {0};

  // Creating the socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("Socket creation error");
    return EXIT_FAILURE;
  }

  // Defining the server address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, LOCALHOST, &serv_addr.sin_addr) <= 0)
  {
    perror("Invalid address/ Address not supported");
    return EXIT_FAILURE;
  }

  // Connecting to the server
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("Connection failed");
    return EXIT_FAILURE;
  }

  // Sending the message to the server
  send(sock, message, strlen(message), 0);
  printf("Message sent to the server\n");
  
  // Receiving the message from the server
  read(sock, buffer, BUFFER_SIZE);
  printf("Message received from the server: %s\n", buffer);

  // Closing the socket
  close(sock);

  return EXIT_SUCCESS;
}
