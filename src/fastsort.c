#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
  MPI_Init(&argc, &argv);
  MPI_Comm comm = MPI_COMM_WORLD;
  int myid, numprocs;
  MPI_Comm_size(comm, &numprocs);
  MPI_Comm_rank(comm, &myid);

  double t1 = MPI_Wtime();
  FILE *fp_r;
  long fsize;
  char *buffer;
  size_t rc;
  fp_r = fopen("input", "rb");
  if (fp_r == NULL) {
    fputs("File error", stderr);
    exit(1);
  }
  fseek(fp_r, 0, SEEK_END);
  fsize = ftell(fp_r);
  rewind(fp_r);
  buffer = (char *) malloc(sizeof(char) * fsize);
  if (buffer == NULL) {
    fputs("Memory error", stderr);
    exit(2);
  }
  rc = fread(buffer, sizeof(char), fsize, fp_r);
  if (rc != fsize) {
    fputs("Reading error", stderr);
    exit(3);
  }
  /* sort */
  fclose(fp_r);
  double t2 = MPI_Wtime();

  FILE *fp_w;
  fp_w = fopen("output", "wb");
  fwrite(buffer, sizeof(char), fsize, fp_w);
  fclose(fp_w);
  double t3 = MPI_Wtime();
  free(buffer);

  double read_time, write_time;
  double read_rate, write_rate;
  read_time = t2 - t1;
  write_time = t3 - t2;
  double file_size = fsize / 1000000.0;
  read_rate = file_size / read_time;
  write_rate = file_size / write_time;
  printf("file_size(MB)\tread_time(s)\t"
         "write_time(s)\tread_rate(MB/s)" "\twrite_rate(MB/s)\n");
  printf("%f\t%f\t%f\t%f\t%f\n", file_size, read_time, write_time,
         read_rate, write_rate);

  return 0;
}
