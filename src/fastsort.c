#include "mpi.h"

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm comm = MPI_COMM_WORLD;
    int myid, numprocs;
    MPI_Comm_size(comm, &numprocs);
    MPI_Comm_rank(comm, &myid);
    MPI_File fh;
    MPI_File_open(comm, "input.txt", MPI_MODE_RDWR, MPI_INFO_NULL, &fh);
    MPI_File_close(&fh);
    MPI_Finalize();
    return 0;
}
