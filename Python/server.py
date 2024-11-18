import socket

HOST = "127.0.0.1"
PORT = 8080


def main():
    # Create a socket
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to the address and port
    server.bind((HOST, PORT))

    # Set the accepted connections at one time
    server.listen(3)

    print(f"Server is listening on {HOST}:{PORT}...")

    # Accept the connection
    client, address = server.accept()
    print(f"Connected from {address}")

    while True:
        # Receive the data from the client
        data = client.recv(1024).decode()
        if not data or data.lower() == "end":
            print("Connection closed by the client")
            break
        print(f"Client: {data}")

        # Send a reply to the client
        reply = input("Server (Type your message): ")
        client.send(reply.encode("utf-8"))
        if reply.lower() == "end":
            print("Connection closed by the server")
            break

    # Close the connection
    client.close()


if __name__ == "__main__":
    main()
