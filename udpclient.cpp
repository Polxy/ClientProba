#include "udpclient.h"


UDPClient::UDPClient(QObject *parent) :QObject(parent), clientSocket(this)
{
    qDebug()<<"I am your client";
    connect(&clientSocket,SIGNAL(readyRead()),this,SLOT(readReady()));
}

void UDPClient::WriteData(const QString& data)
{
    QByteArray clientData;
    clientData.append( data);
    // write to the port, listening by the server.
    qDebug()<<"Writing datagram to 9999 port";
    clientSocket.writeDatagram(clientData, QHostAddress("192.168.153.1"), 9999 );

}

void UDPClient::readReady()
{
    // got response from server, so clientSoclet port number can get.
    qDebug()<< "Reacieved response from server through my port(Client port No):" << clientSocket.localPort();

    QByteArray buffer;
    buffer.resize(clientSocket.pendingDatagramSize());

    QHostAddress sender;
    quint16 port;
    clientSocket.readDatagram(buffer.data(),buffer.size(),&sender,&port);
    // To read server IP
    qDebug()<< "Server IP Responded" << sender.toString();
    qDebug()<< "Server Port Number" << port;
}
