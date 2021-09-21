#include <iostream>
#include "ServerMotor0920.h"
#include <unistd.h>//計時

using namespace std;

ServerMotor0920::ServerMotor0920(int OOP_Port){
    this->OOP_Port=OOP_Port;
}
void ServerMotor0920::Reset() {//重整
    if (error) {
        volt = 0;
        speed = 0;
        current = 0;
        error = false;
    }
}

void ServerMotor0920::Folder(int OOP_Port) {//夾
    while(current < 13) {
        if (OOP_Port == 1) {
            angle -= speed;
        } else {
            angle += speed;
        }
        speed = 7;
        current += 1;        
    }
    speed = 0;
}

void ServerMotor0920::Put(int OOP_Port) {//放
    int times = 0;//計時用
    while(times < 3000){
        if (OOP_Port == 1) {
            angle += speed;
        } else {
            angle -= speed;
        }
        speed = 7;
        sleep(1);
        times += 1;
    }
    times = 0;
    speed = 0;
}

int main() {
    //兩邊
    int port;//連接埠
    cin >> port;
    ServerMotor0920 server1(1);
    ServerMotor0920 server2(port);
    server1.Reset();
    server2.Reset();
    server1.Folder(1);
    server2.Folder(port);
    server1.Put(1);
    server2.Put(port);
}
