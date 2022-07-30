#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

// This calculates the waiting time of a single trajectory as a function of s

int main()
{
	int frames=555555;      // 5517 6 number of 5 s  no of frames in a successful trajectory
//	int frames=1;      // no of frames in a successful trajectory
        int i,j,k,l,m;
	int atom_no[116];
 	float  x[116],y[116],z[116], dum_x;  //stores the coordinates of single frame

	FILE *file1, *file2;
	file1=fopen("coordi_single","r");  // file with coordinates of a single frame
	file2=fopen("waiting_time_s_N1.dat","w"); // file where a single traj waiting time is stored

	float s_final ;
	int s, bin[200];
	for(l=0;l<=200;l++)
	{
	bin[l]=0;
	}	

/************* CALCULATION FOR A FRAME **/
for(i=0;i<=frames-1;i++)
{
// Reading a single frame in the trajectory
		for(k=0;k<=10;k++)                        // coordinate of 117 beads in a frames
		{
		fscanf(file1,"%d %f %f %f \n", &atom_no[k], &dum_x, &y[k], &z[k] ); 
//		printf( "dum_x is %f \n", dum_x);
		x[10-k]=dum_x;
//		printf( " read x is %d %f %f \n",10-k ,dum_x, x[0]);
		}

// Reading ends
//		for(l=0;l<=10;l++)
//		{
//		printf( "The read part is %d %f \n", l, x[l]);
//		}
 
/* WAITING TIME CALCULATION  */
			int   monomer=0; // some big value
if(i==0)
{
s_final=0.5;
}
else if (i!=0)
{

		        for(j=0;j<=10;j++)                                          //CHANGE
                        {
				if( x[j]>0.0)
				{
				monomer +=1;               // j-th monomer has crossed the pore
				s=monomer;
				}
//			printf("%d The monomer crossed \n", s );
			}
////////////*************************  exceptions


					//s_final=0.5;
					if(s==0 && x[s-1]> -0.5 && (x[s-1]- x[s]) != 0.0)
					{
					s_final=0.5+ (x[s-1]/fabs(x[s-1]-x[s]));
					}
					else if(s==0 && x[s-1]< -0.5)
					{
					s_final=0.5;
					}
					else if(s==0 && x[s-1]>-0.5 && (x[s-1]-x[s])==0.0)
					{
					s_final=0.5+x[s-1];
					}

					else if(s>0.0 && s<11 )                      // CHANGE
					{
						if(fabs(x[s-1]-x[s]) != 0.0)
						{
						s_final=(double)s-1.0 + 0.5 + fabs(x[s-1])/fabs(x[s-1]-x[s]);
						}
						else if (fabs(x[s-1]-x[s])==0.0)
						{
						s_final=(double)s-1.0+0.5;
						}
					}

					else if(s==11.0 && x[s-1]<0.5)            //CHANGE
					{
					s_final=11.0 - 1.0 + 0.5+x[s-1];          //CHANGE
					}
					else if(s=11.0 && x[s-1]>0.5)            //CHANGE
					{
					s_final=11.0;
					}
}

		for(k=11;k<=116;k++)                        // coordinate of 117 beads in a frames
		{
		fscanf(file1,"%d %f %f %f \n", &atom_no[k], &dum_x, &y[k], &z[k] ); 
//		printf( " read x is %d %f %f \n",10-k ,dum_x, x[0]);
		}

///////////////////////////////////////////////////////////////////////////////////////////////////
//		s_final=5.2;
		
	//	printf("%d \n", abs(s_final));	
	//	bin[abs(s_final)]=bin[abs(s_final)]+1;  //// Putting waiting time according to the calculated s_final

		m=abs(s_final)+1;
		bin[m]=bin[m]+1;  //// Putting waiting time according to the calculated s_final
/* WAITING TIME CALCULATION ENDS HERE */

/*********************************** CALCULATION FOR A FRAME  ENDS **/

}
fclose(file1);


/* FOR PRINTING */

    for(k=1; k <=11; k++)
      {
      fprintf(file2,"%d %d \n",k, bin[k]);
      }
fclose(file2);
return 0;
}

