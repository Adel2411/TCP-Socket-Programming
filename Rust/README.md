# Socket Programming Example in Rust

This directory contains a simple example of **TCP socket communication** implemented in **Rust**.

## **Files**

- `server.rs`: The server file that listens for incoming client connections.
- `client.rs`: The client file that connects to the server, sends a message, and receives a response.

## **How to Run**

### **1. Server**

1. Open a terminal window.
2. Run the server:
   ```bash
   rustc src/server.rs && ./server
   ```

### **2. Client**

1. Open another terminal window.
2. Run the client:
   ```bash
   rustc src/client.rs && ./client
   ```
