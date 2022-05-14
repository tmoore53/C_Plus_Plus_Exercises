/*
 * This is a C implementation of malloc( ) and free( ), based on the buddy
 * memory allocation algorithm. 
 */
#include <stdio.h> // printf

/*
 * The following global variables are used to simulate memory allocation
 * Cortex-M's SRAM space.
 */
// Heap
char array[0x8000];            // simulate SRAM: 0x2000.0000 - 0x2000.7FFF
int heap_top   = 0x20001000;   // the top of heap space
int heap_bot   = 0x20004FE0;   // the address of the last 32B in heap
int max_size   = 0x00004000;   // maximum allocation: 16KB = 2^14
int min_size   = 0x00000020;   // minimum allocation: 32B = 2^5

// Memory Control Block: 2^10B = 1KB space
int mcb_top    = 0x20006800;   // the top of MCB
int mcb_bot    = 0x20006BFE;   // the address of the last MCB entry
int mcb_ent_sz = 0x00000002;   // 2B per MCB entry
int mcb_total  = 512;          // # MCB entries: 2^9 = 512 entries

/*
 * Convert a Cortex SRAM address to the corresponding array direction.
 * @param  sram_addr address of Cortex-M's SRAM space starting at 0x20000000.
 * @return array direction.
 */
int m2a( int sram_addr ) {
  int direction = sram_addr - 0x20000000;
  // printf( "m2a: sram_addr = %x array_direction = %d\n", sram_addr, direction );
  return direction;
}

/*
 * Reverse an array direction back to the corresponding Cortex SRAM address.
 * @param  array direction.
 * @return the corresponding Cortex-M's SRAM address in an integer.
 */ 
int a2m( int array_direction ) {
  return array_direction + 0x20000000;
}

/*
 * In case if you want to print out, all array elements that correspond
 * to MCB: 0x2006800 - 0x20006C00.
 */
void printArray( ) {
  printf( "memroy ............................\n" );
  for ( int i = 0; i < 0x8000; i+=4 )
    if ( a2m( i ) >= 0x20006800 ) 
	 printf( "%x = %x(%d)\n",
		 a2m( i ), *(int *)&array[i], *(int *)&array[i] ); 
}

/*
 * _ralloc is _kalloc's helper function that is recursively called to
 * allocate a requested space, using the buddy memory allocaiton algorithm.
 * Implement it by yourself in step 1.
 *
 * @param  size  the size of a requested memory space
 * @param  left  the address of the left boundary of MCB entries to examine
 * @param  right the address of the right boundary of MCB entries to examine
 * @return the address of Cortex-M's SRAM space. While the computation is
 *         made in integers, cast it to (void *). The gcc compiler gives
 *         a warning sign:
                cast to 'void *' from smaller integer type 'int'
 *         Simply ignore it.
 *  mid = begin + (end - begin) / 2 
 */

     // for(int i = 0 ; i < currentSize ; i+=4){
    //   if(i > size){
    //         mcb[(left+i)] = size+1;
    //   }
    //   else{
    //       mcb[(left+i)] = size;
    //   }

    // }
void *_ralloc( int size, int left, int right ) {
  int midpoint = left + (right - left)/2 + 1;
  int currentSize = (right - left + 2) * 16;  
  int nextSize = currentSize/2;
  //printf( "_ralloc: size=%x, left=%x, right=%x, nextSize%x, currentSize=%x\n", size, left, right, nextSize, currentSize );
  // printf(array[left]);

  // If the size is bigger than the space initially available exit
  if(size > max_size){
    return NULL;
  }
  //printf("Array at %x, == %x\n", left, array[m2a(left)] );
  void * address;
  if(nextSize >= size){
    // Go left
    //printf("Going left\n");
    address = _ralloc(size,left, right - (right - left)/2 -1);
    if(address == NULL){
    // Go right
    //printf("Going right\n");
    address = _ralloc(size,(right - left)/2 + left + 1, right);
    }
    return address;
  } else{
    //printf("HITT Outside!!!!\nA: %x && B: %d\n", *(int *)&array[m2a(left)], *(int *)&array[m2a(midpoint)]);
      if(*(int *)&array[m2a(left)] % 2 == 0 && *(int *)&array[m2a(midpoint)] == 0){
        //printf("HITT Inside!!!!\n");
        address = (void *)&array[m2a(left)];
        *(int *)&array[m2a(left)] = size+1;
        // Assign the midpoint so that others don't use this space
        *(int *)&array[m2a(midpoint)] = size +1;
        //  *(int *)&array[m2a(right)] = size ;
        //printf("%x\n", (left - 0x20006800)*16 + heap_top);
        return (void *)((left - 0x6800) * 16) + heap_top;
    }else{
      return NULL;
    }
  }
  return NULL;
}

