#include "DataStreamReceiverInterface.h"
#include "MsgAdapterBase.h"
#include "DataStreamProcessor.h"

#include <iostream>

void DataStreamReceiverInterface::receiveDataStream(DataStream* data) {
    int msgType = MsgAdapterBase::getHeader(data);
    MsgAdapterBase* adapter =  DataStreamProcessor::Instance()->getAdapter(msgType);
    std::cout << "msgType: " << msgType << std::endl;
    adapter->processDataStream(data);
}
