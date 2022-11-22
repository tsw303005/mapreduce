#include <string>
#include <mpi.h>
#include <memory>

#include "jobTracker.h"
#include "taskTracker.h"
#include "utility.h"

#define debug 1;

int main(int argc, char **argv) {
    // mpi
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // cpu
    cpu_set_t cpuset;
    sched_getaffinity(0, sizeof(cpuset), &cpuset);
    int ncpus = CPU_COUNT(&cpuset);

    // parameter
    auto config = std::make_shared<MapReduce::Config>(argv);

    if (rank == size - 1) {
        MapReduce::JobTracker jobTracker(config);
        jobTracker.run();      
    } 

    return 0;
}
