#ifdef __cplusplus
extern "C"{
#endif
#include "mpi.h"

#define MAXEXTRA_DATATYPE 16

struct _mpi_double_int {
  double value;
  int proc;
};
typedef struct _mpi_double_int double_int;

static int _mpi_is_initialized=0;

int nextra_datatype;
MPI_Datatype *ptr_datatype[MAXEXTRA_DATATYPE];
int index_datatype[MAXEXTRA_DATATYPE];
int size_datatype[MAXEXTRA_DATATYPE];

int MPI_Init(int *argc, char ***argv)
{
  if (_mpi_is_initialized > 0)
    return 1;

  if (_mpi_is_initialized < 0) 
    return 1;
  _mpi_is_initialized = 1;
  return 0;
}

int MPI_Comm_rank(MPI_Comm comm, int *me)
{
  *me = 0;
  return 0;
}

int MPI_Barrier(MPI_Comm comm) 
{
  return 0;
}


int MPI_Comm_size(MPI_Comm comm, int *nprocs)
{
  *nprocs = 1;
  return 0;
}

int MPI_Finalize()
{
  if (_mpi_is_initialized == 0) 
    return 1;
  if (_mpi_is_initialized < 0)
    return 1;
  _mpi_is_initialized = -1;
  return 0;
}

int MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  int n = count * stubtypesize(datatype);

  // if (sendbuf == '\0' || recvbuf == '\0') return 0;
  // memcpy(recvbuf,sendbuf,n);
  unsigned char *d = (unsigned char *)recvbuf;
  const unsigned char *s = (const unsigned char *)sendbuf;

  for (int i = 0; i < n; i++)
    d[i] = s[i];

  return 0;
}

static int stubtypesize(MPI_Datatype datatype)
{
  if (datatype == MPI_INT)             return sizeof(int);
  else if (datatype == MPI_FLOAT)      return sizeof(float);
  else if (datatype == MPI_DOUBLE)     return sizeof(double);
  else if (datatype == MPI_CHAR)       return sizeof(char);
  else if (datatype == MPI_BYTE)       return sizeof(char);
  else if (datatype == MPI_LONG)       return sizeof(long);
  else if (datatype == MPI_LONG_LONG)  return sizeof(unsigned long long int);
  else if (datatype == MPI_DOUBLE_INT) return sizeof(double_int);
  else {
    int i;
    for (i = 0; i < nextra_datatype; i++)
      if (datatype == index_datatype[i]) return size_datatype[i];
  }
  return 0;
}

int MPI_Cart_create(MPI_Comm comm_old, int ndims, int *dims, int *periods,
                    int reorder, MPI_Comm *comm_cart)
{
  *comm_cart = comm_old;
  return 0;
}

int MPI_Cart_get(MPI_Comm comm, int maxdims, int *dims, int *periods,
                 int *coords)
{
  dims[0] = dims[1] = dims[2] = 1;
  periods[0] = periods[1] = periods[2] = 1;
  coords[0] = coords[1] = coords[2] = 0;
  return 0;
}

int MPI_Cart_shift(MPI_Comm comm, int direction, int displ,
                   int *source, int *dest)
{
  *source = *dest = 0;
  return 0;
}

int MPI_Comm_free(MPI_Comm *comm) 
{
  return 0;
}

int MPI_Sendrecv(void *sbuf, int scount, MPI_Datatype sdatatype,
                 int dest, int stag, void *rbuf, int rcount,
                 MPI_Datatype rdatatype, int source, int rtag,
                 MPI_Comm comm, MPI_Status *status)
{
  return 0;
}

#ifdef __cplusplus
}
#endif
