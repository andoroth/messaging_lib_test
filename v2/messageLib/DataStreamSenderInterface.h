#pragma once

class DataStream;
class DataStreamSenderInterface
{
    public:
        virtual void sendDataStream(DataStream*) = 0;
};

