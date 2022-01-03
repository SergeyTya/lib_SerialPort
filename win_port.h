/*
 * win_port.h
 *
 *  Created on: 29 ����. 2021 �.
 *      Author: Sergey
 */

#ifndef WIN_PORT_H_
#define WIN_PORT_H_

#include <windows.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#include "iSerialPort.h"

namespace std {

class WinSerialPort: public ISerialPort {
public:

	WinSerialPort();
	virtual ~WinSerialPort(){};

	 bool openPort(std::string portname, unsigned long baudRate);
	 bool write(char *data, unsigned long len);
	 bool write(char  data);

	 unsigned long read(char *data, unsigned long maxNumBytesRead);

	virtual unsigned long bytesToRead(void);

	virtual bool isOpen() { return this->isOpenPort;};
	virtual bool waitForReadyRead(int timeout);
	virtual bool waitForReadyRead(int timeout , unsigned long size);

	virtual std::string readAll();
	virtual std::string readAll(int timeout);
	virtual std::string getName() const{ return portname; };
	virtual void close(void);

protected:

private:
	//win API fields
	HANDLE hComPort = NULL;
	DCB dcbComPort;
	COMMTIMEOUTS commTimeoutsComPort;
	COMMPROP commPropComPort;
	std::string portname;
	bool isOpenPort =false;




};

} /* namespace std */

#endif /* WIN_PORT_H_ */
