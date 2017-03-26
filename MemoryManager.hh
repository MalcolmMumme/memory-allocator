#ifndef I_MemoryManager_H
#define I_MemoryManager_H
#include<cstddef>

#include "Block.hh"

// Simple memory manager interface
// template< std::size_t B=0 > // B = maximum number of donated blocks
template< class Blocktype > // Blocktype = the actual (sub)type of Block created by MemoryManager
class MemoryManager {
public:
	typedef Blocktype blocktype;
	typedef std::size_t Claim_check;
public:
	// MemoryManager(); // no default constructor
	virtual ~MemoryManager() {}; // default destructor
	
	// Methods for user requests
	// Request a block of length bytes from MemoryManager
	virtual void request( Blocktype & result, std::size_t length )=0; 

//	// Ignore for now:
//	// TBD additional methods
//	// Return the block when no longer needed
//	virtual void returnback( Blocktype & result )=0;
//	// Methods for provisioning MemoryManager with resources
//	// Loan a gift of memory for use by MemoryManager. May be reclaimed using tag, returns 1 if gift accepted, and 0 if rejected.
//	virtual bool donate( Claim_check & tag, Block & gift )=0;
//	// Check if gift is being used. Returns 1 if gift not in use, returns 0 if gift was in use.
//	virtual bool check_reclaim( Claim_check & tag, Block & gift )=0;
//	// Take back memory from MemoryManager, using tag. Returns 1 if gift not in use, returns 0 if gift was in use.
//	virtual bool reclaim( Claim_check & tag, Block & gift )=0;
};
#endif //I_MemoryManager_H
