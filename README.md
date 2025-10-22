<h1 style="text-align: center;"> 📒 Address Book Management System </h1>

- [🚀 Features](#-features)
- [🧠 Logical Design](#-logical-design)
- [⚙️ Technologies Used](#-technologies-used)

This project is a menu-driven Address Book Management System written in C, designed to efficiently store, manage, and retrieve contact information. It demonstrates strong programming fundamentals such as modular design, structured data management, file handling, and pointer-based memory operations — concepts widely used in embedded software development.

---


## 🚀 Features
- ➕ Create Contact: Add new contacts with name, phone number, and email.
- 🔍 Search Contact: Find and display a contact by name or phone number.
- ✏️ Edit Contact: Update existing contact details.
- ❌ Delete Contact: Remove unwanted contacts from the list.
- 📜 List Contacts: Display all stored contacts in a structured format.
- 💾 Save Contacts: Write all data to a file to preserve it after the program exits.
- 🔁 Menu-Driven Interface: Interactive loop for repeated use until exit.

---

## 🧠 Logical Design
The project uses C structures to represent each contact as an object containing attributes like name, phone, and email. These structures are grouped into an AddressBook structure that maintains an array of contacts and a counter variable to track total entries.

<br>

The program logic is modular — each function (like createContact(), searchContact(), editContact(), etc.) performs a specific task, improving maintainability and readability. Pointers are used to pass structure references to functions, optimizing memory usage and performance, similar to how embedded 
systems manage data through references to hardware registers.

<br>

File handling is used to simulate non-volatile memory, allowing contact data to be saved and reloaded when the program restarts — an approach comparable to data persistence in EEPROM or flash memory in embedded environments.
The main loop uses a do-while construct with a switch-case menu to continuously handle user input, ensuring a smooth and intuitive console interface.
<br>

---

## ⚙️ Technologies Used
- Language: C
- Concepts: Structures, Pointers, File Handling, Modular Programming
- IDE/Compiler: GCC
