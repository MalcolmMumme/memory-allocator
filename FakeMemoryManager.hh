#ifndef I_FakeMemoryManager_H
#define I_FakeMemoryManager_H
#include "MemoryManager.hh"
class Easyblock : public Block {
private:
	char * blockstart;
	bool validbit;
	std::size_t blocklength;
public: 
	Easyblock(): validbit(false) {}; // default constructor. 
	void initialize( std::size_t count ) // useful constructor. 
	{
		blockstart = new char[count];
		blocklength = count;
		validbit = true;
	};
	void invalidate() {
		if (valid()) delete[] blockstart;
		blockstart = NULL;
		validbit = false;
		blocklength = 0;
	};
public:
	/*virtual*/ ~Easyblock() {
		invalidate();
	}; // default destructor
	// ask is this Block constructed/allocated
	/*virtual*/ bool valid() { return validbit; }; 
	// get the length of the Block
	std::size_t length() { return blocklength; };
	// get the byte at offset, store into val
	virtual void get_byte(std::size_t offset, char & val) { val = blockstart[offset]; }; 
	// set the byte at offset to val
	virtual void set_byte(std::size_t offset, char & val) { blockstart[offset] = val; }; 
};

// Memory manager that always works
class FakeMemoryManager: public MemoryManager<Easyblock> {
	//typedef MemoryManager<Failblock>::blocktype blocktype;
public:
	FakeMemoryManager() {}; // default constructor
	/*virtual*/ ~FakeMemoryManager() {}; // destructor
	
	// Methods for user requests
	// Request a block of length bytes from MemoryManager
	/*virtual*/ void request( Easyblock & result, std::size_t length ) { result.initialize(length); }; 
	
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
#endif // I_FakeMemoryManager_H