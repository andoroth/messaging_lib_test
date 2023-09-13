
// Common Message library
#include "messages.h"

// Message Serialization library
#include "MessageFactory.h"
#include "SendDataStreamInterface.h"
#include "Msg3Adapter.h"
#include "Msg5Adapter.h"

// Transport layer module
#include "SocketListenerInterface.h"

// StdLib includes
#include <iostream>

class Msg3Adapter_Mod1 : public Msg3Adapter {
    public:
        void receiveMsg(msg3* msg){
            std::cout << "Module1 received msg3: " << msg.data << std::endl;
        }
};
class Msg5Adapter_Mod1 : public Msg5Adapter {
    public:
        void receiveMsg(msg5* msg){
            std::cout << "Module1 received msg5: " << msg.data << std::endl;
        }
};

class SocketInterface_mod1 : public SocketInterface, public SendDataStreamInterface {
    public:
        SocketListener(MessageFactory* msgFactory_in) {
            msgFactory = msgFactory_in;
            registerListner(this);
        }
        virtual void receiveData(int data) {
            DataStreamInterface ds = new DataStreamInterface(data);
            msgFactory.processDataStream(ds);
        }
        void sendDataStream(DataStreamInterface* ds){
            int data = ds.getData;
            broadcast(this, data);
        }
    private:
        MessageFactory* msgFactory;
};

class MessageSender : public Msg1Sender, public Msg2Sender {
    public:
        MessageSender(SendDataStreamInterface* dsSender_in){
            dsSender = dsSender_in;
        }
};

class Module1 {
    public:
        Module1() {
            MessageFactory* msgFactory = new MessageFactory();
            msgFactory.addAdapter(new Msg3Adapter_Mod1());
            msgFactory.addAdapter(new Msg5Adapter_Mod1());

            socketInterface* = new SocketInterface_mod1(msgFactory);

            msgSender = new MessageSender(socketInterface);
        }
        public sendMsg1(int val){
            std::cout << "Module1 Sending msg1: " << val << std::endl;
            msg1 msg;
            msg.data = val;
            msgSender->send(msg);
        }
        public sendMsg2(int val){
            std::cout << "Module1 Sending msg2: " << val << std::endl;
            msg2 msg;
            msg.data = val;
            msgSender->send(msg);
        }
    private:
        MessageSender* msgSender;
};
