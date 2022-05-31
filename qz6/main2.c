#include <iostream>
#include <string>

using namespace std;

class Clock {
    public:
        int hour;
        int minute;
        int second;
        string timing;
        Clock(int x, int y, int z, string s) {
            hour = x;
            minute = y;
            second = z;
            timing = s;
        }
        void display() {
            cout << hour << ":" << minute << ":" << second << " " << timing << endl;
        }
};

class StandardClock : Clock {
    public:
        StandardClock (int x, int y, int z, string s) : Clock(x, y, z, s) {}
        void display() {
            if (timing == "AM") {
                cout << "上午  " << hour << ":" << minute << ":" << second << endl;
            }else if (timing == "PM") {
                cout << "下午  " << hour << ":" << minute << ":" << second << endl;
            }
        }
            
};

class MilitaryClock : Clock {
    public:
        MilitaryClock (int x, int y, int z, string s) : Clock(x, y, z, s) {}
        void display() {
            if (timing == "AM") {
                cout << hour << ":" << minute << ":" << second << endl;
            }else if (timing == "PM") {
                cout << hour+12 << ":" << minute << ":" << second << endl;
            }
        }
            
};

int main() {
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
