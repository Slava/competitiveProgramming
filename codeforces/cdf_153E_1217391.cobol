       IDENTIFICATION DIVISION.
          PROGRAM-ID. SOLUTION.

          DATA DIVISION.
          WORKING-STORAGE SECTION.
          01 ARR.
            02 XX        PIC S9(10)9 OCCURS 200 TIMES.
            02 YY        PIC S9(10)9 OCCURS 200 TIMES.
          01 N          PIC 9(10)9.
          01 X          PIC S9(10)9.
          01 Y          PIC S9(10)9.
          01 I          PIC 9(10)9.
          01 J          PIC 9(10)9.
          01 ANS        PIC 9(10)V9(10).
          01 DIST        PIC 9(10)V9(10).
          01 STR      PIC X(10).

          PROCEDURE DIVISION.
            MOVE 0.0 TO ANS
            ACCEPT STR
            MOVE STR TO N
            
            MOVE 1 TO I
            PERFORM N TIMES
                ACCEPT STR
                MOVE STR TO XX(I)
                ACCEPT STR
                MOVE STR TO YY(I)
                ADD 1 TO I
            END-PERFORM
            MOVE 1 TO I
            PERFORM N TIMES
                MOVE 1 TO J
                PERFORM N TIMES
                    IF XX(I) > XX(J) THEN
                    SUBTRACT XX(I) FROM XX(J) GIVING X
                    ELSE
                    SUBTRACT XX(J) FROM XX(I) GIVING X
                    END-IF

                    IF YY(I) > YY(J) THEN
                    SUBTRACT YY(I) FROM YY(J) GIVING Y
                    ELSE
                    SUBTRACT YY(J) FROM YY(I) GIVING Y
                    END-IF

                    MULTIPLY X BY X GIVING X
                    MULTIPLY Y BY Y GIVING Y
                    ADD X TO Y GIVING DIST
                    COMPUTE DIST = FUNCTION SQRT (DIST)
                    IF DIST > ANS
                        MOVE DIST TO ANS
                    END-IF
                    ADD 1 TO J
                END-PERFORM
                ADD 1 TO I
            END-PERFORM
            DISPLAY ANS
            STOP RUN.




// lang: Cobol
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 22, 2012 8:20:17 PM
// contest: 153
// link: /contest/153/submission/1217391
// time: 30 ms
// verdict: Accepted
// problem: 153E - Euclidean Distance
// ID: 1217391
// downloaded by very stupid script
