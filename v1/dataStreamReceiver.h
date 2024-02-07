#pragma once

class DataStreamReceiver {
    public:
        virtual void receiveDataStream(int* data) = 0;
};
