#include <iostream>
#include <math.h>
using namespace std;
class Segment {
public:
	double getLenght() {
		return sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));
	}
	Segment(int x1, int y1, int x2, int y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	};
	bool operator == (Segment& otherSegment) {
		if (this->x1 == otherSegment.x1 &&
			this->x2 == otherSegment.x2 &&
			this->y1 == otherSegment.y1 &&
			this->y2 == otherSegment.y2) {

			return true;
		}
		else { return false; }
	}
	bool operator < (const Segment& otherSegment) {
		return sqrt((pow((this->x2 - this->x1), 2)) + (pow((this->y2 - this->y1), 2))) <
			sqrt((pow((otherSegment.x2 - otherSegment.x1), 2)) + (pow((otherSegment.y2 - otherSegment.y1), 2)));
	};
	bool operator > (const Segment& otherSegment) {
		return sqrt((pow((this->x2 - this->x1), 2)) + (pow((this->y2 - this->y1), 2))) >
			sqrt((pow((otherSegment.x2 - otherSegment.x1), 2)) + (pow((otherSegment.y2 - otherSegment.y1), 2)));
	};
	friend ostream& operator << (ostream& out, const Segment& segment) {
		cout << "x1: " << segment.x1 << endl;
		cout << "x2: " << segment.x2 << endl;
		cout << "y1: " << segment.y1 << endl;
		cout << "y2: " << segment.y2 << endl;
		return out;
	}



	friend istream& operator >> (std::istream& in, Segment& segment)
	{
		cin >> segment.x1 >> segment.x2 >> segment.y1 >> segment.y2;
		return in;
	}

	friend void operator  *=(Segment& segment, const int multiplicator) {
		segment.y2 *= multiplicator;
		segment.x2 *= multiplicator;
	}

private:
	int x1;
	int y1;
	int x2;
	int y2;



};


int main() {
	Segment segment = Segment(1, 1, 5, 5);
	Segment segment2 = Segment(2, 2, 4, 4);
	Segment segment3 = Segment(1, 1, 5, 5);
	cout << segment << endl;
	cout << segment2 << endl;
	cout << segment3 << endl;
	bool isEqual = segment == segment2;
	cout << isEqual << endl;
	isEqual = segment == segment3;
	cout << isEqual << endl;
	bool isBigger = segment < segment2;
	cout << isBigger;
	cout << endl;
	bool isSmaller = segment > segment2;
	cout << isSmaller;
	cout << endl;
	segment *= 11;
	cout << segment;

}