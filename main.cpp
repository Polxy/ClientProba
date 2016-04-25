#include <QtCore/QCoreApplication>
#include "udpclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    UDPClient client;
    client.WriteData("What is my IP");
    return a.exec();
}
