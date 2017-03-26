#include "FakeMemoryManager.hh"
#include "testBlock.hh"
// sample driver

#include<iostream>

int main() {
	FakeMemoryManager theMemoryManager;

	typedef typeof(theMemoryManager) MemoryManagerType;

	typedef MemoryManagerType::blocktype TheBlockType;
	
	TheBlockType aBlock; 
// 	FailMemoryManager::blocktype aBlock; 

	theMemoryManager.request( aBlock, (std::size_t) 100 ); 

	bool allocated = aBlock.valid();

	if (allocated) { 
		std::cout << std::endl << "Yaay! The allocator worked!" << std::endl; 
	} else {
		std::cout << std::endl << "Nooo! The allocator failed!" << std::endl; 
	};
	
	bool worked = testBlock( &aBlock );
	std::cerr << std::endl << "The length is now " << (aBlock.length()) << ". " << std::endl;
	{if (!worked) {
		std::cerr << std::endl << "The block did not operate as intended. " << std::endl;
	};};
	
	return 0;
	
}; 

