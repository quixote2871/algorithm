#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	long long x, y;
	bool operator<(Point P) {
		return x<P.x || (x==P.x && y<P.y);
	}
};

int ccw(Point a, Point b, Point c) {
	long long t1 = a.x*b.y+b.x*c.y+c.x*a.y;
	long long t2 = a.y*b.x+b.y*c.x+c.y*a.x;
	if(t1-t2>0) return 1;
	if(t1-t2==0) return 0;
	return -1;
}

class ConvexHull {
	vector<Point> hull;
public:
	ConvexHull(vector<Point> points) {
		int n = points.size();
		sort(points.begin(), points.end());
		for(int i=0; i<n; i++) {
			while(hull.size()>=2 && ccw(hull[hull.size()-2], hull[hull.size()-1], points[i])<=0)
				hull.pop_back();
			hull.push_back(points[i]);
		}
		for(int i=n-2, t=hull.size()+1; i>=0; i--) {
			while(hull.size()>=t && ccw(hull[hull.size()-2], hull[hull.size()-1], points[i])<=0)
				hull.pop_back();
			hull.push_back(points[i]);
		}
		hull.pop_back();
	}
	void print() { // for debug
		for(int i=0; i<hull.size(); i++)
			cout << "[" << hull[i].x << ", " << hull[i].y << "]\n";
	}
	unsigned int size() {
		return hull.size();
	}
	Point operator[](int k) {
		return hull[k];
	}
	bool is_included(Point P) {
		int n = hull.size();
		for(int i=0; i<n; i++)
			if(ccw(hull[i], hull[(i+1)%n], P)<0)
				return false;
		return true;
	}
};
