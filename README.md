# Employee Absence Calculator

Short description
This is a small console C++ program that prompts the user for a number of employees, collects each employee's ID and number of absences, writes the per-employee data to `EmployeeAbs.txt`, and displays the average absences.

Author
Andrea Ongomefen

Files
- main.cpp — program source (single-file program)
- EmployeeAbs.txt — output file produced by the program (created at runtime)

Requirements
- A C++ compiler supporting C++17 or later (g++, clang++, MSVC)
- No external libraries are required

Build
To compile with g++ (C++17):
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o EmployeeAbs

Usage
Run the program:
./EmployeeAbs

The program will:
1. Ask for the number of employees.
2. For each employee, ask for an employee ID and the number of absences.
3. Save each employee's ID and absence count into `EmployeeAbs.txt`.
4. Print the average absences to the console and show class/author information.

Example interactive session
Please enter number of employees: 3
what is the employee ID of employee 1: 101
How many Absences has employee 101 had: 2
what is the employee ID of employee 2: 102
How many Absences has employee 102 had: 3
what is the employee ID of employee 3: 103
How many Absences has employee 103 had: 1

Average Employee Absences is: 2.00

EmployeeAbs.txt (after the run) will contain:
101: 2
102: 3
103: 1

Design and implementation notes
- The original program uses three functions: getNumofEmployees, getTotalDaysAbsent (which also collects data and writes it to a file), and calculateAvgDaysAbsent. The original code uses integer division for the average and a global ofstream variable.
- The program writes per-employee entries to `EmployeeAbs.txt` (overwrites the file each run).

How to improve the code (summary)
- Avoid global file objects; open files locally and check for successful open.
- Validate all user input robustly (handle non-integer input using cin.fail()).
- Prevent integer division when computing an average: use double arithmetic.
- Pass primitive values by value (not as non-const reference) unless you need to modify the caller's variable.
- Use small helper types (struct Employee, std::vector) for clarity and extendability.
- Use const where possible and prefer clearer function names.
- Add error handling for file I/O and division-by-zero.
- Format output with iomanip (setprecision, fixed).

Testing
- Test with reasonable inputs, zero/negative numbers, and invalid (non-numeric) inputs to confirm input validation works.
- Confirm `EmployeeAbs.txt` is created and overwritten or appended based on desired behavior.

Contributing
- If you want to extend this to track reasons for absence or date ranges, change the Employee type to store more fields, and use CSV or JSON output for interoperability.

License
MIT (or change to your preferred license)

Contact
Andrea Ongomefen
