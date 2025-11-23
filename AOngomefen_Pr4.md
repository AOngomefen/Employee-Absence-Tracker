**CMSC140 Project 4 Documentation Template**

 Class: CMSC140 CRN XXXX  
 Program: Project \#4  
 Instructor:   
 Summary of Description: (Employee Absence Calculator)  
 Due Date: Fri. Nov 14, 2025  
 Integrity Pledge: I pledge that I have completed the programming assignment independently.  
 I have not copied the code from a student or any source.  
 I have not given my code to any student.  
 Print your Name here: Andrea Ongomefen

**Part1: Flowchart and Pseudo Code:** Here is Flowchart and pseudo code for Project 4 program:

Function \#Employees:  
      
Set employeeNum to 0  
      
   	Display "Please enter number of employees:"  
    	Get input employeeNum  
      
    	While employeeNum is less than 1:  
      	Display "Number of employees cannot be less than 1\. Please re-enter number of employees:"  
       	Get input employeeNum  
      
    	Return employeeNum

Function getTotalDaysAbsent(employeeNum):  
    	  
Open file "EmployeeAbs.txt"  
      
    	Initialize TotalAbsences to 0  
      
    	For each employee from 1 to employeeNum:  
       	Display "What is the employee ID of employee" \+ current employee number  
       	Get input employeeId  
          
        	While employeeId is less than 1:  
            	Display "Employee ID cannot be less than 1"  
            	Get input employeeId  
          
        	Display "How many Absences has employee" \+ employeeId \+ " had:"  
        	Get input employeeAbsences  
          
        	While employeeAbsences is less than 0:  
           	Display "Invalid input. Employee Absences cannot be less than 0"  
            	Get input employeeAbsences  
          
        	Add employeeAbsences to TotalAbsences  
          
        	If file is open:  
            	Write employeeId and employeeAbsences to file  
       	Else:  
           	Display "Error. File is not open."  
      
    	Close the file  
    	Return TotalAbsences

Function calculateAvgDaysAbsent(numOfEmployees, TotalAbsences):  
    	Initialize avgDaysAbs to TotalAbsences / numOfEmployees  
    	Return avgDaysAbs

Main Function:  
   	Initialize numOfEmployees, TotalAbsences, averageAbsences  
      
    	Set numOfEmployees to result of getNumOfEmployees()  
    	Set TotalAbsences to result of getTotalDaysAbsent(numOfEmployees)  
    	Set averageAbsences to result of calculateAvgDaysAbsent(numOfEmployees, TotalAbsences)  
      
    	Display "Average Employee Absences is:" \+ averageAbsences

**Part2: Comprehensive Test Plan**  
A good test plan should be comprehensive. This means you should have a few test cases that test when the input is in and out of range, division by 0, incorrect Data type, etc. (Provide valid and invalid input)

| Cases | Input | Expected Output | Actual Output | Did Test Pass? |
| :---- | :---- | :---- | :---- | :---- |
| Case 1 | 3   3   2   2 | 2 | 2 | Y |
| Case 2 | 2    1    9 | 5 | 5 | Y |
| Case 3 | \-1  1    \-1     213      4  | invalid , invalid, 4 | invalid , invalid, 4 | Y |
| Case 4 | 5   4   5   6   2 | 4 | 4 | Y |

**Part3: Screenshots related to the Test Plan:**  
 **Case 1 									Case 2**

 **Case 3									Case 4**

**Lessons Learned** \<Provide answers to the questions listed above\>**:**

Write about your Learning Experience, highlighting your lessons learned and learning experience from working on this project. 

What have you learned? I learned about file and how they work I learned do while \+ if else verification and I learned about non void function return

What did you struggle with? I struggled a little with files not writing to but reading before I realized we didn’t need to read to the file.

What would you do differently on your next project? Start earlier there were more components than usual this project

What parts of this assignment were you successful with, and what parts (if any) were you not successful with? function, I love functions now 

Provide any additional resources/links/videos you used to while working on this assignment/project. 

[https://www.w3schools.com/cpp/cpp\_files.asp](https://www.w3schools.com/cpp/cpp_files.asp)  
[https://www.geeksforgeeks.org/how-to-open-and-close-file-in-cpp/](https://www.geeksforgeeks.org/how-to-open-and-close-file-in-cpp/)

**Check List:** \<Provide answers to the column Y/N or N/A \>**:**

| \# |  | Y/N | Comments |
| :---- | :---- | :---- | :---- |
|  | **Assignment files:**  |  |  |
|  | FirstInitialLastName\_ Assignment\#.zip | **Yes or No** | **Y** |
|  | FirstInitialLastName\_Assignment\#.docx/.pdf       | **Yes or No** | **Y** |
|  |  |  |  |
|  | **Program compiles** | **Yes or No** | **Y** |
|  | **Program runs with desired outputs related to a Test Plan** | **Yes or No** | **Y** |
|  | **Documentation file:** |  |  |
|  | Comprehensive Test Plan | **Yes or No**  | **Y** |
|  | Screenshots related to the Test Plan | **Yes or No** | **Y** |
|  | Algorithms/Pseudocode (if required) | **Yes or No or N/A** | **Y** |
|  | Flowchart (if required) | **Yes or No or N/A** | **Y** |
|  | Lessons Learned | **Yes or No** | **Y** |
|  | Checklist is completed and included in the Documentation | **Yes or No** | Y |

