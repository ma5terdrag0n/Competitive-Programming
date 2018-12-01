
// If not already added uncomment next line
// typedef long long ll;

class Point{
public:
	ll x, y;
	Point(){}
	Point(ll x, ll y): x(x), y(y){}
	
	// Vector from Point A to B = A - B
	Point operator - (Point const &obj){
		Point ret(x - obj.x, y - obj.y);
		return ret;
	}

	// Point A, B, it will return A.x*B.y - A.y*B.x
	ll operator ^ (Point const &obj){
		return x * obj.y - y * obj.x;	
	}
};

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
    return false; 
} 

int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1,q1' and 'p2,q2' intersect. 
bool doLinesIntersect(Point p1, Point q1, Point p2, Point q2) { 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) 
        return true;  
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;    
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
    return false;
} 
