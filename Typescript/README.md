# Socket Programming Example in TypeScript

This directory contains a simple example of **TCP socket communication** implemented in **TypeScript**.

## **Files**

- `server.ts`: The server file that listens for incoming client connections.
- `client.ts`: The client file that connects to the server, sends a message, and receives a response.

## **How to Run**

### **1. Prerequisites**

Ensure that you have **Node.js** and **TypeScript** installed on your system.

- Initialize the folder project by running the following command:

```bash
npm init -y
```

- Install the required dependencies:

```bash
npm install typescript @types/node
```

### **2. Compile and Run TypeScript Files**

#### **Server**

```bash
tsc server.ts
node server.js
```

#### **Client**

```bash
tsc client.ts
node client.js
```
