// RUN: AArch64

// FUNC-DECL: int test(int)
// COMPILE-FAIL

const int a;

int test(int b) {
  a = b;
  return a;
}
