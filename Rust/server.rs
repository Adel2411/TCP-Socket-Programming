use std::io;
use std::io::{BufRead, Read, Write};
use std::net::TcpListener;

fn main() -> std::io::Result<()> {
    // Bind the server to the address
    let listener = TcpListener::bind("127.0.0.1:8080")?;
    println!("Server listening on port 8080");

    // Accept single incoming connection
    let (mut stream, addr) = listener.accept()?;
    println!("Connection received from {}", addr);

    // Send a welcome message to the client
    let mut buffer = [0; 1024];
    let welcome_message = "Welcome to the server!";
    stream.write_all(welcome_message.as_bytes())?;

    // Communication loop
    loop {
        // Read the incoming data
        let bytes_read = stream.read(&mut buffer)?;
        if bytes_read == 0 {
            println!("Connection closed");
            break;
        }

        let message = String::from_utf8_lossy(&buffer[..bytes_read]);
        println!("Client: {}", message);

        if message.trim().to_lowercase() == "end" {
            println!("Closing the connection");
            break;
        }

        // Prompt the server user to type a response
        print!("Server (Type your message): ");
        std::io::stdout().flush().unwrap(); // Flush the buffer to make sure the message is printed
        let mut server_message = String::new();
        io::stdin().lock().read_line(&mut server_message).unwrap();
        server_message = server_message.trim().to_string();

        // Send the server's response to the client
        if server_message.to_lowercase() == "end" {
            stream.write_all(b"end")?;
            println!("The server is closing the connection");
            break;
        } else {
            stream.write_all(server_message.as_bytes())?;
        }
    }

    // Close the connection
    stream.shutdown(std::net::Shutdown::Both)?;

    Ok(())
}
