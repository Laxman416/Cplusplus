// PHYS30762 Programming in C++
// Assignment 2

// Program to compute mean, standard deviation and standard
// error of the a set of courses. Data is read from file

#include<iostream>
#include<iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream> // for stringstream

// Functions to compute mean, standard deviation or for other tasks.

// Main function

int main()
{
  // Declaring variables
  std::vector<float> grade_list;
  std::vector<int> course_number_list;
  std::vector<std::string> course_name_list;
  std::vector<std::string> line_list; // Contains all lines from file

  float grade_value; 
  int course_number;
  std::string course_name;
  std::string line;
  std::string data_file;
  bool file_opened = false;
  std::ifstream myfile; // Declaring file

  // Loop to ask for filename again if input is wrong
  do {
      // Ask user to enter filename
      std::cout << "Enter data filename: ";
      std::cin >> data_file;

      myfile.open(data_file); // Open the file

      //Check if file can be opened
      if (!myfile.is_open()) {
          std::cerr << "Error: file could not be opened." << std::endl;
      } else {
          file_opened = true; // File opened successfully, exit loop
      }
  } while (!file_opened);

  // Gets each line in myfile
  while (getline(myfile, line)) 
  {
    std::istringstream iss(line); //istringstream contains line

    iss>>grade_value>>course_number;
    std::getline(iss >> std::ws, course_name); // read the rest of the line into course_name

    line_list.push_back(line);
    grade_list.push_back(grade_value);
    course_number_list.push_back(course_number);
    course_name_list.push_back(course_name);
  }
  myfile.close();
  
  std::cout<<line_list[1]<<std::endl;


 return 0;
}