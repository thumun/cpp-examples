// Bryn Mawr College, 2021
// Write a program which reads `snacks.txt` and initializes an array of struct Snack

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// TODO: Define struct Snack
struct Snack {
  string name;
  float cost;
  int quantity;
  string description;
};

int main(int argc, char** argv)
{
  string filename = "../files/snacks.txt";

  ifstream file(filename);
  if (!file) // true if the file is valid
  {
     cout << "Cannot load file: " << filename << endl;
     return 1;
  }

  int num = 0;
  file >> num;

  Snack* snacks = new Snack[num];
  for (int i = 0; i < num; i++) {
    string name;
    float cost;
    int quantity;
    string description;

    file >> name; 
    file >> cost; 
    file >> quantity; 
    file >> description; 
    snacks[i] = Snack{ name, cost, quantity, description };
  }
  delete[] snacks; 
}

