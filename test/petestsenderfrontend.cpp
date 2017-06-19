#include "petestsenderfrontend.h"

PETestSenderFrontEnd::PETestSenderFrontEnd(sc_module_name name) :
    sc_module(name)
{
    _msgDestination = 1;

    SC_THREAD(_threadRun);
}

void PETestSenderFrontEnd::_threadRun()
{
    char sendChar;
    for (;;) {
        sendChar = _message.back();
        _message.pop_back();
        NoCDebug::printDebug(std::string("PE Test Shell Send Char: ") + sendChar, NoCDebug::NI);
        frontEndSendEvent();
        wait(backEndReceivedEvent());
    }
}