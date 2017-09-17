#include "interpret.h"

interpret::interpret(string filename){
  circuit = LoadCircuit(filename);
}

string* interpret::LoadCircuit(string filename){
  // get circuit's dimensions
  uint width, height;

  string line;
  ifstream file(filename);

  while(getline(file, line)){
    height++;

    if(line.length() > width) // new longest line
      width = line.length();
  }

  // pull lines to memory
  string* circuit = new string[height];

  file.seekg(0); // reset reader
  for(int i = 0; i < height; i++){
    getline(file, line);

    circuit[i] = line + string(height - line.length(), ' '); // pad to width
  }

  return circuit;
}
