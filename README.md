<p align="center">
  <img src="https://github.com/user-attachments/assets/338d4621-d5dc-4136-81c5-252edcbcf5e0" alt="SEA:ME Portugal logo"/>
</p>

<p align="center">
Main repo of our team with the objective of building a functioning intelligent mobility system and its documentation.
</p>

# Build and Run the exercices

To build this project using CMake, follow these steps:

1. **Configure the Build**: In the project root directory, run the following command to configure the build system and specify the output directory:
   ```bash
   cmake -B build
   ```
   This creates a `build/` directory with the necessary files to build the project.

2. **Compile the Project**: Next, run:
   ```bash
   cmake --build build
   ```
   This compiles the code and generates the executable files in the `build/` directory.

3. **Run the Program**: To execute the main program (assuming it produces an executable named `my_car`), run:
   ```bash
   ./build/my_car
   ```

4. **Run Tests**: If there is a test folder, then run:
   ```bash
   ./build/test/my_car_tests
   ```

