**Real-Time IoT Device Connectivity Management**
<br>
📘 Project Overview:
<br>
This project demonstrates TCP socket programming in C for IoT connectivity, where a server communicates with multiple clients simultaneously.
The server and clients exchange data over the TCP protocol, simulating a basic IoT communication framework between devices and a central hub.

**⚙️ Features:**
<br>
✅ TCP/IP-based communication
<br>
✅ Multi-client handling using threads
<br>
✅ Real-time message exchange between client(s) and server
<br>
✅ Simple and efficient C implementation

🧠 Concept:
<br>
The project is based on the TCP (Transmission Control Protocol), ensuring reliable and ordered data transmission between IoT devices and the central server.

**🖥️ Technologies Used:**
<br>
Language: C
<br>
Protocol: TCP/IP
<br>
Environment: Ubuntu (WSL or native Linux terminal)
<br>
Compiler: GCC

📂 File Structure:
Real-Time-IoT-Device-Connectivity-Management/
<br>
│
<br>
├── server.c      # Server-side code
<br>
├── client.c      # Client-side code
<br>
├── Makefile      # Compile and run automation
<br>
└── README.md     # Project documentation

🧩 How It Works
1️⃣ Server Side
$ gcc server.c -o server
<br>
$ ./server


**Output:**
<br>
✅ Server socket created successfully 
<br>
✅ Bind successful on port 8080
<br>
🟢 Server listening...
<img width="1618" height="171" alt="Screenshot 2025-10-09 103415" src="https://github.com/user-attachments/assets/637adc9d-b2e6-482e-ba66-530c953532a0" />


**2️⃣ Client Side:**
$ gcc client.c -o client
<br>
$ ./client

**Output:**
<br>
✅ Socket created  
<br>
🔄 Trying to connect to server...
<br>
✅ Connected to server!
<br>
📤 Sent: Hello from client  
<br>
📩 Server says: Hello client, I received: Hello from client
<img width="1607" height="179" alt="Screenshot 2025-10-09 103632" src="https://github.com/user-attachments/assets/8a165b92-e303-4e25-bc4f-3fb498cc923f" />


**🚀 Future Scope:**
<br>
Simulate IoT device parameters (battery, latency, status)
<br>
Add JSON-based data packets and dashboards


**🧑‍💻 Author-**
**Prajakta Navatake**

<br>
🎓 Embedded Systems | IoT Enthusiast
