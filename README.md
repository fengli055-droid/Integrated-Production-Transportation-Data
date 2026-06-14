Data and Solutions for "Incorporating Inventory Costs in Production and Transportation Integration: New Exact and Approximation Algorithms"

This repository contains the instance data, data generation details, and solution descriptions for the paper "Incorporating Inventory Costs in Production and Transportation Integration: New Exact and Approximation Algorithms".

Repository Structure
- instances/: Contains all test instances used in the computational experiments.
- solutions/: Contains the detailed solution outputs, including objective values, lower bounds, running times, and algorithm-specific statistics.
- data_generation/: Contains the scripts and descriptions detailing how the random instances were generated.

Data Format
Instance Files (instances/)
The instance files are stored in the instances directory. For more details on the file naming convention and the line-by-line structure of each txt file, please refer to instance_description.pdf.

Solution Files (solutions/)
The solution files are stored in the solutions directory. For more details on the columns in each result file, please refer to solution_description.pdf.

Data Generation
The data generation files are stored in the data_generation directory. The corresponding C++ data-generation code is provided in data_generation/Generate-data.cpp. For more details on the generation procedure, please refer to data_generation.pdf.

Reproducibility Notes
- Exact-algorithm instances and approximation-algorithm instances are stored in separate subdirectories under instances/.
- The solution files use the same instance-index convention as the released instance files.
- The accompanying description documents are intended to make the released data self-contained and easier to reproduce.
