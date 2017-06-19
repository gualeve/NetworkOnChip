#include "petestreceiverfrontend.h"

PETestReceiverFrontEnd::PETestReceiverFrontEnd(sc_module_name name) :
    sc_module(name)
{
    SC_THREAD(_threadRun);
}

void PETestReceiverFrontEnd::_threadRun()
{
    char receivedChar;
    for (;;) {
		wait(backEndSendEvent());
        receivedChar = fifoInput.read();
        NoCDebug::printDebug(std::string("PE Test Shell Received Char: ") + receivedChar, NoCDebug::NI);
        _message.push_back(static_cast<unsigned>(receivedChar));
        frontEndReceivedEvent();
    }
}

