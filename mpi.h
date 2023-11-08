/* -----------------------------------------------------------------------
   LAMMPS 2003 (July 31) - Molecular Dynamics Simulator
   Sandia National Laboratories, www.cs.sandia.gov/~sjplimp/lammps.html
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------ */

#ifndef MPI_STUBS
#define MPI_STUBS

/* use C bindings for MPI interface */

#ifdef __cplusplus
extern "C" {
#endif

/* Dummy defs for MPI stubs */

#define MPI_COMM_WORLD 0

#define MPI_SUCCESS   0
#define MPI_ERR_ARG  -1

#define MPI_INT 1
#define MPI_FLOAT 2
#define MPI_DOUBLE 3
#define MPI_CHAR 4
#define MPI_BYTE 5
#define MPI_LONG 6
#define MPI_LONG_LONG 7
#define MPI_DOUBLE_INT 8

#define MPI_SUM 1
#define MPI_MAX 2
#define MPI_MIN 3
#define MPI_MAXLOC 4
#define MPI_MINLOC 5
#define MPI_LOR 6

#define MPI_UNDEFINED -1
#define MPI_COMM_NULL -1
#define MPI_GROUP_EMPTY -1

#define MPI_ANY_SOURCE -1
#define MPI_STATUS_IGNORE NULL

#define MPI_Comm int
#define MPI_Request int
#define MPI_Datatype int
#define MPI_Op int
#define MPI_Fint int
#define MPI_Group int
#define MPI_Offset long

#define MPI_IN_PLACE NULL

#define MPI_MAX_PROCESSOR_NAME 128

typedef void MPI_User_function(void *invec, void *inoutvec, 
                               int *len, MPI_Datatype *datatype);

/* MPI data structs */

struct _MPI_Status {
  int MPI_SOURCE;
};
typedef struct _MPI_Status MPI_Status;

/* Function prototypes for MPI stubs */

int MPI_Init(int *argc, char ***argv);

int MPI_Comm_rank(MPI_Comm comm, int *me);
int MPI_Comm_size(MPI_Comm comm, int *nprocs);
int MPI_Finalize();

int MPI_Sendrecv(void *sbuf, int scount, MPI_Datatype sdatatype,
                  int dest, int stag, void *rbuf, int rcount,
                  MPI_Datatype rdatatype, int source, int rtag,
                  MPI_Comm comm, MPI_Status *status);

int MPI_Comm_free(MPI_Comm *comm);

int MPI_Cart_create(MPI_Comm comm_old, int ndims, int *dims, int *periods,
                    int reorder, MPI_Comm *comm_cart);
int MPI_Cart_get(MPI_Comm comm, int maxdims, int *dims, int *periods,
                 int *coords);
int MPI_Cart_shift(MPI_Comm comm, int direction, int displ,
                   int *source, int *dest);

int MPI_Barrier(MPI_Comm comm);
int MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
/* ---------------------------------------------------------------------- */

static int stubtypesize(MPI_Datatype datatype);

#ifdef __cplusplus
}
#endif

#endif
