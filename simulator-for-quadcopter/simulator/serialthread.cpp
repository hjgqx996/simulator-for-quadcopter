#include "SerialThread.h"
#include "qextserialport.h"

SerialThread::SerialThread(QextSerialPort *port, QObject *parent) : QThread(parent)
{
    this->port = port;
    
    stopped = false;
    bool isOpen = this->port->open(QIODevice::Read);
    if (isOpen) {
    // COMx is already in use
    }
/*    
    port->setBaudRate(BAUD9600);
    port->setDataBits(DATA_8);
    port->setParity(PAR_NONE);
    port->setStopBits(STOP_1);
    port->setFlowControl(FLOW_OFF);
*/    
    qDebug() << "Connected";
}

SerialThread::~SerialThread()
{
    qDebug() << "Disconnected";
}

void SerialThread::run()
{
    do {
        // Read data from COMx
    } while (!stopped);
}

void SerialThread::stopThread()
{
    stopped = true;
}
    
void SerialThread::readData()
{
    // Check the buffer
    if (port->bytesAvailable() == 6)
    QByteArray temp = port->readAll();
    //qDebug() << "read:" << temp;
}
