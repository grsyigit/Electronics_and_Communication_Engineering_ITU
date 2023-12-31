// e42.cpp
// A constructor with Parameters
#include <iostream>
using namespace std;

class Point{				// Declaration Point Class
   int x,y;					// Properties: x and y coordinates
 public:
   Point(int, int);		// Declaration of the constructor
   bool move(int, int);	// A function to move points
   void print();			// to print cordinates on the screen
};


// ***** Bodies of Member Functions *****

// A constructor with Parameters
// Cooridnates must be pozitive
Point::Point(int x_first=0, int y_first=0)
{
	cout << "Constructor is called..." << endl;
	if ( x_first < 0 )		// If the given value is negative
		x = 0;					// Assigns zero to x
	else
		x = x_first;
	if ( y_first < 0 )		// If the given value is negative
		y = 0;					// Assigns zero to x
	else
		y = y_first;
}

// A function to move the points 
bool Point::move(int new_x, int new_y)
{
	if (new_x >=0 && new_y>=0){
		x = new_x;				// assigns new value to x coordinate
	   y = new_y;				// assigns new value to y coordinate 
		return true;
	}
	return false;
}

// To print the coordinates on the screen 
void Point::print()
{
	cout << "X= " << x << ", Y= " << y << endl;
}
				
// -------- Main Program -------------
int main()
{
  Point array[]= { (10) , (20) , (30,40) }; 
  for (int i=0; i<3; i++)
  	  array[i].print();

	return 0;
}


