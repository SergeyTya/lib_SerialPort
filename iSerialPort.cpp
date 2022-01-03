/*
 * iSerialPort.cpp
 *
 *  Created on: 30 дек. 2021 г.
 *      Author: Sergey
 */

#include "iSerialPort.h"
#include "win_port.h"

namespace std {

 unique_ptr<ISerialPort> ISerialPort::create(){

	 return std::unique_ptr<ISerialPort> (new WinSerialPort());
}

 ISerialPort * ISerialPort::create2(){

	 return new   WinSerialPort() ;
}



} /* namespace sp */
