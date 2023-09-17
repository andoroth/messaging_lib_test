#pragma once

#include <deque>
#include <vector>

#include <iostream>

class TransportLayerDataReceiver;
class TransportLayer {
    public:
        static void broadcast(TransportLayerDataReceiver* sender, std::deque<int>* dataStream);
        static void registerReceiver(TransportLayerDataReceiver* receiver);
        static std::vector<TransportLayerDataReceiver*> receiver_list;
};
