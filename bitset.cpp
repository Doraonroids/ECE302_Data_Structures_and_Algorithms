#include "bitset.hpp"


Bitset::Bitset(){
	N = 8;
	bit_array = new int[N];
	for(int i = 0; i < N; i++){
		*(bit_arry + i) = 0;
	}
	
}


Bitset::Bitset(intmax_t size){
	if(size >= 0){
		N = size;
		bit_array = new int[N];
		for(int i = 0; i < N; i++){
			*(bit_arry + i) = 0;
		}
	}else{
		//error message and exit?
	}
}


Bitset::Bitset(const std::string & value){
	N = value.lenght();
	bit_array = new int[N];
	for(int i = 0; i < N; i++){
			*(bit_arry + i) = value[i];
		}
}
// TODO


  // TODO COMMENT
	Bitset::~Bitset(){
	  
	}

	Bitset::Bitset(const Bitset & ) = delete{
		
	}
	
	Bitset Bitset::& operator=(const Bitset &) = delete{
		
	}

	// TODO COMMENT
	intmax_t Bitset::size() const{
		
	}

	// TODO COMMENT
	bool Bitset::good() const{
		
	}

	// TODO COMMENT
	void Bitset::set(intmax_t index){
		
	}

	// TODO COMMENT
	void Bitset::reset(intmax_t index){
		
	}

	// TODO COMMENT
	void Bitset::toggle(intmax_t index){
		
	}

	// TODO COMMENT
	bool Bitset::test(intmax_t index){
		
	}

	// TODO COMMENT
	std::string asString() const{
		
	}

