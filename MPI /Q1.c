/*
Program that uses MPI and has each process print the message. This is from process i of n, where i is the rank of process in MPI_COMM_WORLD and n is the number of process.
*/

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    printf("rank %d out of %d processors\n", world_rank, world_size);
    MPI_Finalize();
}
