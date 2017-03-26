#include "FailMemoryManager.hh"
// sample driver

#include<iostream>

int main() {
	FailMemoryManager theMemoryManager;

	typedef typeof(theMemoryManager) MemoryManagerType;

	typedef MemoryManagerType::blocktype TheBlockType;
	
	TheBlockType aBlock; 
// 	FailMemoryManager::blocktype aBlock; 

	theMemoryManager.request( aBlock, (std::size_t) 100 ); 

	bool allocated = aBlock.valid();

	if (allocated) { 
		std::cout << std::endl << "Nooo! The allocator should fail!" << std::endl; 
	} else {
		std::cout << std::endl << "Yaay! The allocator failed!" << std::endl; 
	};
	
	return 0;
	
}; 

