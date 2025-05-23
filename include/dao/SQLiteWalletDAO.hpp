#ifndef SQLITEWALLETDAO_HPP
#define SQLITEWALLETDAO_HPP

#include "IWalletDAO.hpp"
#include <sqlite3.h>

using namespace std;

class SQLiteWalletDAO : public IWalletDAO
{
private:
    sqlite3 *db;

public:
    explicit SQLiteWalletDAO(const string &dbPath);
    ~SQLiteWalletDAO();

    bool insertWallet(const Wallet &wallet) override;
    vector<Wallet> getAllWallets() override;
};

#endif
