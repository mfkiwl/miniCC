// RUN: AArch64

// FUNC-DECL: int test()
// COMPILE-FAIL

int test() {
  int a;
  int a;
  return a;
}

