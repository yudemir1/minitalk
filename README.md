Minitalk (42 School Project)

A simple client-server program demonstrating communication using only UNIX signals (SIGUSR1 and SIGUSR2).

Goal: The client process sends a string message to the server process, which then displays it. Communication is achieved by encoding the string bit-by-bit into signals.

Features:

    Server displays its PID on startup.

    Client takes server PID and the message string as arguments.

    Uses SIGUSR1 and SIGUSR2 exclusively for data transfer.

    Server can handle messages from multiple clients consecutively.

    Server acknowledges message receipt to the client.

    Supports Unicode characters.

Tech: C, UNIX Signals (signal/sigaction, kill), Make
