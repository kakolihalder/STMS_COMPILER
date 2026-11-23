# =====================================
# Symbol Table Management System (STMS)
# Created by: Kakoli Halder
# Project: Compiler Design PBL
# =====================================

A terminal-based **Symbol Table Management System** developed using C as a Project-Based Learning (PBL) project for the subject **Compiler Design**.

This project demonstrates how a compiler manages identifiers using a Hash Table and Linked List data structure.

## About the Project

A Symbol Table is an essential component of a compiler. It stores information about identifiers used in a source program, such as variable names, data types, scopes, memory sizes, and declaration line numbers.

This project provides a simple, menu-driven terminal interface to perform various symbol table operations and understand how compilers manage identifiers internally.

## Features

- **Insert Symbol:** Add a new identifier with its associated information.
- **Search Symbol:** Search for an existing identifier.
- **Update Symbol:** Modify the information of an existing identifier.
- **Delete Symbol:** Remove an identifier from the symbol table.
- **Display Symbol Table:** View all stored identifiers and their details.
- **Duplicate Detection:** Prevent insertion of duplicate identifiers.
- **Identifier Validation:** Validate basic identifier naming rules.
- **Dynamic Memory Management:** Allocate and release memory dynamically.

## Technologies Used

- **Programming Language:** C
- **Data Structure:** Hash Table
- **Collision Handling:** Separate Chaining using Linked Lists
- **Memory Management:** Dynamic Memory Allocation
- **Compiler:** GCC / Clang

## Project Structure

```text
STMS_COMPILER/
│
├── SymbolTableManager.c
├── terminal_input_output.txt
├── README.md
└── .gitignore

```

## Prerequisites

Before running this project, make sure you have:

- A C compiler (GCC or Clang) installed.
- A terminal or command-line interface.
- Git installed (optional, for cloning the repository).

To check whether GCC is installed, execute:

```bash
gcc --version
```

## Getting Started

### 1. Clone the Repository

Open your terminal and run:

```bash
git clone https://github.com/kakolihalder/STMS_COMPILER.git
```

### 2. Navigate to the Project Directory

```bash
cd STMS_COMPILER
```

### 3. Compile and Run

Follow the instructions for your respective operating system.

---

## Running on Windows

### Step 1: Install GCC

Install MinGW-w64 or MSYS2 to get the GCC compiler.

MSYS2: https://www.msys2.org/

For MSYS2 UCRT64, install GCC using:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc
```

If you want to use GCC from PowerShell or Command Prompt, make sure the compiler's `bin` directory is added to your Windows PATH.

### Step 2: Compile the Program

Open PowerShell or Command Prompt inside the `STMS_COMPILER` directory and execute:

```bash
gcc SymbolTableManager.c -o SymbolTableManager.exe
```

### Step 3: Run the Program

```powershell
.\SymbolTableManager.exe
```

---

## Running on macOS

### Step 1: Install Command Line Tools

Open Terminal and execute:

```bash
xcode-select --install
```

This installs Apple's command-line development tools, including Clang.

Alternatively, you can install GCC using Homebrew:

```bash
brew install gcc
```

### Step 2: Compile the Program

Using Clang:

```bash
clang SymbolTableManager.c -o SymbolTableManager
```

Or using GCC:

```bash
gcc SymbolTableManager.c -o SymbolTableManager
```

### Step 3: Run the Program

```bash
./SymbolTableManager
```

---

## Running on Linux

### Step 1: Install GCC

**Ubuntu / Debian:**

```bash
sudo apt update
sudo apt install build-essential
```

**Fedora:**

```bash
sudo dnf install gcc
```

**Arch Linux:**

```bash
sudo pacman -S gcc
```

### Step 2: Compile the Program

```bash
gcc SymbolTableManager.c -o SymbolTableManager
```

### Step 3: Run the Program

```bash
./SymbolTableManager
```

---

## Program Menu

After successfully running the program, the following menu will appear:

```text
===== SYMBOL TABLE MANAGEMENT =====

1. Insert Symbol
2. Search Symbol
3. Update Symbol
4. Delete Symbol
5. Display Symbol Table
6. Exit

Enter your choice:
```

Select an option by entering the corresponding number.

## Sample Input

You can use the following sample identifiers to test the application.

| Identifier | Data Type | Scope | Size | Line |
|---|---|---|---|---|
| age | int | global | 4 | 5 |
| salary | float | local | 4 | 8 |
| grade | char | global | 1 | 10 |

## Sample Output

```text
========== SYMBOL TABLE ==========

Name            Type         Scope        Size     Line
age             int          global       4        5
salary          float        local        4        8
grade           char         global       1        10

=================================
```

## How It Works

The project implements a Hash Table with Separate Chaining.

1. A hash function calculates an index based on the identifier name.
2. The identifier is stored at the calculated index.
3. Linked Lists handle collisions when multiple identifiers generate the same index.
4. Searching, updating, and deleting are performed using the identifier name.
5. Dynamic memory allocation is used to manage symbol entries.

## Time Complexity

| Operation | Average Case | Worst Case |
|---|---|---|
| Insertion | O(1) | O(n) |
| Searching | O(1) | O(n) |
| Updating | O(1) | O(n) |
| Deletion | O(1) | O(n) |
| Display | O(n) | O(n) |

## Learning Outcomes

Through this project, we explore:

- The role of symbol tables in compiler design.
- Hashing techniques and collision handling.
- Implementation of linked lists in C.
- Dynamic memory allocation and pointers.
- Basic identifier validation.
- Symbol table insertion, searching, updating, and deletion.

## Limitations

- Symbol information is stored in memory and is lost when the program exits.
- Only basic identifier information is supported.
- Scope information is stored as an attribute; separate scope-based identifier lookup is not implemented.
- Advanced compiler features such as semantic analysis and type checking are not included.

## Future Enhancements

- File handling for permanent symbol storage.
- Support for multiple and nested scopes.
- Reserved keyword detection.
- Advanced data type validation.
- Memory usage statistics.
- Integration with a lexical analyzer.

## Project Information

| Details | Description |
|---|---|
| Project Name | Symbol Table Management System (STMS) |
| Subject | Compiler Design |
| Project Type | Project-Based Learning (PBL) |
| Programming Language | C |
| Execution Mode | Terminal / Command Line |
| Data Structure | Hash Table with Linked Lists |

## Repository

GitHub: https://github.com/kakolihalder/STMS_COMPILER

---

*Developed as an academic project to explore the fundamental concepts of symbol table management in compiler design.*