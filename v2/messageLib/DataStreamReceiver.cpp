#include "DataStreamReceiver.h"
#include "MsgAdapterBase.h"
#include "DataStreamProcessor.h"

#include <iostream>

void DataStreamReceiver::processDataStream(DataStream* data) {
    int msgType = MsgAdapterBase::getHeader(data);
    MsgAdapterBase* adapter =  DataStreamProcessor::Instance()->getAdapter(msgType);
    std::cout << "msgType: " << msgType << std::endl;
    adapter->processDataStream(data);
}
