/*
pintos-mkdisk mydisk.dsk --filesys-size=5
pintos --qemu --disk=mydisk.dsk -- -f -q
pintos --qemu --disk=mydisk.dsk -p ../../examples/project -a project -- -q
pintos --qemu --disk=mydisk.dsk -p ../../examples/child_sort -a child_sort -- -q
pintos --qemu --disk=mydisk.dsk -p ../../examples/matmult -a matmult -- -q
pintos -r --qemu --disk=mydisk.dsk -- -q run project
*/

#include <stdio.h>
#include <syscall.h>
 
static thread_func test_function;


int main(void)
{

  int x = thr_create ("TEST", test_function, NULL);

  printf("%d",x);
  return 0;
}

static void test_function (void *aux UNUSED) {
  printf("%s","inside thread");
}
