#ifndef IWALLETDAO_HPP
#define IWALLETDAO_HPP

#include "../../include/entity/Wallet.hpp"
#include <vector>

using namespace std;

class IWalletDAO
{
public:
    virtual ~IWalletDAO() = default;
    virtual bool insertWallet(const Wallet &wallet) = 0;
    virtual vector<Wallet> getAllWallets() = 0;
};

#endif
