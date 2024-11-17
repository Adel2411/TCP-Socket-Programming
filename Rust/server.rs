use std::io::{Read, Write};
use std::net::TcpListener;

fn main() -> std::io::Result<()> {
    //  Bind the server to the address
    let listener = TcpListener::bind("127.0.0.1:8080")?;
    println!("Server listening on port 8080");

    // Accept single incoming connection
    let (mut stream, addr) = listener.accept()?;
    println!("Connection received from {}", addr);

    // Send welcome message to the client
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
        println!("Client : {}", message);

        if message.trim().to_lowercase() == "end" {
            println!("Closing the connection");
            break;
        }

        // Echo the data back to the client
        let server_response = message.trim().to_uppercase();
        stream.write_all(server_response.as_bytes())?;
    }

    // Close the connection
    stream.shutdown(std::net::Shutdown::Both)?;

    Ok(())
}
