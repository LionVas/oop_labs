#include <fstream>
#include<string>
#include<iostream>
using namespace std;
struct rectangle{
    double width;
    double height;
    double x;
    double y;
    string fill ="black";
};
struct polygon{
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    string fill ="black";
};
ostream& operator <<(ostream& os, const polygon& obj){
    return os <<"<polygon points =\"" << obj.x1 << " "<<obj.y1 << ", " << obj.x2 << " "<< obj.y2 << ", " << obj.x3 << " "<< obj.y3<<"\" " << "fill=\"" << obj.fill << "\" />";
}
ostream& operator <<(ostream& os, const rectangle& obj){
    return os <<"<rect width = \"" << obj.width << "\" " << "height = \""<< obj.height<< "\" " << "x= \"" << obj.x <<"\" " << "y = \"" << obj.y <<"\" " <<"fill =\"" << obj.fill <<"\" />" ;
}
int main(){
    rectangle a{40, 70, 30, 5, "#c86643"};
    polygon b{65, 47, 70, 35, 70, 55, "white"};
    rectangle c{5, 65, 69, 13, "white"};
    polygon d{60, 0, 85, 20, 75, 35, "#336b60"};
    rectangle e{5, 70, 25, 0, "#31221f"};
    rectangle f{5, 30, 27, 25, "#c0494d"};
    ofstream fout("picture.svg");
    fout << "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox= \"0 0 100 100\">" << "\n";
    fout << a << "\n" << b << "\n"<< c << "\n" << d << "\n" << e << "\n" << f << "\n";
    fout <<"</svg>";
    fout.close();
    return 0;
}