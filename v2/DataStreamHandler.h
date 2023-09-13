
#include "DataStreamInterface.h"
#include "MessageReceiverInterface.h"
#include "MsgAdapterBase.h"


#include <map>
#include <iostream>

class MessageFactory {
    public:
        MessageFactory(MessageReceiverInterface* msgReceiver_in) {
            msgReceiver = msgReceiver_in;
        }
        void addAdapter(MsgAdapterBase* adapter){
            adapterMap.insert(make_pair(adapter.getId(), adapter));
        }
        void processDataStream(DataStreamInterface* data){
            AdapterID id = MsgAdapterBase::getHeader(data);
            MsgAdapterBase* msgAdapter = adapterMap.get(id);
            if (msgAdapter != nullptr) {
                msgAdapter.processData(data, msgReceiver);
            }
            else {
                std::cout << "MsgID not handled: " << id << std::endl;
            }
        }
    protected:
        std::map<AdapterID, MsgAdapterBase*> adapterMap;
        MessageReceiverInterface* msgReceiver;
}
