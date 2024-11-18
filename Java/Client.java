import java.io.*;
import java.net.*;

public class Client {
  public static void main(String[] args) {
    String serverAddress = "127.0.0.1";
    int serverPort = 8080;

    try {
      // Create a socket to connect to the server
      Socket socket = new Socket(serverAddress, serverPort);
      System.out.println("Connected to the server");

      // Create a buffered reader to read from the input stream
      BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
      PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
      BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));

      String userMessage;
      String serverMessage;
      while (true) {
        System.out.print("Client (Type your message) : ");
        userMessage = userIn.readLine();
        out.println(userMessage); // Send message to the server

        // Stop communication if "end" is sent
        if (userMessage.equals("end")) {
          System.out.println("Connection closed by the client");
          break;
        }

        // Read response from the server
        serverMessage = in.readLine();
        if (serverMessage.equals("end")) {
          System.out.println("Connection closed by the server");
          break;
        }
        System.out.println("Server : " + serverMessage);
      }

      // Close the socket
      in.close();
      out.close();
      socket.close();
    } catch (IOException e) {
      System.out.println("Error: " + e.getMessage());
    }
  }
}
