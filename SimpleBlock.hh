#ifndef I_SIMPLE_BLOCK_H
#define I_SIMPLE_BLOCK_H
#include "Block.hh"

class SimpleBlock: public Block {
private:
	char * blockstart;
	bool validbit;
	std::size_t blocklength;
public:
	SimpleBlock(): validbit(false) {}; // default constructor. 
	void initialize( char * blockstartp, std::size_t blocklengthp ) // useful constructor. 
	{
		blockstart = blockstartp;
		blocklength = blocklengthp;
		validbit = true;
	};
	void invalidate() {
		// if (valid()) delete[] blockstart;
		blockstart = NULL;
		validbit = false;
		blocklength = 0;
	};
	// get the address of the memory block
	virtual char * address() { return blockstart; };
	// get the length of the block
	virtual std::size_t getlength() { return blocklength; };
public:
	/*virtual*/ ~SimpleBlock() {
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
#endif //I_SIMPLE_BLOCK_H
