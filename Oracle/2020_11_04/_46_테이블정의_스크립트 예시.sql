--client ���̺��� �����϶�
DROP TABLE client;

--client ���̺��� �����϶�
CREATE TABLE client(
  cnum NUMBER,
  cname VARCHAR2(50),
  addr VARCHAR2(200),
  tel VARCHAR2(20)
);

--server ���̺��� �����϶�
DROP TABLE server;

--server ���̺��� �����϶�
CREATE TABLE server(
  cnum NUMBER,
  cname VARCHAR2(50),
  addr VARCHAR2(200),
  tel VARCHAR2(20)
);
