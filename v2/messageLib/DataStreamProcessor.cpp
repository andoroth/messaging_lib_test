#include "DataStreamProcessor.h"
#include "MsgAdapterBase.h"

DataStreamProcessor* DataStreamProcessor::instance = nullptr;

DataStreamProcessor* DataStreamProcessor::Instance()
{
    if (instance == nullptr)
    {
        instance = new DataStreamProcessor();
        instance->adapterMap = {};
    }
    return instance;
}

void DataStreamProcessor::registerMsgAdapter(int id, MsgAdapterBase* adapter)
{
    adapterMap.insert(std::make_pair(id, adapter));
}

MsgAdapterBase* DataStreamProcessor::getAdapter(int id)
{
    return adapterMap[id];
}