/*
 * _rfree is _kfree's helper function that is recursively called to
 * deallocate a space, using the buddy memory allocaiton algorithm.
 * Implement it by yourself in step 1.
 *
 * @param  mcb_addr that corresponds to a SRAM space to deallocate
 * @return the same as the mcb_addr argument in success, otherwise 0.
 */
int _rfree( int mcb_addr ) {
   printf( "_rfree: mcb[%x] = %x\n", mcb_addr, *(short *)&array[ m2a( mcb_addr ) ] );  
  // Contents at the address
  int mcb_contents = *(short *)&array[m2a(mcb_addr)];
  // Determine the current memory control block space
  int currentVal = 0;
  if (mcb_contents % 2 == 0) {
    currentVal = (*(short *)&array[m2a(mcb_addr)]) / 16;
  } else { 
    currentVal = (*(short *)&array[m2a(mcb_addr)] - 1) / 16;
  }
  // Lower value to signify it is being removed
  if (mcb_contents % 2 != 0) {
    mcb_contents = mcb_contents - 1;
    *(short *)&array[m2a(mcb_addr)] = mcb_contents;
  }
  //printf("is this mcb_contents %x,currentVal %x\n", mcb_contents, currentVal  );
  // Determine if the buddy is on the right or left
  int direction = (mcb_addr - mcb_top) / (mcb_contents / 16);
  // Buddy Address
  int buddy = 0;
  // Buddy contents at address
  int buddy_contents = 0;
  //Buddy is on the right
  if (direction % 2 == 0) {
    buddy = mcb_addr + currentVal;
    buddy_contents = *(short *)&array[m2a(buddy)];
      //  printf("is this address %x,contents %x\n", buddy, buddy_contents  );
    // If the buddy and contents match and the buddy is already empty
    if (buddy_contents == mcb_contents && buddy_contents % 2 == 0) {
      // Clear the buddy
      *(short *)&array[m2a(buddy)] = 0;
      //printf("is this mcb_contents %x,buddy_contents %x\n", mcb_contents, buddy_contents);
      // Merge the buddy and current with the sum of both
      *(short *)&array[m2a(mcb_addr)] = mcb_contents + buddy_contents;
      // Try to free the memory above
      return _rfree(mcb_addr);
    }
  } else { 
    // Buddy address is on the left
    buddy = mcb_addr - currentVal;
    buddy_contents = *(short *)&array[m2a(buddy)];
    // If the buddy and contents match and the buddy is already empty
    if (buddy_contents == mcb_contents && buddy_contents % 2 == 0) {
      // Set the buddy on the right to 0
      *(short *)&array[m2a(mcb_addr)] = 0;
      // Merge them and try to free any memory than needs to be freed 
      *(short *)&array[m2a(buddy)] = buddy_contents + mcb_contents;
      return _rfree(buddy);
    }
  }

  return mcb_addr;
}
/**
  int contents = *(short *)&array[m2a(mcb_addr)];
  printf( "_rfree: mcb[%x] = %x\n", mcb_addr, *(short *)&array[ m2a( mcb_addr )] );
  if(mcb_addr > mcb_bot || mcb_addr < mcb_top || contents == 0){
    return 0;
  }
  // Get the size contained in the memory control block
  int buddy_Offset = (contents- 1)/16;
  // Check up
  printf("Offset value %x\n", buddy_Offset);
  

  int direction = (mcb_addr - mcb_top) / (contents / 16);
  int buddy_Address = 0;
  int buddy_value = 0;
  // look right else look left
  if(direction % 2 == 0){
    buddy_Address = mcb_addr + buddy_Offset;
    buddy_value = *(short *)&array[ m2a( buddy_Address )];
     printf("is this equal? %x\n", buddy_value );
    if(buddy_value == contents){
      printf("is this midpoint? %x\n", buddy_Address + buddy_Offset/2 );
      *(short *)&array[ m2a( buddy_Address )] = 0;
      *(short *)&array[ m2a(mcb_addr)] = buddy_value + contents;
      //printf("is this good? %x\n", *(short *)&array[ m2a(mcb_addr)] );
      _rfree( buddy_Address + buddy_Offset/2);
    }
    *(short *)&array[ m2a( buddy_Address )] = 0;
    
    printf("Even %x\n", buddy_Address);
  }else{
    buddy_Address = mcb_addr - buddy_Offset;
    if(*(short *)&array[ m2a( buddy_Address )] == contents - 1 ){
      printf("is this midpoint? %x\n", buddy_Address + buddy_Offset/2 );
      *(short *)&array[ m2a( buddy_Address )] = 0;
      _rfree( buddy_Address + buddy_Offset/2);
    }
    printf("Odd %x\n", buddy_Address);


  }

   printf("direction value %x, contents %x\n", direction, contents);
  // Go to the location of the mem by recursion
  // _rfree(mcb_addr-1 + buddy_Offset);
  // _rfree(mcb_addr-1 - buddy_Offset);

  //int nextAddress = ( mcb_addr - mcb_top ) / contents;
  // printf("nextAddress value %x\n", nextAddress);


*/

