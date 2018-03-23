#!/bin/bash
#------------------------------------------------------------------------------
#  SBATCH CONFIG
#-------------------------------------------------------------------------------
## resources
#SBATCH --partition Lewis
#SBATCH -N 1
#SBATCH -n 5

#SBATCH --exclusive  # using MPI with 90+% of the cores you should go exclusive

#SBATCH --time 0-01:00  # days-hours:minutes
#SBATCH --qos=normal


## labels and outputs
#SBATCH --job-name=MICTEST
#SBATCH --output=results-Micturition-%j.out  # %j is the unique jobID
## notifications
##SBATCH --mail-user=latimerb@missouri.edu  # email address for notifications
##SBATCH --mail-type=END,FAIL  # which type of notifications to send
#-------------------------------------------------------------------------------

echo "Starting Micturition Model at $(date)"

## Commands here run only on the first core of the first node
# Load needed HOC modules
#module load matlab/matlab-R2016a
module load intel/intel-2016-update2
module load nrn/nrn-mpi-7.4
module load openmpi/openmpi-2.0.0
module list

## Run matlab non-interactively
#echo "Pre-Processing Matlab Scripts starting at $(date)"
#srun -N 1 -n 1 -c 1 --mem 4G matlab -nodesktop -nosplash -nodisplay -r "run('../Scripts_MATLAB/Main_ModelGen.m');exit"

# MPI flag for explicit safety
export PSM_RANKS_PER_CONTEXT=2

srun -N 1 -n 1 nrnivmodl
## Commands prefixed with mpirun or srun will run on every core
echo "Main Micturition file starting at $(date)"
mpirun nrniv -mpi main_model1.hoc

## Run analysis code and print to results file
#echo "Post-Processing Matlab Scripts starting at $(date)"
#srun -N 1 --mem 4G matlab --pty "run('../Scripts_MATLAB/Spike_Raster.m')"

echo "Program complete... $(date)"

#module unload matlab/matlab-R2016a
#module unload intel/intel-2016-update2
#module unload nrn/nrn-mpi-7.4
#module unload openmpi/openmpi-2.0.0
