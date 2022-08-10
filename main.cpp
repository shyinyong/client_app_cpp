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
//    const std::string file = "D:/Work/server/loginsrv/fish5-loginserver201001.log";
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
    ClientApp clientApp;

    BlockBuffer blockBuffer;
    blockBuffer.make_client_message(1605);
//    buffer.write_uint32(1);

//    buffer.make_client_message(1000);
//    std::string account = "m-126108hgnn";
//    std::string passwd = "a58870025879";
//    buffer.write_uint16(1700);
//    buffer.write_uint8(account.length());
//    buffer.write_string(account);
//    buffer.write_uint8(passwd.length());
//    buffer.write_string(passwd);
//    buffer.write_uint16(19);
//    buffer.write_int32(1);
    blockBuffer.finish_message();

    clientApp.sendData(blockBuffer);

    BlockBuffer receiveBuffer = clientApp.getReceiveBuffer();

    receiveBuffer.dump();
}
