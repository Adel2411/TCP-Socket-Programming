use std::io::{Read, Write};
use std::net::TcpStream;

fn main() -> std::io::Result<()> {
    // Connect to the server
    let mut stream = TcpStream::connect("127.0.0.1:8080")?;
    println!("Connected to the server at port 8080!");

    // Read welcome message from the server
    let mut buffer = [0; 1024];
    let bytes_read = stream.read(&mut buffer)?;
    println!(
        "Server said : {}",
        String::from_utf8_lossy(&buffer[..bytes_read])
    );

    // Communication loop
    loop {
        // Read user input
        print!("Client (Type message): ");
        std::io::stdout().flush().unwrap(); // Flush the buffer to make sure the message is printed
        let mut input = String::new();
        std::io::stdin().read_line(&mut input)?;
        input = input.trim().to_string();

        // Send user input to the server
        stream.write_all(input.as_bytes())?;
        if input.to_lowercase() == "end" {
            println!("Closing the connection!");
            break;
        }

        // Read server response
        let bytes_read = stream.read(&mut buffer)?;
        println!("Server: {}", String::from_utf8_lossy(&buffer[..bytes_read]));
    }

    // Close the connection
    stream.shutdown(std::net::Shutdown::Both)?;

    Ok(())
}
