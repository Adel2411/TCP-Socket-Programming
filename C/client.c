#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024
#define LOCALHOST "127.0.0.1"


int main(void)
{
  int sock = 0;
  struct sockaddr_in serv_addr;
  char *message = "Hello from client";
  char buffer[MAXLINE] = {0};

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

  // Communication loop
  while (1) {
    // Send a message to the server
    printf("Client (Type your message) : ");
    fgets(buffer, MAXLINE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character
    send(sock, buffer, strlen(buffer), 0);

    // Check if the message is 'end'
    if (strcmp(buffer, "end") == 0) {
      printf("Connection closed by the client\n");
      break;
    }

    // Receive a message from the server
    memset(buffer, 0, MAXLINE);
    int bytes_read = read(sock, buffer, MAXLINE);
    if (bytes_read == 0) {
      printf("Connection closed by the server\n");
      break;
    }
    printf("Server : %s\n", buffer);

    // Check if the message is 'end'
    if (strcmp(buffer, "end") == 0) {
      printf("Connection closed by the server\n");
      break;
    }

  }


  // Closing the socket
  close(sock);

  return EXIT_SUCCESS;
}
