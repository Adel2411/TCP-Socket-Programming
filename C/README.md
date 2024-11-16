# Socket Programming Example in C

This directory contains a simple example of **TCP socket communication** implemented in **C**.

## **Files**

- `server.c`: The server file that listens for incoming client connections.
- `client.c`: The client file that connects to the server, sends a message, and receives a response.

## **How to Run**

### 1. Server

1. Open a terminal window.
2. Compile the server code:

```bash
   gcc -o server server.c
```

3. Run the server:

```bash
   ./server
```

### 2. Client

1. Open another terminal window.
2. Compile the client code:

```bash
   gcc -o client client.c
```

3. Run the client:

```bash
   ./client
```
