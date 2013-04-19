       IDENTIFICATION DIVISION.
          PROGRAM-ID. SOLUTION.

          DATA DIVISION.
          WORKING-STORAGE SECTION.
          01 A        PIC 9(10)9.
          01 B        PIC 9(10)9.
          01 C        PIC Z(10)9.
          01 STR      PIC X(10).

          PROCEDURE DIVISION.
            ACCEPT STR
            MOVE STR TO A
            ACCEPT STR
            MOVE STR TO B
            ADD A TO B
            MOVE B TO C
            DISPLAY C
            STOP RUN.




// lang: Cobol
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 22, 2012 7:34:45 PM
// contest: 153
// link: /contest/153/submission/1216776
// time: 30 ms
// verdict: Accepted
// problem: 153A - A + B
// ID: 1216776
// downloaded by very stupid script
