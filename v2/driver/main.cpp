#include "module1.h"
#include "module2.h"
#include "module3.h"

int main(int argc, char *argv[]) {
    auto mod1 = new mod1::Module1();
    auto mod2 = new mod2::Module2();
    auto mod3 = new mod3::Module3();
    mod1->sendMsg1(5);
    mod1->sendMsg2(6);
    mod2->sendMsg3(15);
    mod2->sendMsg4(38);
    mod3->sendMsg5(-5);
    mod3->sendMsg6(-52);
}
