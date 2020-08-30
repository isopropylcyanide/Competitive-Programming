#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    Point(){}
};

struct Rectangle{
	Point tl;
	Point br;
    Rectangle(Point _tl, Point _br){
        tl = _tl;
        br = _br;
    }
};

bool doOverlap(Rectangle a, Rectangle b){
    // If one rectangle is on left side of other
    if (a.tl.x > b.br.x || b.tl.x > a.br.x)
        return false;

    // If one rectangle is above other
    if (a.tl.y < b.br.y || b.tl.y < a.br.y)
        return false;

    return true;
}

bool anyIntersect(vector<Rectangle> &P){
    for (int i = 0; i < P.size(); i++){
        for (int j = 0; j < P.size(); j++){
            if (i == j)
                continue;
            if (doOverlap(P[i], P[j]))
                return true;
        }
    }
    return false;
}

int main(){
	int N, x1, y1, x2, y2;
	cin >> N;
	vector<Rectangle> P;

	for (int i = 0; i < N; i++){
        // Change to tl and br
		cin >> x1 >> y1 >> x2 >> y2;
        P.push_back(Rectangle(Point(x1, y2), Point (x2, y1)));
	}
    string ans = anyIntersect(P) ? "Overlap\n":"No Overlap\n";
    cout << ans << endl;
}
