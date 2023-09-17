#pragma once
#include "MsgAdapterBase.h"

class DataStream;
class ReceiveMsg5;
class msg5;
class Msg5Adapter : public MsgAdapterBase
{
    public:
        Msg5Adapter(ReceiveMsg5* msg5Receiver_in);
        virtual void processDataStream(DataStream*);
        static DataStream* createDataStream(msg5*);
        virtual int getId();
    private:
        ReceiveMsg5* msgReceiver;
        static const int id = 5;
};
