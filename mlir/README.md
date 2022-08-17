# MLIR
Learning & experimenting with LLVM/MLIR

## TorchMLIR
Requirements I am using
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

"Order"
1. Running `python3 torch_matmul.py` yields `raw_matmul.mlir`, which gets compiled down to `torch_backend_matmul.mlir` and `linalg_tensor_backend_matmul.mlir`.
2. Applying _part of_ [the pass chain](https://github.com/llvm/torch-mlir/blob/main/python/torch_mlir_e2e_test/linalg_on_tensors_backends/refbackend.py#L115-L153) yields `lowered_linalg.mlir`.
