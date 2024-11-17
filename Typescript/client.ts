import * as net from "net";
import * as readline from "readline";

// Create a readline interface for user input from the client
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const client = new net.Socket();

// Connect to the server at localhost:8080
client.connect(8080, "127.0.0.1", () => {
  console.log("Connected to the server.");
  rl.question("Client (Type message) : ", (message) => {
    // Send the initial message from the client
    client.write(message);
  });
});

// Listen for incoming messages from the server
client.on("data", (data) => {
  const message = data.toString();
  console.log("Server :", message);

  // If the message is 'end', close the connection
  if (message.trim().toLowerCase() === "end") {
    console.log("Ending conversation.");
    client.end();
    rl.close();
    return;
  }

  // After receiving a message from the server, prompt the client for a reply
  rl.question("Client: ", (message) => {
    if (message.trim().toLowerCase() === "end") {
      console.log("Ending conversation.");
      client.write("end");
      client.end();
      rl.close();
      return;
    }

    client.write(message);
  });
});

// Handle client closure
client.on("close", () => {
  console.log("Connection closed");
});
