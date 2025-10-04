# Hospital & Old Age Home Management System


## Project Overview
This is a **C-based CLI application** that simulates hospital and old age home management.  
It allows users to apply to a hospital or old age home, validates age, stores data in files, and provides admin access to view application history.

---

## Language & Tools
- **Programming Language:** C  
- **Platform:** Linux / macOS / Windows (GCC compatible)  
- **Tools Used:** Terminal, ANSI escape codes for animations, file handling, Git & GitHub for version control  

---

## Features
- ✅ **Age validation** to check eligibility for hospital or old age home.  
- ✅ **Animated terminal output** for loading and submitting applications.  
- ✅ **File storage** to save user applications (`hospital.txt` and `applications.txt`).  
- ✅ **Admin verification** with simple password encryption for viewing application history.  

---

## Challenges Faced
- Validating user input to prevent crashes on invalid entries.  
- Animating terminal output with dots and loading cycles.  
- Ensuring file data is safely written and read.  

---

## Solutions Implemented
- Used **loops and conditionals** for input validation.  
- Used **ANSI escape codes** (`\033[...m`) to add colors and terminal animations.  
- Implemented **simple password encryption** for admin access.  
- Modularized code with **functions** to handle hospital and old age home logic separately.  

---

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/ShlokPhadtare/Hospital_OldAge_C.git
   default password: shlok123

