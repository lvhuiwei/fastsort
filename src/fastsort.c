#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm comm = MPI_COMM_WORLD;
    int myid, numprocs;
    MPI_Comm_size(comm, &numprocs);
    MPI_Comm_rank(comm, &myid);

    FILE * fp_r;
    long fsize;
    char * buffer;
    size_t result;
    fp_r = fopen ( "input" , "rb" );
    if (fp_r==NULL) {fputs ("File error",stderr); exit (1);}
    fseek (fp_r , 0 , SEEK_END);
    fsize = ftell (fp_r);
    rewind (fp_r);
    buffer = (char*) malloc (sizeof(char)*fsize);
    if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
    result = fread (buffer,1,fsize,fp_r);
    if (result != fsize) {fputs ("Reading error",stderr); exit (3);}
    /* sort */
    fclose (fp_r);
    free (buffer);

    FILE *fp_w;
    fp_w = fopen("output","wb");
    fclose (fp_w);
    
    return 0;
}
