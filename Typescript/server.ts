import * as net from "net";
import * as readline from "readline";

// Create a readline interface to take input from the server's terminal
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const server = net.createServer((socket) => {
  console.log("Client connected.");

  socket.on("data", (data) => {
    const message = data.toString();
    console.log("Client :", message);

    // If the message is 'end', close the connection
    if (message.trim().toLowerCase() === "end") {
      console.log("Ending conversation.");
      socket.end();
      rl.close();
      return;
    }

    // Server responds to the client
    rl.question("Server (Type Message) : ", (answer) => {
      if (answer.trim().toLowerCase() === "end") {
        console.log("Ending conversation.");
        socket.write("end");
        socket.end();
        rl.close();
        return;
      }

      socket.write(answer);
    });
  });

  socket.on("end", () => {
    console.log("Client disconnected.");
  });
});

// Listen for incoming connections on port 8080
server.listen(8080, () => {
  console.log("Server listening on port 8080");
});
