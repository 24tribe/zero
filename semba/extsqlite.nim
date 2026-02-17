import db_connector/sqlite3

type ExtSqliteError = object of CatchableError

proc loadSql*(db: PSqlite3, sql: string) =
    var err: cstring = nil

    discard exec(db, sql.cstring, nil, nil, err)

    if err != nil:
        let errStr = $err
        sqlite3.free(err)
        raise newException(ExtSqliteError, "loadSql failed: " & errStr)