/*
MPI program with two processes: a master and a slave process. Master process with rank 0 reads a integer input from the terminal and send to the slave process. The slave process with rank 1 print out value it received.
*/
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

			//master

	    if(MyRank == 0)
	    {
	       scanf("%d",&var);
	       Destination = Root;
	       Destination_tag = 1;
	       printf("\n MPMD : Process with Rank %d Sending MESSAGE \"%d\" to Process with Rank %d \n\n",MyRank,var,Root);
	       MPI_Send(&var, 1, MPI_INT, Destination, Destination_tag, MPI_COMM_WORLD);
	    }

			//slave

			if(MyRank == 1)
		 {
			Source = 0;
				Source_tag = 1;
						MPI_Recv(&var1, 1, MPI_INT,Source, Source_tag, MPI_COMM_WORLD, &status);
				printf("\n MPMD : Process with Rank %d Received MESSAGE \"%d\"  from Process with Rank %d\n\n",Root,var1,Source);
		 }
	    MPI_Finalize();
	}
