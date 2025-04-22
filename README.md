# Minitalk 📶 (42 School Project)

A simple client-server program demonstrating inter-process communication (IPC) using only **UNIX signals** (`SIGUSR1` and `SIGUSR2`).

---

## 🎯 Goal

The client process sends a string message to the server process, which then displays it. Communication is achieved by encoding the string **bit-by-bit** into signals.

---

## ✨ Features

*   Server displays its **PID** (Process ID) on startup.
*   Client takes the server `PID` and the message `string` as arguments.
*   Uses `SIGUSR1` and `SIGUSR2` **exclusively** for data transfer.
*   Server can handle messages from multiple clients consecutively without restarting.
*   **Acknowledgement:** Server acknowledges message receipt back to the client. *(Bonus)*
*   **Unicode Support:** Correctly transmits and displays Unicode characters. *(Bonus)*

---

## 💻 Tech Stack

*   **Language:** C
*   **Core Concepts:** UNIX Signals, Inter-Process Communication (IPC), Bitwise Operations
*   **System Calls/Functions:** `signal()` / `sigaction()`, `kill()`, `getpid()`, `pause()`, `usleep()`
*   **Build System:** Make

---
