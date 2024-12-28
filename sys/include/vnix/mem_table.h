#ifndef _vnix_mem_table_h
#define _vnix_mem_table_h

#define kb(x) x * 1024
#define mb(x) kb(x) * 1024
#define gb(x) mb(x) * 1024

/*
 * =============
 * | 0x0       | memory start
 * | --------- |
 * | 1 mb      | not used
 * | --------- |
 * | 0x100000  | 
 * |           |
 * | 0x100000  | 
 * | --------- |
 * | 12 mb     | kernel code
 * | --------- |
 * | 0xd00000  |
 * |           |
 * | 0xd00000  | MEM_KERNEL_PAGE_START
 * | --------- |
 * | 4 mb      | kernel page directory
 * | --------- |
 * | 0x1100000 | MEM_KERNEL_PAGE_END
 * |           |
 * | 0x1100000 |
 * | --------- |
 * | 16 mb     | gfx memory
 * | --------- |
 * | 0x2100000 |
 * |           |
 * | 0x2100000 | end reserved memory
 * | --------- | MEM_END_RESERVED
 * |           |
 * | 0x2100000 | heap start
 * | --------- | MEM_HEAP_START
 * |     |     |
 * |    \|/    |
 * |           |
 * |    ...    |
 * |           |
 * |    /|\    |
 * |     |     |
 * | --------- | (runtime)
 * | (runtime) | alloc info zone
 * =============
*/

#define MEM_KERNEL_PAGE_START mb(13)
#define MEM_KERNEL_PAGE_END MEM_KERNEL_PAGE_START + mb(4)

#define MEM_GFX_MEMORY_START MEM_KERNEL_PAGE_END
#define MEM_GFX_MEMORY_END MEM_GFX_MEMORY_START + mb(16)

#define MEM_START_RESERVED 0x0
#define MEM_END_RESERVED MEM_GFX_MEMORY_END

#define MEM_HEAP_START MEM_END_RESERVED

#endif