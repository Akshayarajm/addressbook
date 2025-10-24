# 📒 AddressBook

## 🧩 Overview
The **AddressBook** project is a C-based application that allows users to manage contacts through a command-line interface.  
Users can create, search, edit, delete, list, and save contact details (name, phone, and email).  
The data is stored persistently in a CSV file (`contact.csv`) for later retrieval.

---

## 📁 Folder Structure
```
AddressBook/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contact.csv
```

---

## ⚙️ Features
- ➕ **Create Contact** — Add a new contact with name, phone, and email.
- 🔍 **Search Contact** — Find a contact by name, phone, or email.
- ✏️ **Edit Contact** — Modify an existing contact’s details.
- ❌ **Delete Contact** — Remove a contact from the list.
- 📃 **List All Contacts** — View all saved contacts.
- 💾 **Save Contacts** — Save all contacts to `contact.csv`.
- 📂 **Persistent Storage** — Automatically loads contacts on program start.

---

## 🧠 Data Structures

### `Contact`
```c
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;
```

### `AddressBook`
```c
typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;
```

---

## 🗂️ Files Description

### `main.c`
- Contains the main menu and handles user input.
- Calls respective functions to manage contacts.

### `contact.h`
- Declares the core structures and function prototypes for managing contacts.

### `contact.c`
- Implements functions for creating, editing, deleting, and searching contacts.
- Includes validation for phone numbers and email IDs.

### `file.h`
- Declares file operation functions.

### `file.c`
- Implements file read and write operations.
- Saves and loads contacts from `contact.csv`.

### `contact.csv`
- Stores the list of contacts in CSV format.
- Example:
  ```
  12
  Alice Smith,0987654321,alice@example.com
  Bob Johnson,1112223333,bob@company.com
  ...
  ```

---

## 🧾 Compilation & Execution

### **Step 1:** Compile the program
```bash
gcc main.c contact.c file.c -o addressbook
```

### **Step 2:** Run the program
```bash
./addressbook
```

---

## 🧩 Menu Options
```
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save contacts
7. Exit
```

---

## 🧰 Input Validation
- **Phone numbers** must be:
  - Exactly 10 digits long.
  - Contain only numbers.
  - Unique.
- **Emails** must:
  - Contain `@` and `.com`
  - Be lowercase.
  - End with `.com`
  - Be unique.

---

## 💾 Sample `contact.csv`
```
12
Alice Smith,0987654321,alice@example.com
Bob Johnson,1112223333,bob@company.com
Carol White,4445556666,carol@company.com
David Brown,7778889999,david@example.com
Eve Davis,6665554444,eve@example.com
Frank Miller,3334445555,frank@example.com
Grace Wilson,2223334444,grace@example.com
Hannah Clark,5556667777,hannah@example.com
Ian Lewis,8889990000,ian@example.com
John Doe,9876543211,as@g.com
John Doe,1234567899,amx@g.com
John Doe,1234567892,ad@g.com
```

---

## 🧑‍💻 Author
**Developed by:** Aks R  
**Language:** C  
**Platform:** Command Line  
**Version:** 1.0

---

## 📜 License
This project is open-source and available for educational purposes.
