**Real-Time IoT Device Connectivity Management** 

📘 Project Overview**
This project demonstrates a basic TCP/IP client-server communication model implemented in C language.
It simulates the initial phase of an IoT connectivity system where devices connect to a central server to exchange messages.
Both client and server communicate using socket programming over the TCP protocol.

**⚙️ Features**
✅ Server socket creation and binding
✅ TCP connection establishment between client and server
✅ Bi-directional message exchange
✅ Real-time communication simulation

🧠 Concept
The project is based on the TCP (Transmission Control Protocol), ensuring reliable and ordered data transmission between IoT devices and the central server.

**🖥️ Technologies Used**
Language: C
Protocol: TCP/IP
Environment: Ubuntu (WSL or native Linux terminal)
Compiler: GCC

📂 File Structure
Real-Time-IoT-Device-Connectivity-Management/
│
├── server.c      # Server-side code
├── client.c      # Client-side code
├── Makefile      # Compile and run automation
└── README.md     # Project documentation

🧩 How It Works
1️⃣ Server Side
$ gcc server.c -o server
<br>
$ ./server
<img width="1308" height="226" alt="server" src="https://github.com/user-attachments/assets/9437e176-d89a-4780-93ca-44c7be94dabc" />

**Output:**
<br>
✅ Server socket created successfully
<br>
✅ Bind successful on port 8080
<br>
🟢 Server listening...
<br>
📩 Received: Hello from client
<br>
📤 Replied: Hello from server 👋


**2️⃣ Client Side**
$ gcc client.c -o client
<br>
$ ./client
<img width="1331" height="227" alt="client" src="https://github.com/user-attachments/assets/f40978a2-ea6d-4acb-9a18-adae0242a3d9" />

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
📩 Server says: Hello from server👋

**🚀 Future Scope**
Add multiple client connections
Simulate IoT device parameters (battery, latency, status)
Add JSON-based data packets and dashboards


**🧑‍💻 Author**
**Prajakta Navatake**
🎓 Embedded Systems | IoT Enthusiast
