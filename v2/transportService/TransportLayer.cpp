#include "TransportLayer.h"
#include "TransportLayerDataReceiver.h"

std::vector<TransportLayerDataReceiver*> TransportLayer::receiver_list = {};
void TransportLayer::broadcast(TransportLayerDataReceiver* sender, std::deque<int>* dataStream){
    for(auto &itr : TransportLayer::receiver_list){
        if(sender != itr){
            itr->receiveDataStream(new std::deque<int>(*dataStream));
        }
    }
}

void TransportLayer::registerReceiver(TransportLayerDataReceiver* receiver){
    TransportLayer::receiver_list.push_back(receiver);
    std::cout << "Registered receiver: " << TransportLayer::receiver_list.size() << std::endl;
}

