import socket

HOST = "127.0.0.1"
PORT = 8080


def main():
    # Create a socket object
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect to the server
    client.connect((HOST, PORT))
    print("Connected to the server at {}:{}".format(HOST, PORT))

    while True:
        # Send message to the server
        message = input("Client (type your message): ")
        client.send(message.encode("utf-8"))
        if message.lower() == "end":
            print("Connection closed by the client.")
            break

        # Receive message from the server
        data = client.recv(1024).decode("utf-8")
        if data.lower() == "end":
            print("Connection closed by the server.")
            break
        print("Received:", data)

    # Close the connection
    client.close()


if __name__ == "__main__":
    main()
