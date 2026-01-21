
![Uploading Screenshot 2026-01-21 at 2.28.04 PM.png…]()









# Online Voting System (Local Simulation) 🗳️

A simple, secure, and human-written Online Voting System developed in C.
This project simulates an election environment using file-based authentication, vote counting, and secure local storage.

It is designed for:

Cybersecurity fundamentals
File handling & authentication practice
Secure system design understanding

🚀 Features

🔐 User Authentication

  * Login using Voter ID and Password
  * Only registered voters can vote

🗳️ One Person, One Vote

  * Each voter is allowed to vote only once
  * Vote status stored securely in file

 📊 Vote Counting System

  * Automatic counting for each candidate
  * Results displayed instantly

🗂 File-Based Security

  * Voter data stored in `voters.dat`
  * Vote data stored in `votes.dat`
  * Binary file format for better protection

🧠 100% Human-Written Logic

  * No AI models
  * No copied frameworks
  * Simple and transparent rules

💻 Fully Offline

  * No internet required
  * Lightweight and fast

🔑 Default Voter Accounts

| Voter ID | Password |
| -------- | -------- |
| 101      | alpha    |
| 102      | beta     |
| 103      | gamma    |


🧪 How It Works

1. System initializes voter and vote files.
2. User logs in using Voter ID and password.
3. System checks if the voter has already voted.
4. User selects a candidate.
5. Vote is stored in encrypted-style binary format.
6. Voter status is updated.
7. Results are displayed.

 🎯 Project Objective

To develop a local voting simulation system that demonstrates:

* Authentication mechanisms
* Secure data storage
* Vote counting logic
* Cybersecurity principles
* File handling in C


 ⚠️ Disclaimer

This project is a **local simulation** for academic purposes.
It is not a real online voting platform and does not replace secure cryptographic systems.

🔮 Future Enhancements

* Password hashing
* Encryption of voter database
* Admin panel
* Result exporting
* Graphical interface
* Network-based voting

👨‍💻 Author

Mohammad Arqam Javed
Cybersecurity & AI Enthusiast 
Project Type:  Academic

📜 License

Free to use for educational and academic purposes.
