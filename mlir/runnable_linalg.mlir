#map = affine_map<(d0, d1) -> (d0, d1)>
module attributes {torch.debug_module_name = "Matmul"} {
  memref.global "private" @global_seed : memref<i64> = dense<0>
  func.func @forward(%arg0: memref<2x2xf32>) -> memref<2x2xf32> {
    %cst = arith.constant 1.000000e+00 : f32
    %cst_0 = arith.constant 0.000000e+00 : f32
    %0 = memref.alloc() {alignment = 128 : i64} : memref<2x2xf32>
    linalg.fill ins(%cst : f32) outs(%0 : memref<2x2xf32>)
    %1 = memref.alloc() {alignment = 128 : i64} : memref<2x2xf32>
    linalg.fill ins(%cst_0 : f32) outs(%1 : memref<2x2xf32>)
    %2 = memref.alloc() {alignment = 128 : i64} : memref<2x2xf32>
    linalg.generic {indexing_maps = [#map, #map], iterator_types = ["parallel", "parallel"]} ins(%1 : memref<2x2xf32>) outs(%2 : memref<2x2xf32>) {
    ^bb0(%arg1: f32, %arg2: f32):
      linalg.yield %arg1 : f32
    }
    linalg.matmul ins(%arg0, %0 : memref<2x2xf32>, memref<2x2xf32>) outs(%2 : memref<2x2xf32>)
    return %2 : memref<2x2xf32>
  }
  func.func @main() {
    return
  }
}