CREATE TABLE STUDENT (USN VARCHAR (10) PRIMARY KEY,SNAME VARCHAR (25),ADDRESS VARCHAR (25),PHONE NUMBER (10),GENDER CHAR (1));

CREATE TABLE SEMSEC (SSID VARCHAR (5) PRIMARY KEY,SEM NUMBER (2),SEC CHAR (1));

CREATE TABLE CLASS (USN VARCHAR (10),SSID VARCHAR (5),PRIMARY KEY (USN, SSID),FOREIGN KEY (USN) REFERENCES STUDENT (USN),FOREIGN KEY (SSID) REFERENCES SEMSEC (SSID));

CREATE TABLE SUBJECT (SUBCODE VARCHAR (8),TITLE VARCHAR (20),SEM NUMBER (2),CREDITS NUMBER (2),PRIMARY KEY (SUBCODE));

CREATE TABLE IAMARKS (USN VARCHAR (10),SUBCODE VARCHAR (8),SSID VARCHAR (5),TEST1 NUMBER (2),TEST2 NUMBER (2),TEST3 NUMBER (2),FINALIA NUMBER (2),PRIMARY KEY (USN, SUBCODE, SSID),FOREIGN KEY (USN) REFERENCES STUDENT (USN),FOREIGN KEY (SUBCODE) REFERENCES SUBJECT (SUBCODE),FOREIGN KEY (SSID) REFERENCES SEMSEC (SSID));