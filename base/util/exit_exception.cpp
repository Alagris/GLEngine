#include "exit_exception.h"
namespace gle {
    const char * const defaultExitMessage="System exit triggered!";
    ExitException::ExitException():ExitException(0){}
    ExitException::ExitException(const int exitCode):ExitException(exitCode,defaultExitMessage){}
    ExitException::ExitException(const int exitCode,const char *const message):m_exitCode(exitCode),m_message(message){}
    ExitException::~ExitException(){}
}
