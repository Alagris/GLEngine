#ifndef EXIT_EXCEPTION_H
#define EXIT_EXCEPTION_H

#include <exception>
namespace gle {

    class ExitException : public std::exception
    {
      public:
        ExitException();
        ExitException(const int exitCode);
        ExitException(const int exitCode,const char *const message);
        virtual ~ExitException();
        virtual const char* what()  const noexcept {
            return m_message;
        }
        virtual const int getExitCode()const {
            return m_exitCode;
        }
      protected:

      private:
        const int m_exitCode;
        const char *const m_message;
    };
}
#endif // EXIT_EXCEPTION_H
