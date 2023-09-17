#pragma once

#include <map>

class DataStream;
class MsgAdapterBase;
class DataStreamReceiverInterface
{
    public:
        void receiveDataStream(DataStream*);
        void registerMsgAdapter(int id, MsgAdapterBase* adapter);
        MsgAdapterBase* getAdapter(int id);
    private:
        std::map<int, MsgAdapterBase*> adapterMap;
};

