// main.cpp
// Employee Absence Calculator — Improved Implementation
// Created by Andrea 👾 (refactor & improvements 2025-11-23)
// Compiles with C++17 or later

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

struct Employee {
    int id;
    int absences;
};

// Read a line from stdin and try to parse an integer, with validation.
int promptInt(const std::string& prompt, int minValue) {
    while (true) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line)) {
            // EOF or error - clear and try again
            std::cin.clear();
            continue;
        }
        std::stringstream ss(line);
        long long value;
        if (!(ss >> value) || !(ss.eof())) {
            std::cout << "  Invalid input. Please enter an integer value.\n";
            continue;
        }
        if (value < minValue) {
            std::cout << "  Value must be >= " << minValue << ".\n";
            continue;
        }
        return static_cast<int>(value);
    }
}

int getNumOfEmployees() {
    return promptInt("Please enter number of employees: ", 1);
}

Employee readEmployee(int index) {
    Employee e;
    e.id = promptInt("What is the employee ID of employee " + std::to_string(index + 1) + ": ", 1);
    e.absences = promptInt("How many absences has employee " + std::to_string(e.id) + " had: ", 0);
    return e;
}

bool writeEmployeesToFile(const std::vector<Employee>& list, const std::string& filename,
                          bool append = false, bool csv = false) {
    std::ofstream ofs;
    if (append) ofs.open(filename, std::ofstream::out | std::ofstream::app);
    else ofs.open(filename, std::ofstream::out | std::ofstream::trunc);

    if (!ofs.is_open()) return false;

    if (csv) {
        ofs << "EmployeeID,Absences\n";
        for (const auto& e : list) {
            ofs << e.id << ',' << e.absences << '\n';
        }
    } else {
        for (const auto& e : list) {
            ofs << e.id << ": " << e.absences << '\n';
        }
    }
    return true;
}

double calculateAverageAbsences(const std::vector<Employee>& list) {
    if (list.empty()) return 0.0;
    long long total = 0;
    for (const auto& e : list) total += e.absences;
    return static_cast<double>(total) / static_cast<double>(list.size());
}

bool promptYesNo(const std::string& prompt) {
    while (true) {
        std::cout << prompt << " (y/n): ";
        std::string s;
        if (!std::getline(std::cin, s)) {
            std::cin.clear();
            continue;
        }
        if (s.empty()) continue;
        char c = std::tolower(static_cast<unsigned char>(s[0]));
        if (c == 'y') return true;
        if (c == 'n') return false;
        std::cout << "  Please enter 'y' or 'n'.\n";
    }
}

int main() {
    constexpr const char* OUTFILE = "EmployeeAbs.txt";

    // 1) Get number of employees
    int numEmployees = getNumOfEmployees();

    // 2) Read employee records
    std::vector<Employee> employees;
    employees.reserve(static_cast<size_t>(numEmployees));
    for (int i = 0; i < numEmployees; ++i) {
        employees.push_back(readEmployee(i));
        std::cout << '\n';
    }

    // 3) Ask how to write the data
    bool csv = promptYesNo("Save output as CSV format?");
    bool append = promptYesNo("Append to existing file? (Otherwise file will be overwritten)");

    // 4) Write file and handle errors
    if (!writeEmployeesToFile(employees, OUTFILE, append, csv)) {
        std::cerr << "Error: could not open file \"" << OUTFILE << "\" for writing.\n";
    } else {
        std::cout << "Employee data saved to " << OUTFILE << (append ? " (appended)" : " (overwritten)") << ".\n";
    }

    // 5) Compute and display average (with two decimal places)
    double avg = calculateAverageAbsences(employees);
    std::cout << "Average Employee Absences is: " << std::fixed << std::setprecision(2) << avg << '\n';

    // 6) Footer info
    std::cout << "\nClass: CMSCI140\n";
    std::cout << "Assignment: Project 4\n";
    std::cout << "Programmer: Andrea Ongomefen\n";
    std::cout << "Due Date: Nov. 15 2024\n";

    return 0;
}
