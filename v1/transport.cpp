#include "transport.h"
#include "dataStreamReceiver.h"

DataStreamReceiver* TransportLayer::receiver_list[4] = {};
int TransportLayer::receiver_count = 0;
void TransportLayer::broadcast(DataStreamReceiver* sender, int* dataStream){
    for(int i = 0; i < TransportLayer::receiver_count; i++){
        if(sender != TransportLayer::receiver_list[i]){
            TransportLayer::receiver_list[i]->receiveDataStream(dataStream);
        }
    }
}

void TransportLayer::registerReceiver(DataStreamReceiver* receiver){
    TransportLayer::receiver_list[TransportLayer::receiver_count] = receiver;
    TransportLayer::receiver_count += 1;
    std::cout << "Registered receiver: " << TransportLayer::receiver_count << std::endl;
}

