#pragma once

#include <deque>

class TransportLayerDataReceiver {
    public:
        virtual void receiveDataStream(std::deque<int>* data) = 0;
};
