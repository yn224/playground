# MLIR
Learning & experimenting with LLVM/MLIR/TorchMLIR

## LLVM Version
Currently, LLVM15 is being used for implementing and testing.

## GPU execution
Script `run.sh` - adopted from [here](https://github.com/zzzDavid/mlir-playground/blob/main/gpu-backend/compile.sh)

More detailed instruction can be found in respective directories
* Simple examples: `matmul`
* Machine Learning examples: `ml`

## TorchMLIR
Tools & Versions:
* cmake 3.24.0
* python3.9
* gcc 9.4.0
* g++ 9.4.0

Build instruction with python binding (adopted from [here](https://github.com/llvm/torch-mlir/blob/main/build_tools/build_standalone.sh)):
```
cd $TORCH_MLIR_SDIR

mkdir build && cd build

cmake -GNinja -DCMAKE_BUILD_TYPE=Release \
              -DCMAKE_C_COMPILER=`which gcc` \
              -DCMAKE_CXX_COMPILER=`which g++` \
              -DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \ 
              -DPython3_FIND_VIRTUALENV=ONLY \ 
              -DLLVM_ENABLE_PROJECTS=mlir \
              -DTORCH_MLIR_ENABLE_MHLO=OFF \
              -DLLVM_EXTERNAL_PROJECTS="torch-mlir;torch-mlir-dialects" \
              -DLLVM_EXTERNAL_TORCH_MLIR_SOURCE_DIR=$TORCH_MLIR_SDIR \
              -DLLVM_EXTERNAL_TORCH_MLIR_DIALECTS_SOURCE_DIR=$TORCH_MLIR_SDIR/externals/llvm-external-projects/torch-mlir-dialects \
              -DMLIR_ENABLE_BINDINGS_PYTHON=ON \
              -DLLVM_TARGETS_TO_BUILD=host $LLVM_SDIR/llvm

ninja tools/torch-mlir/all check-torch-mlir-all
```

## Compile and Run
* Order (CPU):
    1. Compile using `./run.sh <file> <number>`, where `<number> = 0` if `<file>` is matmul and `<number> = 1` if `<file>` is ML.
    2. Run `./run.sh <file> 2` for CPU-runner.
* Order (GPU):
    1. Same first step as CPU.
    2. Edit out `"exout.llvm"` contained in the line `.file 1 "$PWD" "exout.llvm"` of `exout.s` that gets generated.
    3. Run `./run.sh <file> 3`
* Expected results
  * Matmul
    ```
    Unranked Memref base@ = 0x564c2792cb00 rank = 2 offset = 0 sizes = [2, 2] strides = [2, 1] data =
    [[5,   5],
    [9,   9]]
    ```
  * Resnet18
    ```
    Unranked Memref base@ = 0x3c5ee20 rank = 1 offset = 0 sizes = [3] strides = [1] data =
    [70.6567,  4.98832,  4.47745]
    Unranked Memref base@ = 0x3c5ee40 rank = 1 offset = 0 sizes = [1] strides = [1] data =
    [100]
    ```
    The first output describes the prediction values and the second output describes the execution time in nanoseconds.

    <mark>TODO:</mark> The execution time does not seem to be correct. Need to be fixed.

## Debugging
General errors encountered are being logged in `error-tracking.md`.