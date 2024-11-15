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

      // Send a message to the server
      out.println("Hello, server!");

      // Read the server's response
      String response = in.readLine();
      System.out.println("Server : " + response);

      // Close the socket
      in.close();
      out.close();
      socket.close();
    } catch (IOException e) {
      System.out.println("Error: " + e.getMessage());
    }
  }
}
