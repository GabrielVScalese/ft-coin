#include "../../include/entity/Wallet.hpp"

using namespace std;

Wallet::Wallet(string ownerName, string exchange)
    : id(0), ownerName(move(ownerName)), exchange(move(exchange)) {}
