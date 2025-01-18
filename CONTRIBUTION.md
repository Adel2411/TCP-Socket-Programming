# Contribution Guidelines

Thank you for your interest in contributing to the [TCP Socket Programming](https://github.com/Adel2411/TCP-Socket-Programming) repository! Contributions are welcome, especially implementations in programming languages that are not yet included in the project.

## How to Contribute

### 1. Check Existing Implementations

Before contributing, check the repository to see if the programming language you want to contribute has already been implemented. Browse the directories in the project or refer to the `README.md` file for the list of available languages.

### 2. Pick a Language or Task

If your chosen language is not implemented:

- Implement **both** the client and server for TCP socket programming.
- Follow the general structure outlined in the main `README.md` file (socket creation, binding, listening, accepting connections, sending/receiving data, and closing the connection).

If you'd like to contribute in other ways, you can:

- Add improvements to existing implementations.
- Fix bugs or optimize the code.
- Improve documentation or examples.

### 3. Fork the Repository

1. Fork the repository by clicking the "Fork" button at the top of the page.
2. Clone your forked repository to your local machine:

   ```bash
   git clone https://github.com/your-username/TCP-Socket-Programming.git
   cd TCP-Socket-Programming
   ```

### 4. Create Your Implementation

1. Create a new directory for your programming language (if not already present):

   ```plaintext
   TCP-Socket-Programming/
   ├── Your_Language/
       ├── server.ext
       ├── client.ext
       └── README.md
   ```

2. Add the following files:

   - **`server.ext`**: Server-side TCP socket implementation.
   - **`client.ext`**: Client-side TCP socket implementation.
   - **`README.md`**: Include the following:
     - Brief description of how to run the server and client.
     - Code compilation or runtime requirements (e.g., dependencies).
     - Example usage or commands.

3. Ensure your code is clear, well-documented, and adheres to the best practices of the respective programming language.

### 5. Test Your Implementation

Test your implementation to ensure it works correctly before submitting it.

### 6. Submit a Pull Request

1. Push your changes to your forked repository:

   ```bash
   git add .
   git commit -m "Add TCP socket implementation for <Language>"
   git push origin main
   ```

2. Create a pull request:
   - Go to the original repository: [Adel2411/TCP-Socket-Programming](https://github.com/Adel2411/TCP-Socket-Programming).
   - Click the "Pull Requests" tab and then "New Pull Request."
   - Select your fork and branch, then submit the pull request with a descriptive title and details about your changes.

### 7. Wait for Review

I will review your pull request. If changes are needed, i will provide feedback.

---

## Code Style and Standards

- Write clean, readable, and well-documented code.
- Follow the conventions and best practices of the programming language.
- Include comments to explain non-obvious parts of your code.
- Ensure your code is free of syntax errors and warnings.

---

## Questions or Issues?

If you have questions or encounter any issues:

- Open an issue in the repository: [New Issue](https://github.com/Adel2411/TCP-Socket-Programming/issues).
- Or contact me directly via GitHub.

---

Thank you for contributing! Your efforts help make this project better for everyone.
