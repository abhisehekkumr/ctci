/*
     given graph of 2D points in plane find the best line that passes through
     maximum number of points thus return maximum number of points that can
     be passed through single
*/

#include<iostream>
#include<cmath>
#include<unordered_map>
#include<set>
using namespace std;

class Point{
public:
     double x;
     double y;
};

class Line{
public:
     double epsilon = 0.001;
     double slop,intercept;
     bool infinite_slop = false;

     Line(){
          slop = 0;
          intercept = 0;
     }

     Line(Point p, Point q){
          // if x's are not equal calculate slop
          if(abs(p.x - q.x) > epsilon){
               slop = (p.y - q.y)/(p.x - q.x);
               // y intercept is calculated using y = mx + c, basically we
               // are calculating c
               intercept = p.y - Slop*p.x;
          }
          // infinte slop will result
          else{
               infinite_slop = true;
               intercept = p.x;
          }
     }

     // dividing something and converting to the int will take me to the nearest
     // but smallest value and multiply it with again will give me same value but
     // to best nearest smallest possible
     double floorToNearestEpislon(double d){
          int r = (int)(d/epsilon);
          return (double)(r*epsilon);
     }

     // checking for presicion error due to finite precision
     bool isEquivalent(double a, double b){
          return ((a-b) <= epsilon);
     }

     // checking for validity of an two equations either belonging to same line
     // or not
     bool isEquivalent(Line l){
          if(isEquivalent(l.slop,Slop) && isEquivalent(l.intercept,intercept) &&
               infinite_slop == l.infinite_slop)
               return true;
          return false;
     }
};


// two lines are equivalent if they lines in epsilon distance from earch other
int countEquivalentLines(unordered_map<double,line> map, Line line){
     double key = line.floorToNearestEpislon(line.slop);
     int count = map.count(key);
     count += map.count(key + line.epsilon);
     count += map.count(key - line.epsilon);
     return count;
}

// counting equivalent lines
int countEquivalentLines(vector<Line> &lines, Line line){
     if(lines.size() == 0)
          return 0;
     int count = 0;
     for(int i = 0; i < lines.size(); i++){
          if(line.isEquivalent(lines[i]))
               count++;
     }
     return count;
}

Line getBestLine(unordered_map<double,Line> linesBySlop){
     Line bestLine;
     int bestCount = 0;
     set<double> slopes;

     unordered_map<double, Line> :: iterator it;
     for(it = m.begin(); it != m.end(); it++)
          slopes.insert(it->first);

     vector<Line> v;
     for(it = m.begin(); it != m.end(); it++)
          v.push_back()

     for(int i = 0; i < slopes.size(); i++){
          vector<Line> lines

     }
}

unordered_map<double, Line> getListofLines(Point arr[], int n){
     unordered_map<double,Line> linesBySlop;
     for(int i = 0; i < n; i++){
          for(int j = i+1; j < n; j++){
               Line line(arr[i],arr[j]);
               double key = line.floorToNearestEpislon(line.slop);
               linesBySlop[key] = line;
          }
     }
     return linesBySlop;
}

Line findBestLine(Point arr[], int n){
     unordered_map<double,Line> map = getListofLines(arr,n);
     return getBestLine(map);
}

int main(){
     int n;
     cin >> n;

     Point arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i].x >> arr[i].y;

     std::cout << maxPoints(arr,n) << '\n';
}

/*
8
1 1
1 3
2 2
2 3
3 3
4 1
4 2
4 4
*/
