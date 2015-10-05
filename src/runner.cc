/**
 * :D
 */

#include <stdlib.h>
#include <iostream>
#include <libpq-fe.h>
#include <string>
#include <vector>

#include "RedshiftConnector.hh"

/**
 * Quit Postgres Connection
 * @param conn postgres connection
 */
//void exit_nicely(PGconn *conn) {
//  PQfinish(conn);
//  exit(1);
//}

/**
 * Return a List of 
 * @param 
 */
//void GetTableList(PGresult *res) {
//  int n_fields = PQnfields(res);
//  int n_rows   = PQntuples(res);
//  std::cout << n_rows << "x" << n_fields << "\n";
//  std::cout << n_rows << "x" << n_fields << "\n";
//  std::cout << n_rows << "x" << n_fields << "\n";
//  for (int i=0; i < n_rows; i++) {
//    for (int j=0; j < n_fields; j++) {
//      std::cout << "* " << PQgetvalue(res, i, j) << " ";
//    }
//    std::cout << "\n";
//  }
//}

/**
 * Main
 */
int main(int argc, char **argv) {
  std::vector<std::string> table_list;
  RedshiftConnector connector(
    );

  connector.Connect();

  table_list = connector.GetTables();

  for (auto it=table_list.begin(); it != table_list.end(); ++it) {
    std::cout << *it << "\n";
  }


//std::cout << "Fin.";

  return 0;
}
