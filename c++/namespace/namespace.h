#include "header1.h"
#include "header2.h"

// NAMELESS NAMESPACE 
// This works as static keyword
// and only works in this file
namespace {
	
	int OnlyInThisFile() { return 1; }
	int only_in_this_file = 2;
}


namespace header1 {
	
	int func() {
		
		foo(); // Automatically call foo from namespace header1
		header2::foo();
		return 0;
	}
	
} // namespace header1