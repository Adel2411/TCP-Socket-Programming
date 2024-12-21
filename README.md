# TCP Socket Programming

This repository contains examples of **TCP socket programming** in different programming languages, designed to help you learn and understand how **client-server communication** works over TCP sockets.

The goal is to demonstrate the basic steps and concepts of establishing a TCP connection between a server and a client, handling communication, and closing the connection, using simple, minimal code examples across various programming languages.

## Objective

The main aim of this repository is to provide clear and simple implementations of **TCP client-server communication** in different programming languages, so that you can:

- Understand how TCP sockets work.
- Learn how to establish connections, send/receive messages, and terminate the connection.
- Gain insights into how different languages handle socket programming.

## How Sockets Work

A **socket** is an endpoint for sending or receiving data across a computer network. It provides a way for programs to communicate with each other over a network. Here's a brief overview of how sockets work in the context of **TCP client-server communication**:

1. **Socket Creation** (`socket()`):

   - A socket is created using the `socket()` function, which returns a socket file descriptor. This socket can be used for both sending and receiving data.

2. **Binding** (`bind()`):

   - The **server** binds the socket to a specific port and address using the `bind()` function. This tells the system which address and port the server will be listening on for incoming connections.

3. **Listening** (`listen()`):

   - The server listens for incoming connections with the `listen()` function. This function allows the server to wait for client requests to establish a connection.

4. **Accepting Connections** (`accept()`):

   - Once a client requests to connect, the server uses the `accept()` function to accept the connection. This establishes a communication link between the server and the client.

5. **Connecting** (`connect()`):

   - The **client** uses the `connect()` function to request a connection to the server. The client specifies the server's address and port to connect to.

6. **Sending and Receiving Data** (`send()`, `recv()`):

   - After the connection is established, both the server and client can send and receive data using functions like `send()` and `recv()`.

7. **Closing the Connection** (`close()`):
   - Once the communication is done, both the server and client use the `close()` function to close the socket, terminating the connection.

### Summary Flow of Communication

- **Server**:

  - Creates a socket.
  - Binds the socket to an IP and port.
  - Listens for incoming connections.
  - Accepts client connections.
  - Sends and receives data.
  - Closes the connection when done.

- **Client**:
  - Creates a socket.
  - Connects to the server using the server's IP and port.
  - Sends and receives data.
  - Closes the connection when done.

## How to Use

1. Clone the repository:

   ```bash
   git clone https://github.com/Adel2411/TCP-Socket-Programming.git
   cd TCP-Socket-Programming
   ```

2. Navigate to the directory of the programming language you are interested in.
3. Follow the instructions in the README file of that language to run the client and server programs.

## Project Structure

```plaintext
TCP-Socket-Programming/
│
├── Language_1/
│   ├── server.ext
│   ├── client.ext
│   └── README.md
│
├── Language_2/
│   ├── server.ext
│   ├── client.ext
│   └── README.md
│
├── Language_3/
│   ├── server.ext
│   ├── client.ext
│   └── README.md
│
└── README.md
```

Each language directory contains the following files:

- `server.ext`: Server-side implementation in the respective programming language.
- `client.ext`: Client-side implementation in the respective programming language.
- `README.md`: Instructions on how to run the server and client programs in that language.
