#ifndef _ILLEGAL_BALANCE_EXCEPTION_
#define _ILLEGAL_BALANCE_EXCEPTION_

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    virtual const char *what() const noexcept {
        return "Illegal balance exception";
    }
};

#endif
