// RUN: %clang_dfsan -m64 %s -o %t && %t

// Tests that labels are propagated through loads and stores.

#include <sanitizer/dfsan_interface.h>
#include <assert.h>

int main(void) {
  int i = 1;
  dfsan_label i_label = dfsan_create_label("i", 0);
  dfsan_set_label(i_label, &i, sizeof(i));

  dfsan_label new_label = dfsan_get_label(i);
  assert(i_label == new_label);

  return 0;
}
