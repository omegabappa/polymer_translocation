	PROGRAM avvg
	IMPLICIT NONE
	INTEGER i, n, j,k
	REAL mus(99500),avg(1001)
!	OPEN (1,FILE='15f_waiting_time')
	OPEN(1,FILE='waitingtime_s_N1_11')
	DO 10 n = 1,7370 ! 49700
	READ (1,*)mus(n)
!90	FORMAT(F8.6)
10	CONTINUE
		
		n=1
 		DO 20 j= 1, 11,1
			avg(j)=0.0      
			DO 30 i=1,670
			avg(j) = avg(j) + mus(n)
	!		WRITE(*,*) mus(n)
			n=n+11
30			CONTINUE
			n=j+1
20			CONTINUE


	OPEN (2,FILE='waitingtime_s_N1_11.xvg')
	DO 40 k= 1,11
	WRITE(2,*)k, (avg(k)/670.0)*0.0005
!91	FORMAT(F8.4,F8.6)
40	CONTINUE

	CLOSE(1)
	CLOSE(2)
	STOP
	END
