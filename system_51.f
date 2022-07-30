        PROGRAM folded_coordi
        N1=10
        N=100
        
        DO N=0,100,1
        
                IF(N.LE.N1) THEN
                X1=-(N1-N)*COS(45.0)
                Y1=(N1-N)*SIN(45.0)
                ELSE
                X1=-(N-N1)*COS(45.0)
                Y1=-(N-N1)*SIN(45.0)
                ENDIF
        
        WRITE(*,10) X1, Y1
10      FORMAT(F7.2,5x,F7.2)
        ENDDO

        STOP
        END
