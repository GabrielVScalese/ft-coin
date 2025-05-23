#ifndef WALLET_HPP
#define WALLET_HPP

#include <string>

using namespace std;

class Wallet
{
public:
    int id;
    string ownerName;
    string exchange;

    Wallet() = default;
    Wallet(string ownerName, string exchange);
};

#endif
