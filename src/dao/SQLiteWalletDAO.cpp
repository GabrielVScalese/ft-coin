#include "../../include/dao/SQLiteWalletDAO.hpp"
#include <iostream>

using namespace std;

SQLiteWalletDAO::SQLiteWalletDAO(const string &dbPath)
{
    if (sqlite3_open(dbPath.c_str(), &db))
    {
        cerr << "Erro ao abrir SQLite: " << sqlite3_errmsg(db) << endl;
        db = nullptr;
    }
}

SQLiteWalletDAO::~SQLiteWalletDAO()
{
    if (db)
        sqlite3_close(db);
}

bool SQLiteWalletDAO::insertWallet(const Wallet &wallet)
{
    const char *sql = "INSERT INTO wallets (owner_name, exchange) VALUES (?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt, 1, wallet.ownerName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, wallet.exchange.c_str(), -1, SQLITE_TRANSIENT);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);

    return success;
}

vector<Wallet> SQLiteWalletDAO::getAllWallets()
{
    vector<Wallet> wallets;
    const char *sql = "SELECT id, owner_name, exchange FROM wallets;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return wallets;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Wallet w;
        w.id = sqlite3_column_int(stmt, 0);
        w.ownerName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        w.exchange = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        wallets.push_back(w);
    }

    sqlite3_finalize(stmt);

    return wallets;
}
