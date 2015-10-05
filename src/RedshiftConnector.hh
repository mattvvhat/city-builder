#pragma once

#include <string>
#include <vector>
#include <libpq-fe.h>

#define GET_TABLES_QUERY "SELECT DISTINCT(tablename) FROM pg_table_def WHERE schemaname = 'public';"

class RedshiftConnector {
private:
  bool mIsConnected;
  std::string mConnectString;

  PGconn   *mConn;
  PGresult *mRes;

  // int         nFields;
  // int         i, j;

public:
  RedshiftConnector(std::string host,
                    std::string port,
                    std::string dbname,
                    std::string user,
                    std::string pass):mIsConnected(false) {
    mConnectString = "";
    mConnectString += "host=" + host;
    mConnectString += " port=" + port;
    mConnectString += " dbname=" + dbname;
    mConnectString += " user=" + user;
    mConnectString += " password =" + pass;
    mConnectString += " connect_timeout=5000";
  }

  void Connect() {
    mConn = PQconnectdb(mConnectString.c_str());
    mIsConnected = (PQstatus(mConn) == CONNECTION_OK);
    if (!mIsConnected) {
      ExitNicely();
    }
  }

  void Disconnect() {
    ExitNicely();
  }

  void ExitNicely() {
    PQfinish(mConn);
    mIsConnected = false;
  }

  void Clear() {
    PQclear(mRes);
  }

  /**
   * Return a Vector of Table Names
   */
  std::vector<std::string> GetTables() {
    std::vector<std::string> table_list;
    int result_status;

    mRes = PQexec(mConn, GET_TABLES_QUERY);
    result_status = PQresultStatus(mRes);

    if (result_status == PGRES_TUPLES_OK) {
      int n_rows = PQntuples(mRes);
      std::cout << n_rows << "!!!\n";
      for (int i=0; i < n_rows; i++) {
        table_list.push_back(PQgetvalue(mRes, i, 0));
      }
    } else {
      Clear();
    }

    return table_list;
  }
};
