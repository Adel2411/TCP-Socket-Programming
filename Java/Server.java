import java.io.*;
import java.net.*;

public class Server {
  public static void main(String[] args) {
    int port = 8080;

    try {
      // Create a server socket
      ServerSocket serverSocket = new ServerSocket(port);
      System.out.println("Server started at port " + port + "...");

      // Wait for a client connection
      Socket clientSocket = serverSocket.accept();
      System.out.println("Client connected!");

      // Set up input and output streams
      BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
      PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
      BufferedReader consoleInput = new BufferedReader(new InputStreamReader(System.in));

      String clientMessage;
      String serverMessage;

      while (true) {
        // Receive a message from the client
        clientMessage = in.readLine();
        if (clientMessage == null || clientMessage.equalsIgnoreCase("end")) {
          System.out.println("Client closed the connection!");
          break;
        }
        System.out.println("Client : " + clientMessage);

        // Send a message to the client
        System.out.print("Server (Type your message) : ");
        serverMessage = consoleInput.readLine();
        if (serverMessage.equalsIgnoreCase("end")) {
          out.println("end");
          System.out.println("Server closed the connection!");
          break;
        }
        out.println(serverMessage);
      }

      // Close resources
      in.close();
      out.close();
      clientSocket.close();
      serverSocket.close();

    } catch (IOException e) {
      System.out.println("Server error: " + e.getMessage());
    }
  }
}
