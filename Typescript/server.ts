import * as net from "net";

const PORT = 8080;

// Create the TCP server
const server = net.createServer((socket) => {
  console.log("Client connected");

  // Handle incoming data
  socket.on("data", (data) => {
    console.log(`Client: ${data.toString()}`);

    if (data.toString().trim().toLowerCase() === "end") {
      console.log("Client disconnected");
      socket.end("Goodbye!\n");
    } else {
      const serverResponse = data.toString().toUpperCase();
      socket.write(`Server: ${serverResponse}`);
    }
  });

  // Handle client disconnection
  socket.on("end", () => {
    console.log("Client disconnected");
  });

  // Handle client errors
  socket.on("error", (err) => {
    console.error(err);
  });
});

// Listening for incoming connections
server.listen(PORT, () => {
  console.log(`Server listening on port ${PORT}`);
});
