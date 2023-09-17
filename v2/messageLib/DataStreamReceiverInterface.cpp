#include "DataStreamReceiverInterface.h"
#include "MsgAdapterBase.h"

#include <iostream>

void DataStreamReceiverInterface::receiveDataStream(DataStream* data) {
    int msgType = MsgAdapterBase::getHeader(data);
    MsgAdapterBase* adapter =  getAdapter(msgType);
    //std::cout << "msgType: " << msgType << " adapter: " << adapter << std::endl;
    if (adapter)
        adapter->processDataStream(data);
}

void DataStreamReceiverInterface::registerMsgAdapter(int id, MsgAdapterBase* adapter)
{
    //std::cout << "Registered Receiver: " << id << " " << adapter << std::endl;
    adapterMap.insert(std::make_pair(id, adapter));
}

MsgAdapterBase* DataStreamReceiverInterface::getAdapter(int id)
{
    //std::cout << "Retrieving Receiver: " << id << " " << adapterMap[id] << std::endl;
    return adapterMap[id];
}
