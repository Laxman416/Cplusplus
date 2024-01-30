// Assignment 1

// Program to calculate transition energy using simple Bohr formula

#include<iostream>
#include <cmath>
#include<iomanip>
#include <string>

float energy_calculation(float atomic_number_local, int initial_principle_quantum_number_local, int final_principle_quantum_number_local, std::string output_units_local)   
{
  // Conversion factor to convert between eV to J.
  const float conversion_factor{1.602e-19};
  // Compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV
  float energy_local = 13.6 * std::pow(atomic_number_local, 2) * (1.0 / std::pow(final_principle_quantum_number_local, 2)
   - 1.0 / std::pow(initial_principle_quantum_number_local, 2));

  // Convert energy if user wanted
  if (output_units_local == "J")
  {
    energy_local *= conversion_factor;
  }  

  return energy_local;
}

int main()
{
  // Declare variables here
  int initial_principle_quantum_number;
  int final_principle_quantum_number;
  float atomic_number;
  float energy;
  std::string output_units;


  // Ask user to enter atomic number
  std::cout<<"What is the atomic number of the atom?: "<<std::endl;
  std::cin>>atomic_number;

  // Ask user to enter initial and final principle quantum numbers
  std::cout<<"What is the initial principle quantum number of the atom?: "<<std::endl;
  std::cin>>initial_principle_quantum_number;
  std::cout<<"What is the final principle quantum number of the atom?: "<<std::endl;
  std::cin>>final_principle_quantum_number;

  // Tests for bad input
  
  // Ask user if the output of energy is in joules or eV
  std::cout<<"Do you want the output to be in joules or eV? (J/eV): "<<std::endl;
  std::cin>>output_units;

  // Call function to compute energy

  energy = energy_calculation(atomic_number, initial_principle_quantum_number, final_principle_quantum_number, output_units);

  // Output answer
  if (output_units == "eV")
  {
  std::cout<<"The energy is: "<<energy<<" eV"<<std::endl;
  }
  else if (output_units == "J")
  {
  std::cout<<"The energy is: "<<energy<<" J"<<std::endl;
  }

  return 0;
}