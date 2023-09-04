
#include "transport.h"
#include "messagePasser.h"

class Msg1Encoder {
    public:
        static const int ID = 1;
        static int* encode(msg1 msg){
            static int dataStream[2];
            dataStream[0] = ID;
            dataStream[1] = msg.data;
            std::cout << "Encoding msg1: " << dataStream[1] << std::endl;
            return dataStream;
        }
        static msg1 decode(int data){
            msg1 msg;
            msg.data = data;
            return msg;
        }
};

class Msg2Encoder {
    public:
        static const int ID = 2;
        static int* encode(msg2 msg){
            static int dataStream[2];
            dataStream[0] = ID;
            dataStream[1] = msg.data;
            std::cout << "Encoding msg2: " << dataStream[1]<< std::endl;
            return dataStream;
        }
        static msg2 decode(int data){
            msg2 msg;
            msg.data = data;
            return msg;
        }
};

MessagePasser::MessagePasser(MsgReceiver* mr_in){
    TransportLayer::registerReceiver(this);
    mr = mr_in;
}

void MessagePasser::receiveDataStream(int* dataStream){
    switch (dataStream[0]){
        case Msg1Encoder::ID:
            {
                msg1 msg = Msg1Encoder::decode(dataStream[1]);
                mr->receiveMsg(msg);
            }
            break;
        case Msg2Encoder::ID:
            {
                msg2 msg = Msg2Encoder::decode(dataStream[1]);
                mr->receiveMsg(msg);
            }
            break;
    }
}
void MessagePasser::send(msg1 msg){
    int* dataStream = Msg1Encoder::encode(msg);
    TransportLayer::broadcast(this, dataStream);
}
void MessagePasser::send(msg2 msg){
    int* dataStream = Msg2Encoder::encode(msg);
    TransportLayer::broadcast(this, dataStream);
}
