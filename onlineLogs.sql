DROP TABLE IF EXISTS debugLogs;
CREATE TABLE debugLogs (
    receivedAt STRING,
    uri STRING,
    req STRING,
    res STRING
);