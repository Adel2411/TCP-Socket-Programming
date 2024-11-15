import java.io.*;
import java.net.*;

public class Server {
  public static void main(String[] args) {
    int port = 8080;

    try {

      // Create a server socket
      ServerSocket serverSocket = new ServerSocket(port);
      System.out.println("Server started at port " + port + "...");

      // Wait for client
      Socket clientSocket = serverSocket.accept();
      System.out.println("Client connected !");

      // Set up input and output streams
      BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
      PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

      String clientMessage;
      while ((clientMessage = in.readLine()) != null) {
        System.out.println("Client : " + clientMessage);

        // Stop communication when client sends "end"
        if (clientMessage.equals("end")) {
          System.out.println("Client closed the connection !");
          break;
        }

        // Send data to client
        out.println("Server : " + clientMessage.toUpperCase());
      }

      // Close the connection
      in.close();
      out.close();
      serverSocket.close();
      clientSocket.close();

    } catch (IOException e) {
      System.out.println("Server error : " + e);
    }
  }
}
