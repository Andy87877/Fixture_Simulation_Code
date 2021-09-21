#include <iostream>
using namespace std;

class ServerMotor0920 {
    protected:
              // 伏特      速度        角度        電流
        double volt = 0, speed = 0, angle = 0, current = 0;
        int OOP_Port;//連接埠
        bool error = false;//是否錯誤
    public:
        ServerMotor0920(int);
        void Reset();
        void Folder(int);
        void Put(int);
};

