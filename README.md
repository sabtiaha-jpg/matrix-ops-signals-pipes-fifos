Matrix Operations - Parallel Processing System
📚 Course Information

Course: ENCS4330 - Real-Time Applications & Embedded Systems

University: Birzeit University

Instructor: Dr. Hanna Bullata

Semester: 1st Semester 2025/2026

Supervised by Dr. Hanna Bullata
-------------------------------------------------------------------------------------------------------------------------

🚀 Project Overview

A multi-processing application for matrix operations using signals, pipes, and process pools under Linux.
The project demonstrates real-time inter-process communication, process synchronization, and performance optimization through parallel processing.

✨ Features
Matrix Operations

✅ Matrix addition, subtraction, multiplication

✅ Determinant calculation

✅ Eigenvalues & eigenvectors computation

✅ Matrix modification (element, row, column)

✅ File I/O operations

Advanced Features

✅ Process Pool – Worker reuse (no process creation overhead)

✅ Parallel Processing – Multi-core utilization

✅ Signal Handling – SIGINT, SIGCHLD for robust process management

✅ Performance Optimization – Up to 15× speed improvement with process pool

🧮 Menu Options

Enter a matrix

Display a matrix

Delete a matrix

Modify a matrix (row, column, element)

Read a matrix from a file

Read matrices from a folder

Save a matrix to a file

Save all matrices to a folder

Display all matrices in memory

Add two matrices

Subtract two matrices

Multiply two matrices

Compute determinant

Compute eigenvalues & eigenvectors

Exit
--------------------------------------------------------------------------------------------------------------------

⚙️ Implementation Details

Implemented using signals, pipes, and a process pool for inter-process communication.

Each operation creates or reuses worker processes for distributed computation.

Execution time for each operation is measured and compared with a single-threaded baseline.

Optional OpenMP sections are included to parallelize loops for additional performance gains.

The system automatically returns to the main menu after each operation.

📁 Input & Output

Matrices can be entered manually or loaded from text files/folders.

Output matrices are stored in memory and can be saved to files for later use.

The program can take a configuration file as an argument to specify default matrix paths or menu customization:

./bin/matrix_operations config.txt
----------------------------------------------------
🛠️ Installation & Compilation
# Clone or extract the project
cd my_project

# Compile the project
make clean
make

# Run the application
./bin/matrix_operations
--------------------------------------------------------
💻 Environment

Language: C (Linux environment)

Libraries: <signal.h>, <unistd.h>, <sys/wait.h>, <stdio.h>, <stdlib.h>, <time.h>, and OpenMP (-fopenmp)

🧠 Testing & Debugging

All operations tested and verified for correctness.

Debugging performed using GDB with the -g compilation flag.

Performance compared between single-process and multi-processing modes.

Process aging and cleanup mechanisms ensure stable operation.


------------------------------------------------------------------
📊 Performance Results
Operation	Sequential Time	Parallel Time	Speedup
Addition	0.003018s	0.000273s	11x
Subtraction	0.003384s	0.000223s	15x
Multiplication	0.002456s	0.000198s	12x


🎯 Implementation Details
Process Pool Architecture
 -10 persistent worker processes

 -Pipe-based communication

 -Worker reuse across operations

 -Automatic cleanup on exit

Signal Handling
 -SIGINT: Clean process pool termination

 -SIGCHLD: Zombie process prevention

Matrix Operations
 -Parallel element-wise operations

 -Recursive determinant calculation

 -Power iteration for eigenvalues
