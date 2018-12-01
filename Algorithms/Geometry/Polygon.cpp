/*
  1. Area
  2. Perimeter
  3. isConvex
  4. scaling a vector
  5. dot product of 2 vectorrs
  6. Cross product of 2 vectors
  7. Polygon reading
  8. point "pt" inside polygon "P"
*/
class Point{
public:
	double x, y;

	// P1 ^ P2 = P1.x * P2.y - P1.y * P2.x
	double operator ^(Point const &obj){
		return x * obj.y - obj.x * y;
	}
};

double dist(Point p1, Point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

struct vec{
	double _x, _y;
	vec(double _x, double _y): _x(_x), _y(_y){}
};

vec toVec(Point a, Point b){
	return vec(b.x-a.x, b.y-a.y);
}

vec scale(vec v, double s){
	return vec(v._x * s, v._y * s);
}

double dot(vec a, vec b){
	return (a._x * b._x + a._y * b._y);
}

double cross(vec a, vec b){
	return a._x * b._y - a._y * b._x;
}

// Counter-clockwise test
bool ccw(Point p, Point q, Point r){
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

vector<Point> readPolygon(){
	vector<Point> polygon;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		Point p;
		cin >> p.x >> p.y;
		polygon.push_back(p);
	}

	// assert
	assert(polygon.size() > 1);

	polygon.push_back(polygon[0]);
	return polygon;
}

double perimeter(const vector<Point> &P){
	double ret = 0.0;
	for(int i = 0; i < P.size() - 1; i++){
		ret += dist(P[i], P[i+1]);
	}
	return ret;
}

double area(vector<Point> &P){
	double ret = 0.0;
	for(int i = 0; i < P.size()-1; i++){
		ret += (P[i] ^ P[i+1]);
	}
	return ret / 2.0;
}

bool isConvex(const vector<Point> &P){
	if(P.size() <= 3) return 0;
	bool isLeft = ccw(P[0], P[1], P[2]);
	for(int i = 1; i < P.size() - 1; i++){
		if(ccw(P[i], P[i+1], P[(i+2) == P.size() ? 1 : i+2]) != isLeft){
			return 0;
		}
	}
	return 1;
}

double norm_sq(vec v){
	return v._x * v._x + v._y * v._y;
}

double angle(Point a, Point o, Point b){
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool pointInsidePolygon(Point pt, const vector<Point> &P){
	if(P.size() == 0){
		return 0;
	}
	double sum = 0.0;
	for(int i = 0; i < P.size() - 1; i++){
		if(ccw(pt, P[i], P[i+1])){
			sum += angle(P[i], pt, P[i+1]);
		}else{
			sum -= angle(P[i], pt, P[i+1]);
		}
	}
	return fabs(fabs(sum) - 2*PI) < EPS;
}
