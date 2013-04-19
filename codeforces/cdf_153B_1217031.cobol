       IDENTIFICATION DIVISION.
          PROGRAM-ID. SOLUTION.

          DATA DIVISION.
          WORKING-STORAGE SECTION.
          01 A        PIC 9(7).
          01 B        PIC 9(7).
          01 C        PIC 9(7).
          01 WAS      PIC 9(7).
          01 TWO      PIC 9(7) VALUE 2.
          01 STR      PIC X(10).

          PROCEDURE DIVISION.
            ACCEPT STR
            MOVE STR TO A
            MOVE 0 TO WAS
            MOVE 29 TO B
            PERFORM 30 TIMES
                MOVE 1 TO C
                PERFORM B TIMES
                    MULTIPLY C BY TWO GIVING C
                END-PERFORM
                SUBTRACT 1 FROM B GIVING B
                IF A >= C THEN
                    DISPLAY 1 WITH NO ADVANCING
                    SUBTRACT A FROM C GIVING A
                    MOVE 1 TO WAS
                ELSE
                    IF WAS > 0 THEN
                        DISPLAY 0 WITH NO ADVANCING
                    END-IF
                END-IF
            END-PERFORM
            DISPLAY ""
            STOP RUN.




// lang: Cobol
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 22, 2012 7:52:52 PM
// contest: 153
// link: /contest/153/submission/1217031
// time: 30 ms
// verdict: Accepted
// problem: 153B - Binary notation
// ID: 1217031
// downloaded by very stupid script
