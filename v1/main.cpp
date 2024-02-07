#include "foo.h"
#include "bar.h"
#include "baz.h"

int main(int argc, char *argv[]) {
    Foo* foo = new Foo();
    Bar* bar = new Bar();
    Baz* baz = new Baz();

    foo->sendFooMsg1(5);
    foo->sendFooMsg2(8);
    bar->sendBarMsg1(16);
    bar->sendBarMsg2(25);
    baz->sendBazMsg1(-52);
    baz->sendBazMsg2(-83);
}
