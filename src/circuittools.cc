#include "circuittools.h"
#include "tiletools.h"

using namespace std;

// check point inside circuit
bool WithinBounds(Point p, vector<string> circuit){
  int width = circuit[0].length();
  int height = circuit.size();

  if(p.x < 0 || p.x >= width)
    return false;
  if(p.y < 0 || p.y >= height)
    return false;

  return true;
}

// where can a dot escape to from point p in circuit
vector<Point> FindEscapes(Point p, vector<string> circuit){
  int map[] = { 0, 3, 1, 2 }; // maps vecDir order to clockDir values
  // easier to map order than value to a clockDir
  int order = -1; // -1 since we tick BEFORE operations

  vector<Point> out;

  for(int y = -1; y <= 1; y++) for(int x = -1; x <= 1; x++){
    Point o { x, y }; // offset
    Point q = p + o; // offset p by o

    // escapes

    if(!( (x == 0) ^ (y == 0) ))
    continue; // ONE and ONLY ONE offset must be 0

    order++; // next vector to be used

    if(!WithinBounds(q, circuit))
    continue; // certainly not

    if(ValidEntry(circuit[q.y][q.x], map[order]))
    out.push_back(o); // valid vector, push to output
  }

  return out;
}
