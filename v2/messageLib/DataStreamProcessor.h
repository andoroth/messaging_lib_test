#pragma once

#include <map>

class MsgAdapterBase;
class DataStreamProcessor
{
    public:
        static DataStreamProcessor* Instance();
        void registerMsgAdapter(int id, MsgAdapterBase* adapter);
        MsgAdapterBase* getAdapter(int id);
    private:
        DataStreamProcessor(){}
        std::map<int, MsgAdapterBase*> adapterMap;
        static DataStreamProcessor* instance;
};
