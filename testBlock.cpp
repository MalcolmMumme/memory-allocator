#include "testBlock.hh"
#include<iostream>
// returns true if aBlock seems to work properly, false if otherwise
// prints reason to std::cerr if false
bool testBlock( Block * aBlockp ) {
	bool result = true;
	Block & aBlock = * aBlockp;
	if (aBlock.valid()) {
		std::size_t n = aBlock.length();
		// first fill low to high with *3 +1
		for ( std::size_t i = 0; i<n; ++i ) {
			char buffer = i*3 + 1;
			aBlock.set_byte(i, buffer);
			char readbuffer = 0; 
			aBlock.get_byte(i, readbuffer);
			{if (buffer != readbuffer) {
				result = false;
				std::cerr << std::endl << "testBlock: Block at " << (aBlockp) << " spontaneously changed [" << i << "] from " << ((int)buffer) << " to " << ((int)readbuffer) << ". " << std::endl;
			};};
		};
		// fill low to high with *5 +2
		for ( std::size_t i = 0; i<n; ++i ) {
			char buffer = i*5 + 2;
			aBlock.set_byte(i, buffer);
			char readbuffer = 0; 
			aBlock.get_byte(i, readbuffer);
			{if (buffer != readbuffer) {
				result = false;
				std::cerr << std::endl << "testBlock: Block at " << (aBlockp) << " spontaneously changed [" << i << "] from " << ((int)buffer) << " to " << ((int)readbuffer) << ". " << std::endl;
			};};
		};
		// check contents
		for ( std::size_t i = 0; i<n; ++i ) {
			char buffer = i*5 + 2;
			char readbuffer = 0; 
			aBlock.get_byte(i, readbuffer);
			{if (buffer != readbuffer) {
				result = false;
				std::cerr << std::endl << "testBlock: Block at " << (aBlockp) << " spontaneously changed [" << i << "] from " << ((int)buffer) << " to " << ((int)readbuffer) << ". " << std::endl;
			};};
		};
		// fill high to low with *7 +3
		for ( std::size_t i = n-1; i<n; --i ) {
			char buffer = i*7 + 3;
			aBlock.set_byte(i, buffer);
			char readbuffer = 0; 
			aBlock.get_byte(i, readbuffer);
			{if (buffer != readbuffer) {
				result = false;
				std::cerr << std::endl << "testBlock: Block at " << (aBlockp) << " spontaneously changed [" << i << "] from " << ((int)buffer) << " to " << ((int)readbuffer) << ". " << std::endl;
			};};
		};
		// check contents
		for ( std::size_t i = n-1; i<n; --i ) {
			char buffer = i*7 + 3;
			char readbuffer = 0; 
			aBlock.get_byte(i, readbuffer);
			{if (buffer != readbuffer) {
				result = false;
				std::cerr << std::endl << "testBlock: Block at " << (aBlockp) << " spontaneously changed [" << i << "] from " << ((int)buffer) << " to " << ((int)readbuffer) << ". " << std::endl;
			};};
		};
		
		std::size_t n2 = aBlock.length();
		{if (!(n = n2)) {
			std::cerr << std::endl << "testBlock: Block at " << (aBlockp) << " spontaneously changed length from " << n << " to " << n2 << ". " << std::endl; 
			result = false;
		};};
		{if (!(aBlock.valid())) {
			std::cerr << std::endl << "testBlock: Block at " << (aBlockp) << " became invalid spontaneously. " << std::endl; 
			result = false;
		};};
	} else { // the block is not allocated
		{if (aBlock.valid()) {
			std::cerr << std::endl << "testBlock: Block at " << (aBlockp) << " became valid spontaneously. " << std::endl; 
			result = false;
		};};
	};
	return result;
};
