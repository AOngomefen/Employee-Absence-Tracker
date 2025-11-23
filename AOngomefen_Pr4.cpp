
//  main.cpp
//  AOngomefen_Pr4.cpp
//  Created by Andrea 👾 on 11/14/24.
/*
 * Class: CMSC140 CRN
 * Instructor: Ara K
 * Project<4>
 * Description: (Employee Absence Calculator using Functions)
 * Due Date: Nov. 10 2025
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Andrea Ongomefen

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

ofstream outfile;

int getNumofEmployees(){
    
    int employeeNum;
    
    cout << "Please enter number of employees: ";
    cin >> employeeNum;
    
    do
    {
        if  (employeeNum < 1){
            cout << "number of employee's cannot be less than 1\nPlease re enter number of employees:";
            cin >> employeeNum;
            
        }
        else
            cout << endl;
        
    } while (employeeNum < 1);
    
    return employeeNum;
    
}

int getTotalDaysAbsent(int &employeeNum){
    
    outfile.open("EmployeeAbs.txt");
    
    int employeeId;
    int employeeAbsences;
    int TotalAbsences = 0;
    
    for (int i = 0; i < employeeNum; i++){
        
        cout << "what is the employee ID of employee " << i + 1 << ": ";
        cin >> employeeId;
        
        do 
        {
            if (employeeId < 1){
                    cout << "employee ID cannot be less than 1\n";
                    cin >> employeeId;
                }
            else
                cout << endl;
        } while (employeeId < 1);
        
        
        cout << "How many Absences has employee " << employeeId << " had: ";
        cin >> employeeAbsences;
        
        do 
        {
            if (employeeAbsences < 0){
                
                cout << "Invalid Input. Employee Abscences cannot be less than 0";
                cin >> employeeAbsences;
            }
            else
                cout << endl;
        } while (employeeAbsences < 0);
        
        TotalAbsences += employeeAbsences;
        
        cout << endl;
        
        if (outfile.is_open()){
            
            outfile << employeeId << ": " << employeeAbsences << endl;
        }
        else
            cout << "Error. File is not Open.";
        
    }
    
    outfile.close();
    
    return TotalAbsences;
    
}

double calculateAvgDaysAbsent(int &numofEmployees, int &TotalAbsences){
    
    int avgDaysAbs;
    avgDaysAbs = TotalAbsences/numofEmployees;
    
    return avgDaysAbs;
    
}


int main (){
    
    int numofEmployees, TotalAbsences;
    double averageAbsences;
    
    numofEmployees = getNumofEmployees();
    TotalAbsences = getTotalDaysAbsent(numofEmployees);
    averageAbsences = calculateAvgDaysAbsent(numofEmployees, TotalAbsences);
    
    
    cout << "Average Employee Absences is: " << static_cast<double>(averageAbsences);
    cout << endl;
    
    
    string cmsci = "CMSCI140";
    string assignment = "Project 4";
    string programmer = "Andrea Ongomefen";
    string duedate = "Nov. 15 2024";

    cout << "\nClass: " << cmsci << endl;
    cout << "Assignment: " << assignment << endl;
    cout << "Programmer: " << programmer << endl;
    cout << "Due Date: " << duedate << endl;
    
}
