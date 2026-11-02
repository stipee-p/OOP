#include <cmath>
#include <iostream>

struct Point
{
    double x,y;
};

void move_by(Point* p, double dx, double dy)
{
    p -> x += dx;
    p -> y += dy;
}

double dist(const Point* a, const Point* b)
{
    double dx = a->x - b->x;
    double dy = a->y - b->y; 
    return std::sqrt(dx*dx + dy*dy);
}

void move_by(Point& p, double dx, double dy)
{
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}

int main()
{
    Point p1{3.0 , 4.0};
    Point p2{0.0 , 0.0};
    Point n[5]{ {0.5,0.5},{1.0,1.0},{4.0,9.0},{5.0,3.0},{3.0,2.0} };

    std::cout << "p1 = (" << p1.x << " , " << p1.y << ")" << '\n';
    p1.x = 10;
    std::cout << "p1 = (" << p1.x << " , " << p1.y << ")" << '\n';

    move_by(&p1, 2.0, -1.0);
    std::cout << "p1(pokazivac) = (" << p1.x << " , " << p1.y << ")" << '\n';

    move_by(p1, -2.0, 1.0);
    std::cout << "p1(referenca) = (" << p1.x << " , " << p1.y << ")" << '\n';

    Point p3{4.0,3.0};
    std::cout << "Udaljenost tocaka p2 i p3(pokazivac): " << dist(&p2,&p3) << '\n';
    std::cout << "Udaljenost tocaka p2 i p3(referenca): " << dist(p2,p3) << '\n';

    Point naj = n[0];
    Point ish {0.0,0.0};
    for(const Point& t : n)
    {

        if(dist(t,ish) < dist(naj,ish))
        {
            naj = t; 
        }
    }
    std::cout << "Najbliza ishodistu: (" << naj.x << ", " << naj.y << ")" << '\n'; 
}
