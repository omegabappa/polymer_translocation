	PROGRAM avvg
	IMPLICIT NONE
	INTEGER i, n, j,k
	REAL x(200),y(200),sum_y,avg_time,multi
!	OPEN (1,FILE='new1.xvg')
!	OPEN (1,FILE='waiting_time_F30_new.xvg')
	OPEN (1,FILE='waitingtime_s_N1_11.xvg')
	DO 10 i = 1,11
	READ(1,*)x(i),y(i)
!			WRITE(*,*)y(i),x(i)
!90	FORMAT(F8.6)
10	CONTINUE



		avg_time=0.0
		multi=0.0
		
			DO 30 k=1,11
			multi = (y(k)+y(k+1))/2.0
			avg_time=avg_time + (multi)
			
30			CONTINUE
			WRITE(*,*)avg_time

	CLOSE(1)
	STOP
	END
