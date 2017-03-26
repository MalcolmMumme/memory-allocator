#ifndef I_SimpleMemoryManager_H
#define I_SimpleMemoryManager_H
#include "MemoryManager.hh"
#include "SimpleBlock.hh"
// Memory manager that always works
class SimpleMemoryManager: public MemoryManager<SimpleBlock> {
private:
	class Node {
	private:
		char * next;
		char * afterend; // points to next location after end of memory block
			// so that afterend-(char *)this = the size 
	public:
		Node();
	};
private:
	char * originalstart;
	std::size_t originallength;
private:
	char * list;
public:
	SimpleMemoryManager( std::size_t length ): originallength(length), originalstart( new char[length] ) { // default constructor
		list = (char *) originalstart;
		
		// TBD set up list of free areas
	};
	/*virtual*/ ~SimpleMemoryManager() {}; // destructor
	
	// Methods for user requests
	// Request a block of length bytes from MemoryManager
	/*virtual*/ void request( SimpleBlock & result, std::size_t length ) { result.initialize(length); }; 
	
	// TBD additional methods
//	// Return the block when no longer needed
//	/*virtual*/ void returnback( Failblock & result ) {};
//	// Methods for provisioning MemoryManager with resources
//	// Loan a gift of memory for use by MemoryManager. May be reclaimed using tag, returns 1 if gift accepted, and 0 if rejected.
//	/*virtual*/ bool donate( Claim_check & tag, Block & gift ) { return false; };
//	// Check if gift is being used. Returns 1 if gift not in use, returns 0 if gift was in use.
//	/*virtual*/ bool check_reclaim( Claim_check & tag, Block & gift ) { return false; };
//	// Take back memory from MemoryManager, using tag. Returns 1 if gift not in use, returns 0 if gift was in use.
//	/*virtual*/ bool reclaim( Claim_check & tag, Block & gift ) { return false; };
};  
#endif // I_SimpleMemoryManager_H