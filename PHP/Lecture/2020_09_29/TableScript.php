
DROP TABLE IF EXISTS loginInfo;

CREATE TABLE IF NOT EXISTS loginInfo(
	email varchar(30) NOT NULL,
	password varchar(30) NOT NULL,
	PRIMARY KEY(email)
);