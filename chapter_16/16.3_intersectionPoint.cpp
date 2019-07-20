/*
     given two lines find the intersetion point
*/
#include<iostream>
using namespace std;

class Point{
public:
     double x;
     double y;
public:
     Point(){

     }
     Point(double x, double y){
          this->x = x;
          this->y = y;
     }
};

class Line{
     double x1;
     double y1;
     double x2;
     double y2;
     double slop;
public:
     Line(Point p1, Point p2){
          x1 = p1.x;
          y1 = p1.y;
          x2 = p2.x;
          y2 = p2.y;
          slop = (y2 - y1)/(x2 - x1);
     }

     double Slop(){
          return slop;
     }

     double yIntersept(){
          return y2 - slop*x2;
     }
};

void Swap(Point &p1, Point &p2){
     Point p;
     p = p1;
     p1 = p2;
     p2 = p;
}

bool isbetween(Point start, Point end, Point middle){
     if((start.x < middle.x && end.x > middle.x) && (start.y < middle.y && end.y > middle.y))
          return true;
     return false;
}

Point intersection(Point start1, Point end1, Point start2, Point end2){

     if(start1.x > end1.x)
          swap(start1,end1);
     if(start2.x > end2.x)
          swap(start2,end2);
     if(start1.x > start2.x){
          swap(start1,start2);
          swap(end1,end2);
     }

     Line l1(start1,end1);
     Line l2(start2,end2);

     if(l1.Slop() == l2.Slop()){
          if(l1.yIntersept() == l2.yIntersept() && isbetween(start1,end1,start2))
               return start2;
     }

     double x = (l2.yIntersept() - l1.yIntersept())/(l2.Slop() - l1.Slop());
     double y = x*l1.Slop() + l1.yIntersept();
     Point intersect(x,y);

     if(isbetween(start1,end1,intersect) && isbetween(start2,end2,intersect))
          return intersect;
     return Point(0,0);
}

int main(){
     Point start1(2,4);
     Point start2(4,12);
     Point end1(6,8);
     Point end2(8,10);
     Point ans = intersection(start1,end1,start2,end2);
     std::cout << ans.x << " " << ans.y << '\n';
}
