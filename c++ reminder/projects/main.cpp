/* RAII: Resource Acquisition Is Initialization
* Allocated memory to be returned once it gets out of the scope
* smart pointer -> pointer in stack (not heap)/(stack unwinding)
* 
* why use smart pointer?
* to prevent following cases
* 1. memory leaks
* 2. double free bug
* 
* e.g. 
* 1. unique_ptr -> alllow only move semantic: this one generated on stack
* 2. shared_ptr -> allow copying the pointers using reference count
* 3. 
*
* REMIND 
* Deepcopy vs. Shallow copy
* 1. Deepcopy -> copy all fields and allocate new memory to point
* 2. Shallow copy -> copy all fields leaving pointers point the original address
*
*/

#include "unique_ptr.h"
#include "shared_ptr.h"

int main()
{
	// unique_ptr_main();
	shared_ptr_main();

	return 0;
}