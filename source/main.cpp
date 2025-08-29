#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {

    string line;

    int nPoly = 3;
    double x, y;
    double r = 240.0;
    const double cx = 256.0;
    const double cy = 256.0;


    
    while (true) {
      cout << "enter number of points : ";
      cin >> nPoly;
      ofstream outFile("out.html", ios::trunc);
      ifstream templateFile("htmlTemplate.ini");
      if (!(outFile.is_open() && templateFile.is_open())) {
        cout << "File system eror." << endl;
        return 0;
      }
      templateFile.seekg(0);
      outFile.seekp(0);
      while (getline(templateFile, line)) {
        outFile << line << endl;
      }
      if (nPoly < 3) {nPoly = 3;}
      cout << "drawing " << nPoly << " polygons." << endl;
      outFile << "ctx.beginPath();" << endl;
      outFile << "ctx.moveTo(" << cx << ", " << cy-r << ");" << endl;
      for (int i = 1; i <= nPoly; i++) {
          double angle = 2 * M_PI * i / nPoly;
          x = cx - r * sin(angle);
          y = cy - r * cos(angle);
          outFile << "ctx.lineTo(" << x << ", " << y << ");" << endl;
      }
      outFile << "ctx.closePath();" << endl;
      outFile << "ctx.strokestyle = 'black';" << endl;
      outFile << "ctx.stroke();" << endl;
      outFile << "</script>" << endl;
      outFile << "</body>" << endl;
      outFile << "</html>" << endl;
      outFile.close();
      templateFile.close();
    }
    return 0;
  }