/*
 * Initializes MCB entries. In step 2's assembly coding, this routine must
 * be called from Reset_Handler in startup_TM4C129.s before you invoke
 * driver.c's main( ).
 */
void _kinit( ) {
  // Zeroing the heap space: no need to implement in step 2's assembly code.
  for ( int i = 0x20001000; i < 0x20005000; i++ )
    array[ m2a( i ) ] = 0;

  // Initializing MCB: you need to implement in step 2's assembly code.
  *(short *)&array[ m2a( mcb_top ) ] = max_size;
    
  for ( int i = 0x20006804; i < 0x20006C00; i += 2 ) {
    array[ m2a( i ) ] = 0;
    array[ m2a( i + 1) ] = 0;
  }
}

/*
 * Step 2 should call _kalloc from SVC_Handler.
 *
 * @param  the size of a requested memory space
 * @return a pointer to the allocated space
 */
void *_kalloc( int size ) {
  // printf( "_kalloc called\n" );
  return _ralloc( size, mcb_top, mcb_bot );
}

/*
 * Step 2 should call _kfree from SVC_Handler.
 *
 * @param  a pointer to the memory space to be deallocated.
 * @return the address of this deallocated space.
 */
void *_kfree( void *ptr ) {
  int addr = (int )ptr;

  // validate the address
  // printf( "\n_kfree( %x )\n", ptr );
  if ( addr < heap_top || addr > heap_bot )
    return NULL;

  // compute the mcb address corresponding to the addr to be deleted
  int mcb_addr =  mcb_top + ( addr - heap_top ) / 16;
  
  if ( _rfree( mcb_addr ) == 0 )
    return NULL;
  else
    return ptr;
}

/*
 * _malloc should be implemented in stdlib.s in step 2.
 * _kalloc must be invoked through SVC in step 2.
 *
 * @param  the size of a requested memory space
 * @return a pointer to the allocated space
 */
void *_malloc( int size ) {
  static int init = 0;
  if ( init == 0 ) {
    init = 1;
    _kinit( ); // In step 2, you will call _kinit from Reset_Handler 
  }
  return _kalloc( size );
}

/*
 * _free should be implemented in stdlib.s in step 2.
 * _kfree must be invoked through SVC in step 2.
 *
 * @param  a pointer to the memory space to be deallocated.
 * @return the address of this deallocated space.
 */
void *_free( void *ptr ) {
  return _kfree( ptr );
}
