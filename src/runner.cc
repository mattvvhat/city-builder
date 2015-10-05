/**
 * :D
 */

#include <stdlib.h>
#include <iostream>
#include <libpq-fe.h>
#include <string>

/**
 * Quit Postgres Connection
 * @param conn postgres connection
 */
void exit_nicely(PGconn *conn) {
  PQfinish(conn);
  exit(1);
}

/**
 * Return a List of 
 * @param 
 */
void GetTableList(PGresult *res) {
  int n_fields = PQnfields(res);
  int n_rows   = PQntuples(res);

  std::cout << n_rows << "x" << n_fields << "\n";
  std::cout << n_rows << "x" << n_fields << "\n";
  std::cout << n_rows << "x" << n_fields << "\n";

  for (int i=0; i < n_rows; i++) {
    for (int j=0; j < n_fields; j++) {
      std::cout << "* " << PQgetvalue(res, i, j) << " ";
    }
    std::cout << "\n";
  }
}

/**
 * Main
 */
int main(int argc, char **argv) {

  PGconn     *conn;
  PGresult   *res;
//int         nFields;
//int         i, j;

  // Create string
  std::string connection_string = "";

  // Print out connection string
  std::cout << "connection string: " << connection_string.c_str() << "\n";

  // Attempt connection to postgres
  conn = PQconnectdb(connection_string.c_str());

  // See if connection is good
  if (PQstatus(conn) != CONNECTION_OK) {
    std::cout << "Connection to database failed: " <<  PQerrorMessage(conn) << "\n";
    exit_nicely(conn);
  } else {
    std::cout << "Connection is cool.\n";
  }

  // Attempt select statement query
  res = PQexec(conn, "select distinct(tablename) from pg_table_def where schemaname = 'public';");

  // Get results
  int result_status = PQresultStatus(res);

  // See if select statement is good
  if (result_status != PGRES_TUPLES_OK) {
    std::cout << "Query failed. " << PQerrorMessage(conn) << " -> " << result_status << "/" << PGRES_TUPLES_OK << "\n";
    PQclear(res);
    exit_nicely(conn);
  } else {
    GetTableList(res);
    PQclear(res);
    std::cout << "Query is cool.\n";
  }


  std::cout << "Fin.";

  return 0;
}
