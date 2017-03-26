#ifndef I_FailMemoryManager_H
#define I_FailMemoryManager_H
#include "MemoryManager.hh"
class Failblock : public Block {
public: 
	Failblock() {}; // default constructor. 
	/*virtual*/ ~Failblock() {}; // default destructor
	// ask is this Block constructed/allocated
	/*virtual*/ bool valid() { return false; }; 
	// get the length of the Block
	std::size_t length() { throw; };
	// get the byte at offset, store into val
	virtual void get_byte(std::size_t offset, char & val) { throw; }; 
	// set the byte at offset to val
	virtual void set_byte(std::size_t offset, char & val) { throw; }; 
};

// Memory manager that always fails
class FailMemoryManager: public MemoryManager<Failblock> {
	//typedef MemoryManager<Failblock>::blocktype blocktype;
public:
	FailMemoryManager() {}; // default constructor
	/*virtual*/ ~FailMemoryManager() {}; // destructor
	
	// Methods for user requests
	// Request a block of length bytes from MemoryManager
	/*virtual*/ void request( Failblock & result, std::size_t length ) {}; 
	
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
#endif // I_FailMemoryManager_H