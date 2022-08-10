#include "block_buffer.hpp"

#define DEFAULT_BUFFLEN 1024
#define DEFAULT_PORT "7235"

typedef unsigned short Word;
typedef unsigned short StHead;

typedef struct Pkt {
    Word cver;
    Word account;
} Pkt;

class BlockBuffer;

class ClientApp {
private:
    BlockBuffer receiveBuffer{};

public:
    // TaskClient();

    int sendData(BlockBuffer& buffer);
    BlockBuffer getReceiveBuffer() const;
};
