#include <stdio.h>
#include "mpi.h"
#define BUFFER_SIZE 200
	int main(argc,argv)
	int argc;
	char *argv[];
	{
	    int  MyRank, Destination, Source, Numprocs;
	    int  Destination_tag, Source_tag;
	    int  Root = 1,len_name ;
	    char proc_name[100],proc_name_root[100];
	     MPI_Status status;
			 int var, var1;
	    MPI_Init(&argc,&argv);
	    MPI_Comm_rank(MPI_COMM_WORLD,&MyRank);
	    MPI_Comm_size(MPI_COMM_WORLD,&Numprocs);

	    if(MyRank == 0)
	    {
	       scanf("%d",&var);
	    }


            MPI_Bcast(&var,1,MPI_INT,0,MPI_COMM_WORLD);
            printf("\n %d Message 15 received by process %d",var,MyRank);
	    MPI_Finalize();
	}
