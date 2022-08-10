#include <iostream>
#include <bitset>
#include <fstream>
#include <map>

#include "client_app.h"
#include "block_buffer.hpp"

#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::flush;
using std::bitset;
using std::fstream;

typedef struct LinkList {
    int data;
    struct LinkList* next;

    LinkList() {
        data = 0;
        next = nullptr;
    };

    ~LinkList() {
        delete next;
    }
} LinkList;

void initLinklist(LinkList* linklist) {

}

//LinkList* linklist = new LinkList();
//std::cout << linklist->data;
//std::cout << endl;

//    const std::string string_msg = "tokyo";
//    const std::string file = "D:/Work/server/loginsrv/loginserver201001.log";
//
//    fstream log_file;
//    log_file.open(file, std::ios::in);
//    if (!log_file) {
//        cout << "File not created!";
//        return 0;
//    }
//    string line;
//    while (getline(log_file, line)) {
//        std::cout << line;
//        std::cout << endl;
//    }
//
//    log_file.close();

int main() {
    BlockBuffer blockBuffer;
    blockBuffer.make_client_message(1605);
    blockBuffer.finish_message();

    ClientApp clientApp;
    clientApp.sendData(blockBuffer);

    BlockBuffer receiveBuffer = clientApp.getReceiveBuffer();

    receiveBuffer.dump();
}
